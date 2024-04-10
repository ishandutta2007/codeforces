#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    map<int, vector<int>> bad;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        bad[x].push_back(y);
        bad[y].push_back(x);
    }
    vector<vector<int>> vec(n + 1);
    for (auto [v, c] : mp) {
        vec[c].push_back(v);
        bad[v].push_back(v);
    }
    ll best = 0;
    for (int cntx = 1; cntx <= n; cntx++) {
        if (vec[cntx].empty())
            continue;
        map<int, int> cand;
        for (int i = vec[cntx].size() - 1; i >= 0; i--) {
            for (int y : bad[vec[cntx][i]])
                if (i + 1 == vec[cntx].size()) {
                    cand[y] = i - 1;
                } else if (cand.count(y) && cand[y] == i) {
                    cand[y] = i - 1;
                }
        }
        for (auto [y, cnty] : mp) {
            int id = -1;
            if (cand.count(y))
                id = cand[y];
            else
                id = vec[cntx].size() - 1;
            // if (id >= 0 && vec[cntx][id] == y)
            //     id--;
            if (id >= 0) {
                best = max(best, (0LL + cntx + cnty) * (vec[cntx][id] + y));
            }
        }
    }
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}