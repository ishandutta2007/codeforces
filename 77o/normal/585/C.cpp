#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
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
    ll x, y;
    cin >> x >> y;
    string ans;
    stringstream ss(ans);
    while (x > 1 || y > 1) {
        if (x == y) {
            cout << "Impossible\n";
            return;
        }
        if (x > y) {
            ss << (x - 1) / y;
            ss << 'A';
            x -= (x - 1) / y * y;
        } else {
            ss << (y - 1) / x;
            ss << 'B';
            y -= (y - 1) / x * x;
        }
    }
    cout << ss.str() << '\n';
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