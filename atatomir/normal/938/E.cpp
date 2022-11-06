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

ll n, i, j, sz1, sz2, N;
ll a[maxN];
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

int main()
{
   // freopen("test.in","r",stdin);

    scanf("%lld", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]);

    N = n + 3;

    fact[0] = 1;
    for (i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[N] = poww(fact[N], mod - 2);
    for (i = N - 1; i >= 0; i--) inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;

    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i = j) {
        for (j = i; j <= n && a[i] == a[j]; j++);

        if (j == n + 1) break;

        sz1 = i - 1;
        sz2 = n - i;

        aux = fact[sz2] * fact[sz1 + sz2 + 1];
        aux %= mod;
        aux = aux * inv_fact[sz2 + 1];
        aux %= mod;
        aux *= j - i;
        aux %= mod;

        ans += aux * a[i];
        ans %= mod;
    }

    printf("%lld", ans);



    return 0;
}