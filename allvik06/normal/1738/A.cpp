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
const int INF = 1e15;

inline void solve() {
    int n;
    cin >> n;
    vector <vector <int>> all(2);
    vector <int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        all[t[i]].push_back(y);
    }
    sort(all[0].rbegin(), all[0].rend());
    sort(all[1].rbegin(), all[1].rend());
    if ((int)all[0].size() == (int)all[1].size()) {
        int ans = 0, mn = INF;
        for (int i : all[0]) {
            ans += i;
            mn = min(mn, i);
        }
        for (int i : all[1]) {
            ans += i;
            mn = min(mn, i);
        }
        cout << 2 * ans - mn << "\n";
        return;
    }
    if ((int)all[0].size() > (int)all[1].size()) swap(all[0], all[1]);
    int ans = 0;
    for (int i : all[0]) ans += 2 * i;
    for (int i = 0; i < (int)all[1].size(); ++i) {
        if (i < (int)all[0].size()) ans += 2 * all[1][i];
        else ans += all[1][i];
    }
    cout << ans << "\n";
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