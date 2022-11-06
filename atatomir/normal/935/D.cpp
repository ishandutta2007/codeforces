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
#define maxN 100011

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

const ll inv2 = poww(2, mod - 2);

ll n, m, i, act, inv_m, pr_one;
ll a[maxN], b[maxN];
ll ans;

ll prob(ll k) {
    return (k * inv_m) % mod;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &m);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (i = 1; i <= n; i++) scanf("%lld", &b[i]);

    inv_m = poww(m, mod - 2);
    pr_one = prob(1);

    act = 1;
    for (i = 1; i <= n; i++) {
        if (a[i] != 0 && b[i] != 0) {
            if (a[i] > b[i]) {
                ans += act;
                ans %= mod;
                break;
            }

            if (a[i] == b[i]) continue;

            break;
        }

        if (a[i] != 0 && b[i] == 0) {
            ans += act * prob(a[i] - 1);
            ans %= mod;

            act = (act * pr_one) % mod;
        }

        if (a[i] == 0 && b[i] != 0) {
            ans += act * prob(m - b[i]);
            ans %= mod;

            act = (act * pr_one) % mod;
        }

        if (a[i] == 0 && b[i] == 0) {
            ll eq = pr_one;
            ll dif = (1 + mod - pr_one) % mod;

            ans += ((dif * inv2) % mod) * act;
            ans %= mod;

            act = (act * eq) % mod;
        }
    }

    //cerr << (11 * 11 * poww(26, mod - 2)) % mod << '\n';

    printf("%lld", ans);



    return 0;
}