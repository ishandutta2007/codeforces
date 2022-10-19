#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{/*
    int a[200009],b,k,n,m,i,j,t,x,y,op;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&op);
        switch(op)
        {
            case 1:scanf("%d",&x);scanf("%d",&m);a[x]=m;
            break;
            case 2:scanf("%d",&m);
            for(i=1;i<=n;i++)if(a[i]<m)a[i]=m;
            break;
        }
    }
    for(i=1;i<=n;i++)printf("%d ",a[i]);putchar(10);*/
    int a[200009],p[200009],*m=(int*)malloc(200009*4),k,n,i,j,t,x,y,op;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&op);
        switch(op)
        {
            case 1:scanf("%d",p+i);scanf("%d",m+i);
            break;
            case 2:p[i]=0;scanf("%d",m+i);
            break;
        }
    }
    int *sum=(int*)malloc(200009*4);
    sum[t+1]=0;
    for(i=t;i>0;i--)
    {
        if(p[i])sum[i]=sum[i+1];
        else sum[i]=max(sum[i+1],m[i]);
    }
    int *man=(int*)malloc(200009*4);
    for(i=0;i<200009;i++)man[i]=0;
    for(i=1;i<=t;i++)if(p[i])man[p[i]]=i;
    for(i=1;i<=n;i++)
        printf("%d ",man[i]==0?max(a[i],sum[1]):max(m[man[i]],sum[man[i]+1]));
    putchar(10);
    free((void*)man);free((void*)sum);free((void*)m);
    return 0;
}
/*
4
1 2 3 4
3
2 3
1 2 2
2 1
*/