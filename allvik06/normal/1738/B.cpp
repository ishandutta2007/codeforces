#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;
#define int long long
const int INF = 1e9;

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> p(n);
    for (int i = n - k; i < n; ++i) cin >> p[i];
    vector <int> a(n);
    for (int i = n - 1; i > n - k; --i) {
        a[i] = p[i] - p[i - 1];
    }
    bool ok = true;
    for (int i = n - k + 1; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            ok = false;
        }
    }
    int mx = INF;
    if (k > 1) mx = a[n - k + 1];
    if (ok && mx * (n - k + 1) >= p[n - k]) cout << "Yes\n";
    else cout << "No\n";
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        cin >> t;
        while (t--) {
            solve();
        }
        //  while (true) {}
    }
}

/*

 */