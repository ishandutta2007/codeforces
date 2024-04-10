//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

using namespace std;
#define int long long
const int mod = 998244353;

inline void solve() {
    int n, s;
    cin >> n >> s;
    vector <int> a(n), posa(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; --a[i];
        posa[a[i]] = i;
    }
    vector <int> b(n), posb(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> b[i]; --b[i];
        if (b[i] >= 0) posb[b[i]] = i;
    }
    int ans = 1, now = 0;
    for (int i = 0; i < s; ++i) now += (b[posa[i]] == -2);
    for (int i = 0; i < n; ++i) {
        int p = posb[i];
        if (i + s < n) now += (b[posa[i + s]] == -2);
        if (p >= 0) {
            if (a[p] > i + s) {
                cout << "0\n";
                return;
            }
        } else {
            ans = ans * now % mod;
            --now;
        }
    }
    cout << ans << "\n";
}

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*

 */