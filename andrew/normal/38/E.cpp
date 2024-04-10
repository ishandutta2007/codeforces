#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
using namespace std;
pair<ll, ll> a[3001];
ll s[3001][3001],dp[3001],i,j,n,m,k,sc;
int main ()
{
  ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++)
    {
        s[i][i]=0;
        for(j=i+1;j<=n;j++)
        {
            s[i][j]=s[i][j-1]+a[j].fi-a[i].fi;
        }
    }
    for(i=n;i>0;i--)
    {
        dp[i]=0;
        ll d=1e18;
        for(j=i;j<=n;j++)d=min(d,dp[j+1]+s[i][j]+a[i].se);
        dp[i]=d;
    }
    cout << dp[1] << endl;
 return 0;
}