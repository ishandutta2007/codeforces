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
const int INF = 1e9;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    string all[n];
    for (int i = 0; i < n; ++i) cin >> all[i];
    vector <int> cnt(2 * n + 1), val(m), p(m);
    int ans = 0, ans_mask = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < m; ++i) val[i] = n;
        for (int i = 0; i <= 2 * n; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (all[i][j] == '1') {
                    if ((mask >> i) & 1) ++val[j];
                    else --val[j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            ++cnt[val[i]];
        }
        for (int i = 1; i <= 2 * n; ++i) cnt[i] += cnt[i - 1];
        for (int i = 0; i < m; ++i) {
            p[i] = cnt[val[i]]--;
        }
        int now = 0;
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = 0; j < m; ++j) {
                if (all[i][j] == '1') cur += p[j];
            }
            now += abs(cur - x[i]);
        }
        if (ans < now) {
            ans = now;
            ans_mask = mask;
        }
    }
    for (int i = 0; i < m; ++i) val[i] = n;
    for (int i = 0; i <= 2 * n; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (all[i][j] == '1') {
                if ((ans_mask >> i) & 1) ++val[j];
                else --val[j];
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        ++cnt[val[i]];
    }
    for (int i = 1; i <= 2 * n; ++i) cnt[i] += cnt[i - 1];
    for (int i = 0; i < m; ++i) {
        p[i] = cnt[val[i]]--;
    }
    for (int i : p) cout << i << " ";
    cout << "\n";
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