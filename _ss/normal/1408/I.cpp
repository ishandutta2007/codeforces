#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define eb emplace_back
const int N = 1 << 16, mod = 998244353;

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

int n, k, c;
vi vt[20];
ll dp[20][N], C[20][20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> c;
    int val = 0;
    for (int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        int tmp = x ^ (x - k);
        int d = 0;
        while (tmp)
        {
            tmp >>= 1;
            d++;
        }
        vt[d].eb(x);
        val ^= x;
    }
    for (int i = 0; i <= k; ++i)
    {
        C[0][i] = 1;
        for (int j = 1; j <= i; ++j) C[j][i] = C[j][i - 1] + C[j - 1][i - 1];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= c; ++i)
        for (int x : vt[i])
        {
            int mx = (1 << i) - 1;
            x &= mx;
            for (int sl = k - 1; sl >= 0; --sl)
                for (int add = 1; add <= k - sl; ++add)
                {
                    int change = x ^ (x - add), nsl = sl + add;
                    ll cof = C[add][k - sl];
                    for (int mask = 0; mask <= mx; ++mask)
                        dp[nsl][mask] = (dp[nsl][mask] + dp[sl][mask ^ change] * cof) % mod;
                }
        }
    for (int i = 0; i < (1 << c); ++i)
        if (i < (i ^ val)) swap(dp[k][i], dp[k][i ^ val]);
    ll inv = inverse(modpow(n, k));
    for (int i = 0; i < (1 << c); ++i)
        cout << dp[k][i] * inv % mod << " ";
    return 0;
}