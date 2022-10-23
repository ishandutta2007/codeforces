#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 2e5 + 10, mod = 998244353;
int x[N], y[N], n, s[N];
ll dp[N], ps[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i] >> s[i];
    for (int i = 1; i <= n; ++i)
    {
        int j = lower_bound(x + 1, x + n + 1, y[i]) - x;
        dp[i] = (x[i] - y[i] + ps[i - 1] - ps[j - 1] + mod * 2) % mod;
        ps[i] = (ps[i - 1] + dp[i]) % mod;
    }
    ll res = (x[n] + 1) % mod;
    for (int  i = 1; i <= n; ++i)
        if (s[i]) res = (res + dp[i]) % mod;
    cout << res;
    return 0;
}