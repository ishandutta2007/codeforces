#include"bits/stdc++.h"
#define ll long long
using namespace std;
int n;
ll sum=0;
ll solve(int a[])
{
    if(n==1)return a[0];
    ll ans=0;
    ll best=0;
    for(int i=2;i<n-2;i+=2)ans+=a[i];
    best=ans;
    for(int i=n-2;i>2;i-=2)
    {
        ans=ans+a[i]-a[i-1];
        best=min(ans,best);
    }
    return sum-best-a[0];
}
int main()
{
    int a[200006];
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    a[n]=a[0];
    a[n+1]=a[1];
    for(int i=0;i<n;i++)sum=a[i]+sum;
    ll ans=solve(a);
    ans=max(solve(a+1),ans);
    ans=max(solve(a+2),ans);
    cout<<ans<<endl;
    return 0;
}