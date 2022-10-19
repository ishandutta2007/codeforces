#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m, ans = 0;
        cin >> n >> m;
        vector <string> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        multiset <int> flex;
        array <multiset<int>, 2> now;
        for (int i = 0; i < n + m - 1; ++i) {
            flex.clear();
            int x, y;
            if (i < m) {
                x = 0;
                y = i;
            } else {
                x = i - m + 1;
                y = m - 1;
            }
            while (x < n && y >= 0) {
                if (a[x][y] == '1') {
                    flex.insert(y - x);
                }
                ++x;
                y--;
            }
            int o = i % 2;
            while (!flex.empty()) {
                x = *flex.begin();
                auto it = now[o].lower_bound(x);
                if (it == now[o].end()) break;
                while (!flex.empty() && *flex.begin() <= *it) {
                    flex.erase(flex.begin());
                }
                now[o].erase(it);
                now[o].insert(x);
            }
            if (!flex.empty()) {
                ++ans;
                now[o].insert(*flex.begin());
            }
        }
        cout << ans << "\n";
    }
}

/*

 */