#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)
#define INF ((ll)2e9)



ll n,dp[2][N];
ll ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<N;i++)dp[0][i]=dp[1][i]=INF;
    dp[0][0]=-INF;
    ll change=0;
    for(int i=1;i<=n;i++)
    {
        ll x;cin>>x;
        ll id=upper_bound(dp[1],dp[1]+N,x-i+1)-dp[1];
        dp[1][id]=x-i+1;ans=max(ans,id);
        dp[1][change]=min(dp[1][change],dp[0][change]);ans=max(ans,change);
        id=upper_bound(dp[0],dp[0]+N,x-i)-dp[0];
        change=id;
        dp[0][id]=x-i;
    }
    cout<<n-ans-1<<"\n";
    return 0;
}