#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[6][1001],dp[1001],i,j,v[1001][1001];
int main ()
{
    ll n,k;
    cin >> n >> k;
    for(i=1;i<=k;i++)for(j=1;j<=n;j++)cin >> a[i][j];
    for(i=1;i<=k;i++)for(j=1;j<=n;j++)v[i][a[i][j]]=j;
    ll ans=-1e9;
    for(ll cc=1;cc<=n;cc++)
    {
        ll c=a[1][cc];
        dp[c]=1;
       for(i=1;i<cc;i++)
       {
           ll fl=1;
           ll xx=a[1][i];
           for(j=2;j<=k;j++)if(v[j][xx]<v[j][c])fl++;
           //cout << c << " "  << i << " " << fl << endl;
           if(fl==k)dp[c]=max(dp[c],dp[xx]+1);
       }
    }
    //for(i=1;i<=n;i++)cout << dp[i] << "-"; cout << endl;
    for(i=1;i<=n;i++)ans=max(ans,dp[i]);
    cout << ans << endl;
 return 0;
}