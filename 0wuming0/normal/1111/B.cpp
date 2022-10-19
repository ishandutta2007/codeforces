#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    double sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    double ans=0;
    for(int i=0;i<n&&m>=i;i++)
    {
        sum-=a[i];
        ans=max((sum+min(k*(long long)(n-i),(long long)m-i))/(n-i),ans);
    }
    printf("%.15f\n",ans);
    return 0;
}