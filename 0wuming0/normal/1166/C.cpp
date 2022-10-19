#include<iostream>
#include<algorithm>
#include"stdio.h"
using namespace std;
int a[200005],n;
int finding(int x,int y)
{
    if(x>y)return 0;
    int l,r;
    int p=-1,q=n,t;
    while(1)
    {
        t=(p+q)/2;
        if(a[t]<x)p=t;
        else q=t;
        if(p+1==q)break;
    }
    l=q;
    p=-1;q=n;
    while(1)
    {
        t=(p+q)/2;
        if(a[t]>y)q=t;
        else p=t;
        if(p+1==q)break;
    }
    r=q;
    return r-l;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        if(a[i]<0)a[i]=-a[i];
    }
    sort(a,a+n);
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        int s=0;
        for(;i<n-1;i++)
        {
            if(a[i]==a[i+1])s++;
            else break;
        }
        sum=sum+s*(long long)(s+1)/2;
    }
    //printf("%lld\n",sum);
    for(int i=0;i<n;i++)
    {
        sum=sum+finding(a[i]+1,2*a[i]);
    }
    printf("%lld\n",sum);
    return 0;
}