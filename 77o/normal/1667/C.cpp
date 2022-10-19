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
    if (n == 1) {
        cout << "1\n1 1\n";
        return;
    }
    int cnt = 2 * (n - 1) / 3 + 1;
    cout << cnt << '\n';
    int remOdd = (n - cnt) / 2;
    int remEven = (n - cnt) - remOdd;
    for (int i = 1; i < remEven * 2; i++) {
        cout << i << ' ' << remEven * 2 - i << '\n';
    }
    for (int i = remEven * 2; i < (remEven + remOdd) * 2; i++) {
        cout << i << ' ' << remEven * 4 + remOdd * 2 - 1 - i << '\n';
    }
    for (int i = (remEven + remOdd) * 2; i <= cnt; i++) {
        cout << i << ' ' << i << '\n';
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