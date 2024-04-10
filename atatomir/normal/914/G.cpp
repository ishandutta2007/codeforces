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

const int sz = 17;
const int dim = 1 << sz;

int n, i, j, k;
int s[maxN];
ll fib[maxN];

ll aux[maxN];
ll aux2[maxN];

ll p1[maxN];
ll p2[maxN];
ll p3[maxN];

ll sol[maxN];

ll conv_a[sz + 1][dim], conv_b[sz + 1][dim];

ll bts_cnt(ll x) {
    ll ans = 0;

    while (x > 0) {
        if (x & 1) ans++;
        x >>= 1;
    }

    return ans;
}

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

void fwht(ll *data, bool inv = false) {
    ll n, i, j, len, u, v;
    n = dim;

    for (len = 1; 2 * len <= n; len <<= 1) {
        for (i = 0; i < n; i += 2 * len) {
            for (j = 0; j < len; j++) {
                u = data[i + j];
                v = data[i + len + j];

                data[i + j] = u + v;
                data[i + len + j] = u + mod - v;

                data[i + j] %= mod;
                data[i + len + j] %= mod;
            }
        }
    }

    if (inv) {
        ll xx = poww(n, mod - 2);
        for (i = 0; i < n; i++) data[i] = (data[i] * xx) % mod;
    }
}

void dp_subset(ll *data, ll sgn) {
    int i, j;

    for (i = 0; i < sz; i++) {
        for (j = 0; j < dim; j++) {
            if (j & (1 << i)) {
                data[j] += mod + sgn * data[j ^ (1 << i)];
                data[j] %= mod;
            }
        }
    }
}

void dp_supraset(ll *data, ll sgn) {
    int i, j;

    for (i = 0; i < sz; i++) {
        for (j = 0; j < dim; j++) {
            if ((j & (1 << i)) == 0) {
                data[j] += mod + sgn * data[j ^ (1 << i)];
                data[j] %= mod;
            }
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i <= dim; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &s[i]);

    //! prima parte
    /*
    memset(aux, 0, sizeof(aux));
    for (i = 1; i <= n; i++) aux[s[i]]++;

    for (int conf = 0; conf < dim; conf++) {
        for (int conf1 = conf; conf1 >= 0; conf1 = (conf1 - 1) & conf) {
            int conf2 = conf ^ conf1;
            p1[conf] += aux[conf1] * aux[conf2];
            p1[conf] %= mod;

            if (conf1 == 0) break;
        }
    }*/

    for (i = 1; i <= n; i++)
        conv_a[bts_cnt(s[i])][s[i]]++;

    for (i = 0; i <= sz; i++) dp_subset(conv_a[i], +1);

    for (i = 0; i < dim; i++) {
        for (j = 0; j <= sz; j++) {
            ll work = 0;

            for (k = 0; k <= j; k++) {
                work += conv_a[k][i] * conv_a[j - k][i];
                work %= mod;
            }

            conv_b[j][i] = work;
        }
    }

    for (i = 0; i <= sz; i++) dp_subset(conv_b[i], -1);
    for (i = 0; i < dim; i++)
        p1[i] = conv_b[bts_cnt(i)][i];


    //! a doua parte
    for (i = 1; i <= n; i++) p2[s[i]]++;

    //! a treia parte
    memset(aux, 0, sizeof(aux));
    for (i = 1; i <= n; i++) aux[s[i]]++;
    fwht(aux);
    for (i = 0; i < dim; i++) aux[i] = (aux[i] * aux[i]) % mod;
    fwht(aux, true);
    for (i = 0; i < dim; i++) p3[i] = aux[i];

    //! prelucreaza
    for (i = 0; i < dim; i++) {
        p1[i] = (p1[i] * fib[i]) % mod;
        p2[i] = (p2[i] * fib[i]) % mod;
        p3[i] = (p3[i] * fib[i]) % mod;
    }

    dp_supraset(p1, +1);
    dp_supraset(p2, +1);
    dp_supraset(p3, +1);

    for (i = 0; i < dim; i++) {
        sol[i] = p1[i] * p2[i];
        sol[i] %= mod;

        sol[i] *= p3[i];
        sol[i] %= mod;
    }

    dp_supraset(sol, -1);

    ll ans = 0;
    for (i = 0; i < sz; i++)
        ans += sol[1 << i];

    ans %= mod;
    printf("%lld", ans);


    return 0;
}