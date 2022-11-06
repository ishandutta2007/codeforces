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

struct aib {
    int n;
    vector<ll> data;

    void init(int _n) {
        n = _n;
        data = vector<ll>(n + 13, 0);
    }

    int zrs(int x) {
        return (x & (x - 1)) ^ x;
    }

    void add(int x, ll val) {
        while (x <= n) {
            data[x] += val;
            x += zrs(x);
        }
    }

    ll sum(int x) {
        ll ans = 0;

        while (x > 0) {
            ans += data[x];
            x -= zrs(x);
        }

        return ans;
    }
};

int n, i;
int p[maxN];

ll fact[maxN], inv_fact[maxN];
aib work;

ll ans, rez;

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
    ll i, j;


    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[n] = poww(fact[n], mod - 2);
    for (i = n- 1; i > 0; i--) inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    inv_fact[0] = 1;
}

ll formula(ll n) {
    if (n <= 1) return 0;
    ll ans = (fact[n] * inv_fact[2]) % mod;
    ans = (ans * inv_fact[2]) % mod;
    ans = (ans * n) % mod;
    ans = (ans * (n - 1)) % mod;

    return ans;
}




int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &p[i]);

    pre();
    work.init(n);

    if (next_permutation(p + 1, p + n + 1) == false) {
        printf("%lld", formula(n));
        return 0;
    }

    for (i = 1; i <= n; i++) {
        ll cnt = p[i] - 1 - work.sum(p[i] - 1);
        work.add(p[i], +1);

        ans += (cnt * formula(n - i)) % mod;
        ans += ((((cnt * (cnt - 1)) / 2) % mod) * fact[n - i]) % mod;
        ans %= mod;

        ans += (((rez * fact[n - i]) % mod) * cnt) % mod;
        ans %= mod;

        rez += cnt;
        rez %= mod;
    }

    printf("%lld", ans);


    return 0;
}