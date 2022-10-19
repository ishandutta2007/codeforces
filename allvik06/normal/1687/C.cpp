#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            a[i] += a[i - 1] - x;
        }
        vector <pair <int, int>> all(m);
        vector <vector <int>> flex(n + 1);
        for (int i = 0; i < m; ++i) {
            cin >> all[i].first >> all[i].second; --all[i].first; --all[i].second;
            flex[all[i].first].push_back(i);
            flex[all[i].second + 1].push_back(i);
        }
        vector <int> st;
        set <int> s;
        for (int i = 0; i <= n; ++i) {
            if (a[i] == 0) st.push_back(i);
            else s.insert(i);
        }
        vector <int> cur(m);
        while (!st.empty()) {
            int i = st.back();
            st.pop_back();
            for (int j : flex[i]) {
                ++cur[j];
                if (cur[j] == 2) {
                    int l = all[j].first;
                    int r = all[j].second;
                    while (true) {
                        auto it = s.upper_bound(l);
                        if (it != s.end() && *it <= r) {
                            st.push_back(*it);
                            s.erase(it);
                        } else break;
                    }
                }
            }
        }
        if (s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}