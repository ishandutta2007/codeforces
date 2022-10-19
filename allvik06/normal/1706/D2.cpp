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

using namespace std;
const int MAXC = 1e5 + 10;

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <vector <int>> all(MAXC);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, a[i] / k);
        all[a[i] / k].push_back(i);
    }
    int ans = MAXC;
    bool ok = true;
    for (int mn = 0; mn < MAXC; ++mn) {
        ans = min(ans, mx - mn);
        for (int j : all[mn]) {
            int c = a[j] / (mn + 1);
            if (c == 0) {
                ok = false;
                break;
            }
            mx = max(mx, a[j] / c);
            all[a[j] / c].push_back(j);
        }
        vector <int>().swap(all[mn]);
        if (!ok) break;
    }
    cout << ans << "\n";
}

signed main() {
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
    } else {
        srand(1303);
        int t, cnt = 0;
        cin >> t;
        while (t--) {
            if (t % 1000000 == 0) cout << cnt << "\n";

        }
    }
}

/*

 */