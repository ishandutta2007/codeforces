//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = int;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;



void solve()
{
    ll n, k, s;
    cin >> n >> k >> s;
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    ll mx = n*(n-1)/2;
    vector<vector<ll>> dp(n+1,vector<ll>(mx+1,mod));
    dp[0][0] = 0;
    for (ll i=0;i<n;i++)
    {
        for (ll d=i;d>=0;d--)
        {
            ll M = i*(i+1)/2-(i-d)*((i-d)+1)/2;
            ll del = i-d;
            for (ll S=0;S<=M;S++)
            {
                dp[d+1][S+del] = min(dp[d+1][S+del],dp[d][S]+a[i]);
            }
        }
    }
    ll A = mod;
    for (ll m=0;m<=s and m<=mx;m++)
    {
        A = min(A,dp[k][m]);
    }
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}