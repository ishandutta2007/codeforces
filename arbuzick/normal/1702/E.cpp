#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        a[i].first--, a[i].second--;
        pos[a[i].first].push_back(i);
        pos[a[i].second].push_back(i);
    }
    vector<int> col(n, -1);
    queue<int> q;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(i);
    }
    while (!s.empty() || !q.empty()) {
        int v;
        if (!q.empty()) {
            v = q.front();
            q.pop();
        } else {
            v = *s.begin();
            s.erase(s.begin());
        }
        if (col[v] == -1) {
            col[v] = 0;
        }
        for (auto u : pos[a[v].first]) {
            if (col[u] == -1) {
                col[u] = col[v] ^ 1;
                s.erase(u);
                q.push(u);
            }
        }
        pos[a[v].first].clear();
        for (auto u : pos[a[v].second]) {
            if (col[u] == -1) {
                col[u] = col[v] ^ 1;
                s.erase(u);
                q.push(u);
            }
        }
        pos[a[v].second].clear();
    }
    set<int> used;
    for (int i = 0; i < n; ++i) {
        if (col[i] == 0) {
            if (used.count(a[i].first)) {
                cout << "NO\n";
                return;
            }
            used.insert(a[i].first);
            if (used.count(a[i].second)) {
                cout << "NO\n";
                return;
            }
            used.insert(a[i].second);
        }
    }
    used.clear();
    for (int i = 0; i < n; ++i) {
        if (col[i] == 1) {
            if (used.count(a[i].first)) {
                cout << "NO\n";
                return;
            }
            used.insert(a[i].first);
            if (used.count(a[i].second)) {
                cout << "NO\n";
                return;
            }
            used.insert(a[i].second);
        }
    }
    cout << "YES\n";
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