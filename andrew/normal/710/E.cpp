#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll dp[20000010];
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    ll k;
    cin >> n >> m >> k;
    dp[0]=0;
    ll i,j;
    for(i=1;i<=20000001;i++)dp[i]=1e18;
   for(i=0;i<=n;i++)
   {
     dp[i+1]=min(dp[i+1],dp[i]+m);
     dp[i*2]=min(dp[i*2],dp[i]+k);
     if(i*2-1>=0)dp[i*2-1]=min(dp[i*2-1],dp[i]+k+m);
   }
   cout << dp[n];
       return 0;
}