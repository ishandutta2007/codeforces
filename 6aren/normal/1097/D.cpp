#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
const int base = 1e7;
const int MOD = 1e9 + 7;

ll n, k, nP = 0, P[2][1000], revi[200];
ii p[20];

void getPrime() {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i) continue;
        p[nP] = make_pair(i, 0);
        while (n % i == 0) {
            p[nP].second++;
            n /= i;
        }
        nP++;
    }
    if (n != 1) {
        p[nP] = make_pair(n, 1);
        nP++;
    }
}

ll muli(ll x, ll y) {
    ll x1 = x / base; ll x2 = x % base;
    return (((((x1 * y) % MOD) * base) % MOD) + x2 * y % MOD) % MOD;
}

ll power(ll x, ll y) {
    if (y == 0) return 1;
    ll tmp = power(x, y / 2);
    if (y % 2 == 0) {
        return muli(tmp, tmp);
    } else return muli(x, muli(tmp, tmp));
}

ll rev(ll x) {
     return power(x, MOD - 2);
}

ll frac(ll x, ll y) {
     return muli(x, revi[y]);
}

ll calc(ii x) {
    ll u = x.first; ll v = x. second;
    ll add = 0; ll mul = 1;
    for (int i = 0; i < v; i++) {
        P[0][i] = 0;
    }
    P[0][v] = 1;
    for (int i = 1; i <= k; i++) {
        int m = i % 2;
        int l = 1 - m;
        for (int j = v; j >= 0; j--) {
            P[m][j] = 0;
            for (int t = j; t <= v; t++) {
                P[m][j] = (P[m][j] + frac(P[1 - m][t], t + 1)) % MOD;
            }
        }
    }
    ll res = 0;
    ll pw[100];
    pw[0] = 1;
    for (int i = 1; i <= v; i++) {
        pw[i] = pw[i - 1] * u;
    }
    for (int i = 0; i <= v; i++) {
        res = (res + muli(pw[i], P[k % 2][i])) % MOD;
    }
    return res;
}

int main() {
    cin >> n >> k;
    getPrime();
    for (int i = 0; i <= 100; i++) {
        revi[i] = rev(i);
    }
    ll ans = 1;
    for (int i = 0; i < nP; i++) {
        ans = muli(ans, calc(p[i]));
    }
    cout << ans;
}