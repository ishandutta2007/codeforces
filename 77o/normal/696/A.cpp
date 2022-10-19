#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <map>
#include <random>

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

mt19937 rng(123);

void solve() {
    int q;
    cin >> q;
    map<ll, ll> w;
    auto add = [&](ll n, ll c) {
        while (n > 1) {
            w[n] += c;
            n /= 2;
        }
    };
    auto get = [&](ll v) {
        ll res = 0;
        while (v > 1) {
            res += w[v];
            v /= 2;
        }
        return res;
    };
    auto isParent = [&](ll v, ll u) {
        ll l = v, r = v;
        while (l * 2 <= u) {
            l *= 2;
            r = r * 2 + 1;
        }
        return l <= u && u <= r;
    };
    auto lca = [&](ll a, ll b) {
        ll v = 1;
        while (true) {
            if (isParent(v * 2, a) && isParent(v * 2, b))
                v *= 2;
            else if (isParent(v * 2 + 1, a) && isParent(v * 2 + 1, b))
                v = v * 2 + 1;
            else
                break;
        }
        return v;
    };
    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll v, u, c;
            cin >> v >> u >> c;
            add(v, c);
            add(u, c);
            add(lca(v, u), -c * 2);
        } else {
            ll v, u;
            cin >> v >> u;
            cout << get(v) + get(u) - 2 * get(lca(v, u)) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}