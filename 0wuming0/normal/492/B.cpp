#include"bits/stdc++.h"
using namespace std;
int a[1005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    double ans=1e9;
    ans=max(m-a[n-1],a[0]);
    for(int i=1;i<n;i++)
    {
        ans=max((a[i]-a[i-1])/2.0,ans);
    }
    printf("%.15f",ans);
    return 0;
}