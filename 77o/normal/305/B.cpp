#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
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
    ll p, q;
    cin >> p >> q;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (a.back() == 1 && a.size() >= 2) {
        a.pop_back();
        a.back() += 1;
    }

    vector<ll> b;
    while (q) {
        b.push_back(p / q);
        tie(p, q) = tuple(q, p % q);
    }
    if (a == b)
        cout << "YES\n";
    else
        cout << "NO\n";
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