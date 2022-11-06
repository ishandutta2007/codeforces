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

ll n, m, i;
ll fact[maxN], inv_fact[maxN];
ll ans;

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);

    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
    inv_fact[n] = poww(fact[n], mod - 2);
    for (i = n - 1; i >= 0; i--) inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;

    for (i = 0; i < n; i++) {
        ll comb = ((fact[n] * inv_fact[n - i - 1]) % mod) * inv_fact[i + 1];
        comb %= mod;

        comb *= poww(m - 1, i);
        comb %= mod;

        comb *= poww(m, n - i);
        comb %= mod;

        ans += comb;
    }

    ans += poww(m, n);
    ans %= mod;

    printf("%lld", ans);

    return 0;
}