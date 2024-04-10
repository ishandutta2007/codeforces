#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int ju(int *a,int n,int k)
{
    int i=1,t=a[0];
    ll m;
    for(i=1;i<n;i++)
    {
        if((m=((ll)a[i]-t)*i)>=(ll)k)break;
        k=k-(int)m;
        t=a[i];
    }
    return t+k/i;
}
int main()
{
    int b,i,j,k,n,m,sum=0,t,mm;
    scanf("%d",&n);scanf("%d",&k);
    int a[200000];
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    sort(a,a+n);
    m=(n+1)/2;
    //(n+1)/2;n
    printf("%d\n",ju(a+m-1,m,k));
    return 0;
}
/*

*/