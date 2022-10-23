//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;




void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(k+1,vector<ll>(k+1));
    dp[0][0] = 1;
    for (ll w=0;w<n;w++)
    {
        ll x;
        cin >> x;
        for (ll i=k-x;i>=0;i--)
        {
            for (ll j=k-i-x;j>=0;j--)
            {
                if (dp[i][j]==0) continue;
                dp[i+x][j] = 1;
                dp[i][j+x] = 1;
            }
        }
    }
    vector<ll> a;
    for (ll b=0;b<=k;b++) if (dp[b][k-b]==1) a.push_back(b);
    cout << a.size() << "\n";
    for (ll x: a) cout << x << " ";

}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}