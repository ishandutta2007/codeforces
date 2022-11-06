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

#define maxN 400011
#define mod 1000000007

const int def = 400000;

int n, i, le, ri;
char s[maxN];
ll fact[maxN], inv_fact[maxN];
ll dp[maxN];
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

void pre() {
    int i;

    fact[0] = 1;
    for (i = 1; i <= def; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[def] = poww(fact[def], mod - 2);
    for (i = def - 1; i > 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    inv_fact[0] = 1;
}

ll comb(ll n, ll k) {
    if (n < 0) return 0;
    if (k < 0) return 0;

    if (k == 0)
        return 1;

    return (((fact[n] * inv_fact[k]) % mod) * inv_fact[n - k]) % mod;
}

int main()
{
    //freopen("test.in","r",stdin);

    pre();

    scanf("%s", s + 1);
    n = strlen(s + 1);

    for (i = 1; i <= n; i++)
        if (s[i] == ')')
            ri++;

    dp[0] = 1;
    for (i = 1; i <= n; i++) {
        if (s[i] == '(')
            le++;
        else
            ri--;

        dp[i] = comb(le + ri, le);
        dp[i] = max(dp[i], 1LL);

        if (s[i] == '(')
            ans += mod + dp[i] - dp[i - 1];

    }

    printf("%lld", ans % mod);


    return 0;
}