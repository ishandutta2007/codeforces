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

#define mod 1000000007
#define maxN 1000011


ll poww(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

ll abss(ll x) {
    while (x < 0) x += mod;
    while (x >= mod) x -= mod;

    return x;
}

struct fast {
    int l, r, dim, i;
    vector<ll> fact, inv;

    void set(int _l, int _r) {
        l = _l;
        r = _r;
        dim = r - l + 1;

        fact.resize(dim + 11);
        inv.resize(dim + 11);

        fact[0] = (abss(l) != 0 ? abss(l) : 1);
        for (i = 1; i < dim; i++)
            fact[i] = (fact[i - 1] * (abss(l + i) != 0 ? abss(l + i) : 1)) % mod;

        inv[dim - 1] = poww(fact[dim - 1], mod - 2);
        for (i = dim - 2; i >= 0; i--)
            inv[i] = (inv[i + 1] * (abss(l + i + 1) != 0 ? abss(l + i + 1) : 1)) % mod;
    }


    ll prod(ll p1, ll p2) {
        if (p1 > p2) return 1;
        if (p1 <= 0 && p2 >= 0) return 0;

        if (p1 == l)
            return fact[p2 - l];
        else
            return (fact[p2 - l] * inv[p1 - 1 - l]) % mod;
    }
};

ll n, k, i;
ll y[maxN];
ll up, c[maxN];
fast aux;

ll ans, now;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &k);

    for (i = 1; i <= k + 2; i++) {
        y[i] = poww(i, k);
        y[i] += y[i - 1];
        y[i] = abss(y[i]);
    }

    //! get coef of polynomial
    aux.set(-k - 10, k + 10);

    k += 2;
    for (i = 1; i <= k; i++) {
        up = (aux.prod(i - k, -1) * aux.prod(1, i - 1)) % mod;
        up = (y[i] * poww(up, mod - 2)) % mod;

        c[i] = up;
    }

    ans = 0;

    //! compute f(n)
    aux.set(n - k - 10, n + k + 10);

    for (i = 1; i <= k; i++) {
        now = (aux.prod(n - (i - 1), n - 1) * aux.prod(n - k, n - (i + 1))) % mod;
        ans += (c[i] * now) % mod;
        ans = abss(ans);
    }

    printf("%lld", ans);

    return 0;
}