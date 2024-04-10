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

#define maxN 300011
#define mod 1000000007

const int def = 250000;

ll f, w, h, i;
ll fact[maxN], inv_fact[maxN];

ll up, down;

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
    for (i = 1; i <= def; i++) fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[def] = poww(fact[def], mod - 2);
    for (i = def - 1; i > 0; i--) inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    inv_fact[0] = 1;
}

ll comb(ll n, ll k) {
    if (n < 0 || k < 0) return 0;
    if (n < k) return 0;

    if (n == k) return 1;
    if (k == 0) return 1;

    return (((fact[n] * inv_fact[k]) % mod) * inv_fact[n - k]) % mod;
}

pair<ll, ll> solve(ll wine, ll food) {
    if (wine < 0 || wine > w) return mp(0, 0);
    if (food < 0 || food > f) return mp(0, 0);

    ll up = 0;
    ll down = 0;

    if (w - wine * h >= wine)
        up = comb(w - wine * h - 1, wine - 1) * comb(f - 1, food - 1);
    down = comb(w - 1, wine - 1) * comb(f - 1, food - 1);

    return mp(up % mod, down % mod);
}

int main()
{
    //freopen("test.in","r",stdin);

    pre();
    scanf("%lld%lld%lld", &f, &w, &h);

    if (f == 0) {
        if (w > h)
            printf("1");
        else
            printf("0");

        return 0;
    }

    if (w == 0) {
        printf("1");
        return 0;
    }

    for (i = 1; i <= w; i++) {
        auto act = solve(i, i - 1);
        up += act.first;
        down += act.second;

        act = solve(i, i);
        up += 2LL * act.first;
        down += 2LL * act.second;

        act = solve(i, i + 1);
        up += act.first;
        down += act.second;

        up %= mod;
        down %= mod;
    }

    ll ans = up * poww(down, mod - 2) ;
    ans %= mod;

    printf("%lld", ans);


    return 0;
}