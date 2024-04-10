#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), a(n), used(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        used[p[i]] = 1;
    }
    vector<int> pos(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        if (a[i] < n) {
            pos[a[i]] = i;
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        count += used[i];
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        k = max(k, (a[i] - (n - 1)) / (n - count));
    }
    vector<vector<int>> go(30, vector<int>(n));
    go[0] = p;
    for (int i = 1; i < 30; ++i) {
        for (int j = 0; j < n; ++j) {
            go[i][j] = go[i - 1][go[i - 1][j]];
        }
    }
    auto get_go = [&](int v, int len) {
        for (int i = 29; i >= 0; --i) {
            if (len & (1 << i)) {
                v = go[i][v];
            }
        }
        return v;
    };
    vector<vector<int>> kek(n);
    for (int i = 0; i < n; ++i) {
        kek[get_go(i, k)].push_back(i);
    }
    vector<int> ans(n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        if (pos[i] == -1) {
            ans[*s.begin()] = i;
            s.erase(s.begin());
        } else {
            sort(kek[pos[i]].begin(), kek[pos[i]].end());
            ans[kek[pos[i]][0]] = i;
            for (int j = 1; j < (int) kek[pos[i]].size(); ++j) {
                s.insert(kek[pos[i]][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}