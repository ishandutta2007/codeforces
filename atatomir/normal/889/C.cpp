#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1000011
#define mod 1000000007

ll n, k, i, j;
ll fact[maxN], over[maxN];
ll inv_fact[maxN];

ll sums[maxN];
ll dp[maxN];

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

void solve() {
    ll i, j;

    dp[n + 1] = sums[n + 1] = 0;
    for (i = n; i > 0; i--) {
        dp[i] = over[n];
        add(dp[i], sums[i + 1]);
        if (i + k + 1 <= n)
            add(dp[i], mod - sums[i + k + 1]);

        sums[i] = (dp[i] * over[i - 1]) % mod;
        add(sums[i], sums[i + 1]);
    }
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out", "w", stdout);

    cin >> n >> k;

    fact[0] = 1;
    for (i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[n] = poww(fact[n], mod - 2);
    for (i = n - 1; i > 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    inv_fact[0] = 1;

    for (i = 1; i <= n; i++)
        over[i] = (inv_fact[i] * fact[i - 1]) % mod;

    solve();
    ll ans = (dp[1] * fact[n]) % mod;

    ans = (fact[n] + mod - ans) % mod;
    cout << ans;

    return 0;
}