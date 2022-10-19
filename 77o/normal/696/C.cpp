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
    int n;
    cin >> n;
    ll k = 1;
    bool isEven = true;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        a %= MOD - 1;
        isEven &= a % 2;
        k = k * a % (MOD - 1); 
    }
    k = (k - 1 + MOD - 1) % (MOD - 1);
    ll p = binpow(2, k);
    ll q = p;
    if (isEven)
        q = (p - 1 + MOD) % MOD;
    else
        q = (p + 1) % MOD;
    q = q * binpow(3, MOD - 2) % MOD;
    cout << q << '/' << p << endl;
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