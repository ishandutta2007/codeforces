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
#define maxDivs 22

ll n, p, l, r, vips;
vector<ll> divs;

ll phi;
ll modifs[maxN], fact[maxN], inv_fact[maxN];
ll sum[maxN][maxDivs];
ll ans;

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }

    return ans;
}

ll get_divs(ll p) {
    phi = p;
    for (ll d = 2; d * d <= p; d++) {
        if (p % d) continue;
        phi /= d;
        phi *= d - 1;

        divs.pb(d);
        while (p % d == 0) p /= d;
    }
    if (p > 1) {
        phi /= p;
        phi *= p - 1;
        divs.pb(p);
    }
}

void pre() {
    ll i, j, aux;

    modifs[0] = 1;
    for (i = 1; i <= n; i++) {
        aux = i;
        for (j = 0; j < divs.size(); j++) {
            sum[i][j] = sum[i - 1][j];
            while (aux % divs[j] == 0) {
                aux /= divs[j];
                sum[i][j]++;
            }
        }
        modifs[i] = aux;
    }

    fact[0] = 1;
    for (i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * modifs[i]) % p;

    inv_fact[n] = poww(fact[n], phi - 1);
    for (i = n - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * modifs[i + 1]) % p;
}

ll comb(ll n, ll k) {
    if (n < 0 || k < 0) return 0;

    ll ans = (fact[n] * inv_fact[k]) % p;
    ans = (ans * inv_fact[n - k]) % p;

    for (ll i = 0; i < divs.size(); i++) {
        ll cnt = sum[n][i] - sum[k][i] - sum[n - k][i];
        ans = (ans * poww(divs[i], cnt)) % p;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> p >> l >> r;
    r = min(n, r);


    get_divs(p);
    pre();

    for (vips = 0; vips <= n - l; vips++) {
        ll put_vips = comb(n, vips);
        ll rem = n - vips;

        ans += (put_vips * (p + comb(rem, (rem - l) / 2 ) - comb(rem, (rem - r + 1) / 2 - 1))) % p;
        ans %= p;
    }

    cout << ans;


    return 0;
}