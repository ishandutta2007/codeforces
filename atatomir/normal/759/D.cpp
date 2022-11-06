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

#define maxN 5011
#define sigma 26
#define mod 1000000007

int n, i, j, ch;
char s[maxN];

ll dp[maxN][sigma + 3]; // dp[cate grupe][final in acel caracter]
ll sum[maxN];
ll old, act;

ll fact[maxN], inv_fact[maxN];
ll ans;

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

ll comb(ll n, ll k) {
    if (k == 0) return 1;

    ll aux = (fact[n] * inv_fact[k]) % mod;
    return (aux * inv_fact[n - k]) % mod;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &n, s + 1);

    for (i = 1; i <= n; i++) {
        ch = s[i] - 'a';

        for (j = 2; j <= i; j++) {
            old = dp[j - 1][ch];

            act = sum[j - 1] - old;
            if (act < 0) act += mod;

            sum[j] += act - dp[j][ch];
            if (sum[j] < 0) sum[j] += mod;
            if (sum[j] >= mod) sum[j] -= mod;

            dp[j][ch] = act;
        }

        sum[1] += 1 - dp[1][ch];
        dp[1][ch] = 1;
    }

    fact[0] = 1;
    for (i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[n] = poww(fact[n], mod - 2);
    for (i = n - 1; i > 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    inv_fact[0] = 1;

    for (i = 1; i <= n; i++) {
        ll aux = sum[i];

        ans += (aux * comb(n - 1, i - 1)) % mod;
        ans %= mod;
    }

    printf("%lld", ans);

    return 0;
}