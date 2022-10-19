#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

void solve() {
    ll n, p;
    cin >> n >> p;
    int ans = 1e9;
    for (int it = 1; it < 50; it++) {
        ll m = n - p * it;
        if (m <= 0) continue;
        if (__builtin_popcount(m) <= it && m >= it) {
            ans = min(ans, it);
        }
    }
    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}