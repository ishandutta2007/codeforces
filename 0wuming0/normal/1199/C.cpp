#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[400009],b,k,n,m,i,j,t,x,y;
    scanf("%d",&n);
    scanf("%d",&b);
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    for(i=n;i<400009;i++)a[i]=-1;
    sort(a,a+n);
    int re;t=1;
    for(i=0;i<n;)
    {
        re=a[i];
        a[i]=t;
        while(a[++i]==re)a[i]=t;
        t++;
    }
    //for(i=0;i<n;i++)printf("\n%d",a[i]);
    int *pos;
    pos=(int*)malloc(400009*4);
    t=1;
    for(i=0;i<n;)
    {
        if(a[i]==t)pos[t]=i;
        while(a[++i]==t);
        t++;
    }
    t--;
    b*=8;
    b/=n;
    k=1;
    for(i=0;i<b;i++)
    {
        k*=2;
        if(k>n)
        {
            printf("0\n");
            free((void*)pos);
            return 0;
        }
    }
    if(t<=k)
    {
        printf("0\n");
        free((void*)pos);
        return 0;
    }
    int ans=0;
    for(i=1;i+k<=t;i++)
    {
        ans=max(ans,pos[i+k]-pos[i]);
    }
    ans=max(ans,n-pos[i]);
    printf("%d\n",n-ans);
    free((void*)pos);
    return 0;
}
/*
6 1
2 1 2 3 4 3
6 2
2 1 2 3 4 3
6 1
1 1 2 2 3 3

8 1
12 1 44 44 12 3 12 1
*/