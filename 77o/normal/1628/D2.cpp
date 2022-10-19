#include <bits/stdc++.h>
#include <cassert>
#include <functional>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            (res *= a) %= MOD;
        p >>= 1;
        (a *= a) %= MOD;
    }
    return res;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    if (n == m) {
        cout << k * n % MOD << '\n';
        return;
    }

    int sz = n * 2 + 5;
    vector<ll> f(sz), fr(sz);
    f[0] = fr[0] = 1;
    for (int i = 1; i < sz; i++) {
        f[i] = f[i - 1] * i % MOD;
        fr[i] = binpow(f[i], MOD - 2);
    }

    auto cnk = [&](int n, int k) {
        assert(n >= k);
        return f[n] * fr[k] % MOD * fr[n - k] % MOD;
    };

    ll inv2 = binpow(2, MOD - 2);
    ll ans = 0;
    if (n > m)
        for (int i = 1; i < m; i++) {
            ll val = i * k % MOD * inv2 % MOD;
            int distY = n - m - 1;
            int distX = m - i;
            ll div = binpow(inv2, distX + distY);
            (ans += val * cnk(distX + distY, distX) % MOD * div) %= MOD;
        }
    (ans += m * k % MOD * binpow(inv2, n - m)) %= MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}