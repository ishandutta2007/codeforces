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
    string s;
    cin >> s;
    int x;
    cin >> x;
    for (char& c : s)
        c = tolower(c);
    if (s == "abc") {
        if (x < 2000)
            cout << "Yes\n";
        else
            cout << "No\n";
    } else if (s == "arc") {
        if (x < 2800)
            cout << "Yes\n";
        else
            cout << "No\n";
    } else if (s == "agc") {
        if (x >= 1200)
            cout << "Yes\n";
        else
            cout << "No\n";
    } else {
        exit(1);
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