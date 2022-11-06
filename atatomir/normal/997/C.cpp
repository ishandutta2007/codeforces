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

const ll maxN = 1000000;
const ll mod = 998244353;

ll n, i;
ll ans, aux, aux2;

ll fact[maxN], inv_fact[maxN];

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
    ll ans = (fact[n] * inv_fact[n - k]) % mod;
    return (ans * inv_fact[k]) % mod;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;

    fact[0] = 1;
    for (i = 1; i <= n; i++) 
        fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[n] = poww(fact[n], mod - 2);
    for (i = n - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;

    for (i = 1; i <= n; i++) {
        aux = (comb(n, i) * poww(3, i)) % mod;        
        aux = (aux * poww(3, n * (n - i))) % mod;
        if (i % 2 == 0) aux = (mod - aux) % mod;
        ans = (ans + 2LL * aux) % mod;
    }

    for (i = 0; i < n; i++) {
        aux = (1 + mod - poww(3, i)) % mod;
        aux = poww(aux, n);

        aux2 = (mod - poww(3, i)) % mod;
        aux2 = poww(aux2, n);

        aux = (aux + mod - aux2) % mod;
        if ((i + 1) % 2 == 1) aux = (mod - aux) % mod;
        aux = (aux * comb(n, i)) % mod;
        ans = (ans + 3LL * aux) % mod;
    }

    cout << ans;

    return 0;
}