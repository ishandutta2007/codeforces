#include"stdio.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int a[300005],n,k,i,sum=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",a+i);
    for(i=0;i<n-1;i++)a[i]=a[i+1]-a[i];
    sort(a,a+n-1);
    for(i=0;i<n-k;i++)sum+=a[i];
    printf("%d\n",sum);
    return 0;
}