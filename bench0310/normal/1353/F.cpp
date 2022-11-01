#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll inf=(1ll<<62);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<ll>> a(n+1,vector<ll>(m+1,0));
        vector<ll> v;
        for(int o=1;o<=n;o++)
        {
            for(int i=1;i<=m;i++)
            {
                cin >> a[o][i];
                v.push_back(a[o][i]-(o+i-2));
            }
        }
        ll res=inf;
        for(ll x:v)
        {
            vector<vector<ll>> dp(n+1,vector<ll>(m+1,inf));
            if(x<=a[1][1]) dp[1][1]=(a[1][1]-x);
            for(int o=1;o<=n;o++)
            {
                for(int i=1;i<=m;i++)
                {
                    ll b=min(dp[o-1][i],dp[o][i-1]);
                    if(b==inf) continue;
                    ll y=x+(o+i-2);
                    if(y<=a[o][i]) dp[o][i]=b+(a[o][i]-y);
                }
            }
            res=min(res,dp[n][m]);
        }
        cout << res << "\n";
    }
    return 0;
}