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
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;

ll modpow(ll x,ll h)
{
    ll res=1;
    for (;h;h>>=1)
    {
        if (h&1) res=res*x%mod;
        x=x*x%mod;
    }
    return res;
}

ll inverse(ll x)
{
    return modpow(x,mod-2);
}

ll dp[N], C[20][20];
int n, a[N];
vi vt[N];

void add(ll &x, ll y)
{
    x += y;
    if (x >= mod) x -= mod;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << 1 * inverse(4) % mod;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) C[i][j] = a[i] * inverse(a[i] + a[j]) % mod;
    for (int mask = 1; mask < (1 << n); ++mask)
        for (int i = 0; i < n; ++i)
            if ((mask >> i) & 1) vt[mask].eb(i + 1);
    ll res = 0;
    for (int mask = 1; mask < (1 << n); ++mask)
    {
        ll cof = 1;
        for (int i : vt[mask])
            for (int j : vt[((1 << n) - 1) ^ mask]) cof = cof * C[i][j] % mod;
        dp[mask] = cof;
        for (int smask = (mask - 1) & mask; smask; smask = (smask - 1) & mask)
        {
            ll val = dp[smask];
            int tmp = mask ^ smask;
            for (int i : vt[tmp])
                for (int j : vt[((1 << n) - 1) ^ mask]) val = val * C[i][j] % mod;
            add(dp[mask], mod - val);
        }
        //cout << mask << " " << dp[mask] << "\n";
        res = (res + dp[mask] * __builtin_popcount(mask)) % mod;
    }
    cout << res;
    return 0;
}