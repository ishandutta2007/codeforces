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

#define maxN 200011
#define mod 1000000007

int n, i, j;
ll v[maxN], data[maxN], aux[maxN];
ll fact[maxN], inv_fact[maxN];

ll get_value(int n, int k) {
    static ll data[maxN];
    int i, op;

    memset(data, 0, sizeof(data));
    data[k] = 1;

    op = 1;
    for (; n > 1; n--) {
        for (i = 1; i < n; i++, op ^= 1) {
            if (op)
                data[i] += data[i + 1];
            else
                data[i] -= data[i + 1];
        }
    }

    return data[1];
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

ll comb(ll n, ll k) {
    ll ans = (fact[n] * inv_fact[k]) % mod;
    ans = (ans * inv_fact[n - k]) % mod;
    return ans;
}

void solve(int n) {
    int i, k;

    if (n % 4 == 0) {
        k = n / 4;
        for (i = 0; i <= 2 * k - 1; i++) {
            data[2 * i] = comb(2 * k - 1, i);
            data[2 * i + 1] = mod - data[2 * i];
        }
    }

    if (n % 4 == 1) {
        k = n / 4;
        for (i = 0; i <= 2 * k; i++) {
            data[2 * i] = comb(2 * k, i);
            data[2 * i + 1] = 0;
        }
    }

    if (n % 4 == 2) {
        k = n / 4;
        for (i = 0; i <= 2 * k; i++) {
            data[2 * i] = comb(2 * k, i);
            data[2 * i + 1] = data[2 * i];
        }
    }

    if (n % 4 == 3) {
        solve(n - 1);

        memcpy(aux, data, sizeof(aux));
        memset(data, 0, sizeof(data));

        for (i = 0; i <= n - 1; i++) {
            data[i] += aux[i + 1];
            if (i % 2 == 0)
                data[i + 1] += aux[i + 1];
            else
                data[i + 1] += mod - aux[i + 1];
        }
    }

    for (i = n; i > 0; i--)
        data[i] = data[i - 1] % mod;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%lld", &v[i]);

    //n = 19;
    //for (i = 1; i <= n; i++) cerr << get_value(n, i) << ' ';

    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[n] = poww(fact[n], mod - 2);
    for (i = n - 1; i > 0; i--) inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    inv_fact[0] = 1;

    solve(n);
    ll ans = 0;

    for (i = 1; i <= n; i++)
        ans += v[i] * data[i], ans %= mod;

    ans %= mod;
    cout << ans;


    return 0;
}