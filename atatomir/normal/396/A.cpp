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

#define maxN 511
#define mod 1000000007

const int def = 100000;

int n, i;
bool ciur[def + 11];
vector< pair<ll, int> > primes;
ll fact[def + 11], inv_fact[def + 11];
ll x, ans;


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

    for (i = 2; i <= def; i++) {
        if (ciur[i]) continue;

        primes.pb(mp(i, 0));
        for (j = i * i; j <= def; j += i) ciur[j] = true;
    }

    fact[0] = 1;
    for (i = 1; i <= def; i++) fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[def] = poww(fact[def], mod - 2);
    for (i = def - 1; i > 0; i--) inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    inv_fact[0] = 1;
}

ll comb(ll n, ll k) {
    ll ans = (fact[n] * inv_fact[k]) % mod;
    return (ans * inv_fact[n - k]) % mod;
}

void desc(ll x) {
    int i;

    for (i = 0; i < primes.size(); i++) {
        int e = primes[i].first;

        while (x % e == 0) {
            x /= e;
            primes[i].second++;
        }
    }

    if (x != 1) primes.pb(mp(x, 1));
}

ll compute(int id) {
    if (primes[id].second == 0) return 1;
    return comb(primes[id].second + n - 1, n - 1);
}


int main()
{
    //freopen("test.in","r",stdin);

    pre();
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%lld", &x);
        desc(x);
    }

    ans = 1;
    for (i = 0; i < primes.size(); i++)
        ans = (ans * compute(i)) % mod;
    printf("%lld", ans);


    return 0;
}