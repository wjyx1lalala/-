//
//  main.c
//  ctest
//
//  Created by 魏家园潇 on 2017/3/21.
//  Copyright © 2017年 魏家园潇. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define N 8
typedef int bool;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//冒泡算法的思想是:最重要的思想是两两比较，将两者较大的升上去 复杂度n*(n-1)/2
//每次循环,所有元素都来跟第一个元素比较,如果比较小,则放置在替换放置在数组最前面,
//每一轮循环结束,从下一个坐标开始做对比  复杂度 n*(n-1)/2
//第一个元素依次去跟后面所有的元素进行比较大小,如果满足一定条件,交换两个元素的值,
//以此来实现每个元素向顶层上升
void mybubble_sortbybringToFont(int a[],int n)//n为数组a的元素个数
{
    int count = 0;
    for(int i = 0; i < n - 1; i ++){
        //j = i + 1是因为,j要从i的下一位开始做比较
        //j < n -1 是因为,每一轮过去以后,
        for (int j = i + 1; j < n ; j ++) {
            count ++ ;
            //将数据最小的放置在数组前方
            if (a[i] > a[j]) {
                swap(&a[i],&a[j]);
            }
        }
    }
    printf("代码计算了 %d 次\n",count);
}

//通过两两对比,将最大的放置在数组的最后面,复杂度n*(n-1)/2
void mybubble_sortbybringToEnd(int a[],int n)//n为数组a的元素个数
{
    int count = 0;
    for(int i = 0; i < n - 1; i ++){
        
        for (int j = 0; j < n - i - 1; j ++) {
            count ++ ;
            //将数据最大的放置在数组最后面
            if (a[j] > a[j+1]) {
                swap(&a[j],&a[j+1]);
            }
        }
    }
    printf("代码计算了 %d 次\n",count);
}


//冒泡优化后的代码
//优化的地方是 当最好情况的时候，冒泡排序的时间复杂度是O(n),例如完全不需要交换位置的数组
void mybubble_sort_better(int a[] ,int n){
    
    int count = 0;
    
    for (int i = 0; i < n - 1; i ++) {
        bool isSorted = 1;
        //每一轮比较前n-1-i个，即已排序好的最后i个不用比较
        //对比每一轮的执行过程中,是否都进行了排序操作,如果没有执行排序操作,则判定这一轮里面没有任何需要排序的动作,则程序提前结束
        for(int j=0; j<n-1-i; j++)
        {
            count ++ ;
            if(a[j] > a[j+1])
            {
                isSorted = 0;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;
            }
        }
        if(isSorted) break;
    }
    
    printf("优化后的代码计算了 %d 次\n",count);
}



int main(int argc, const char * argv[]) {
    
    //非优化的冒泡排序
    int num[N] = {89, 19, 44, 78, 96, 11, 38, 110};
    //{89, 19, 44, 78, 96, 11, 38, 110};
    ///{1, 2, 3, 4, 5,6, 7, 8};
    mybubble_sortbybringToEnd(num, N);
    for(int i=0; i<N; i++)
        printf("%d   ", num[i]);
    printf("\n");
    
    //优化后的冒泡排序
    int num_better[N] = {89, 19, 44, 78, 96, 11, 38, 110};
    //{8,7,6,5,4,3,2,1};
    //{1, 2, 3, 4, 5,6, 7, 8};
    //{89, 19, 44, 78, 96, 11, 38, 110};
    mybubble_sort_better(num_better, N);
    for(int i=0; i<N; i++)
        printf("%d   ", num_better[i]);
    printf("\n");
    
    return 0;
}
