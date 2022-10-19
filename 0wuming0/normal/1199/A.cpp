#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{/*
    int a[100009]={0},*b=(int*)malloc(100009*4),*c=(int*)malloc(100009*4),n,m,i,j,t,x,y;
    scanf("%d",&n);scanf("%d",&x);scanf("%d",&y);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    b[1]=10;
    for(i=2;i<=n;i++)
    {
        if(a[i-1]>a[i])
        {
            b[i]=b[i-1]+1;
        }
        else
        {
            b[i]=0;
        }
    }
    c[n]=10;
    for(i=n-1;i>0;i--)
    {
        if(a[i]<a[i+1])
        {
            c[i]=c[i+1]+1;
        }
        else
        {
            c[i]=0;
        }
    }*/
    int a[100009]={0},n,m,i,j,k,t,x,y;
    scanf("%d",&n);scanf("%d",&x);scanf("%d",&y);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    for(i=1;i<=n;i++)
    {
        for(j=max(1,i-x);j<=min(n,i+y);j++)
            if(a[j]<a[i])break;
        if(j==min(n,i+y)+1)
        {
            printf("%d",i);
            return 0;
        }
    }

    return 0;
}
/*
1 3 3
5
*/