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

void solve() {
    int n;
    cin >> n;
    vector <int> x(n), t(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> t[i];
    double l = *max_element(t.begin(), t.end()) - 1e-6, r = INF;
    double ans_pos = -1;
    for (int _ = 0; _ < 100; ++_) {
        double m = (l + r) / 2;
        double l_seg = 0, r_seg = INF;
        for (int i = 0; i < n; ++i) {
            double l_now = x[i] - (m - t[i]);
            double r_now = x[i] + (m - t[i]);
            l_seg = max(l_seg, l_now);
            r_seg = min(r_seg, r_now);
        }
        if (l_seg <= r_seg) {
            r = m;
            ans_pos = l_seg;
        }
        else l = m;
    }
    cout << fixed << setprecision(10) << ans_pos << "\n";
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
    } else {

    }
}

/*

 */