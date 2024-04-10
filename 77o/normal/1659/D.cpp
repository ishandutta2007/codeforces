#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll tot = accumulate(a.begin(), a.end(), 0LL);
    tot /= n;
    vector<ll> mem(n);
    vector<ll> b(n);
    ll diff = 0;
    for (ll i = n - 1; i >= 0 && tot; i--) {
        diff = diff - 1 + mem[i];
        if (i - tot >= 0)
            mem[i - tot]++;
        if (a[i] + diff > 0 || i == 0) {
            b[i] = 1;
            tot--;
        }
    }
    for (ll i = 0; i < n; i++)
        cout << b[i] << " \n"[i + 1 == n];
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