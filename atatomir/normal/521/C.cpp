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

#define maxN 100011
#define mod 1000000007

int n, k, i, pos;
char s[maxN];

ll sum[maxN];
ll pow_ten[maxN];
ll fact[maxN], inv_fact[maxN];

ll ans, aux;


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

    for (i = 1; i <= n; i++) sum[i] = sum[i - 1] + s[i] - '0';

    pow_ten[0] = 1;
    fact[0] = 1, inv_fact[0] = 1;
    for (i = 1; i <= n; i++) {
        pow_ten[i] = (pow_ten[i - 1] * 10) % mod;
        fact[i] = (fact[i - 1] * i) % mod;
    }

    inv_fact[n] = poww(fact[n], mod - 2);
    for (i = n - 1; i > 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
}

ll comb(ll n, ll k) {
    static ll ans;
    ans = (fact[n] * inv_fact[k]) % mod;
    return (ans * inv_fact[n - k]) % mod;
}




int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n%s", &n, &k, s + 1);
    pre();

    for (int l = 1; n - l >= k; l++) {
        aux = 0;

        // 1 .. n-l
        pos = n - l;
        aux += ( sum[pos] * comb(n - l - 1, k - 1) ) % mod;

        // n - l + 1
        aux += comb(n - l, k) * (s[n - l + 1] - '0');

        aux %= mod;
        ans = (ans + pow_ten[l - 1] * aux) % mod;
    }

    printf("%lld", ans);


    return 0;
}