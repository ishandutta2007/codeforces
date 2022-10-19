#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = numeric_limits<ll>::max();
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        ll sum = 0;
        for (int j = i + 1; j < n; j++) {
            ll cnt = (cur + a[j]) / a[j];
            sum += cnt;
            cur = a[j] * cnt;
        }
        cur = 0;
        for (int j = i - 1; j >= 0; j--) {
            ll cnt = (cur - a[j]) / a[j];
            sum -= cnt;
            cur = a[j] * cnt;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
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