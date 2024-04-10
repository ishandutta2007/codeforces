#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[100005];
ll dp[100005][3];
int main()
{
    int n;
    cin>>n;
    ll x,y,z;
    cin>>x>>y>>z;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
        dp[i][0]=dp[i][1]=dp[i][2]=-8e18;
    }
    dp[0][0]=dp[0][1]=dp[0][2]=-8e18;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=max(x*a[i],dp[i-1][0]);
        dp[i][1]=max(y*a[i]+dp[i][0],dp[i-1][1]);
        dp[i][2]=max(z*a[i]+dp[i][1],dp[i-1][2]);
    }
    cout<<dp[n][2]<<endl;
    return 0;
}