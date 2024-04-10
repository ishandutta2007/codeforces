#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i]--;
    }
    set<pair<int, int>> s;
    vector<int> t(n);
    vector<vector<int>> tasks(n);
    for (int i = 0; i < m; ++i) {
        tasks[a[i]].push_back(i);
    }
    int l = 0, r = m * 2;
    while (l < r - 1) {
        int md = (l + r) / 2;
        int cnt = 0;
        bool ch = true;
        vector<int> used(n);
        for (int i = 0; i < n; ++i) {
            if (tasks[i].size() > md + cnt) {
                continue;
            } else if (tasks[i].size() > md) {
                used[i] = 1;
                cnt -= ((int)tasks[i].size() - md);
            } else {
                used[i] = 1;
                cnt += (md - (int)tasks[i].size()) / 2;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i] && tasks[i].size() > md + cnt) {
                ch = false;
                break;
            } else if (!used[i]) {
                if (tasks[i].size() > md) {
                    cnt -= ((int)tasks[i].size() - md);
                } else {
                    cnt += (md - (int)tasks[i].size()) / 2;
                }
            }
        }
        if (ch) {
            r = md;
        } else {
            l = md;
        }
    }
    cout << r << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}