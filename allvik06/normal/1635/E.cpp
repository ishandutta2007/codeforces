#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cassert>
#include <array>

using namespace std;
vector <vector <int>> g;
vector <int> used;

void dfs(int v) {
    for (int i : g[v]) {
        if (used[i] == 2) {
            used[i] = (used[v] ^ 1);
            dfs(i);
        } else if (used[i] == used[v]) {
            cout << "NO";
            exit(0);
        }
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m;
    cin >> n >> m;
    vector <array <int, 3>> all(m);
    g.resize(n);
    used.resize(n, 2);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> all[i][j];
            if (j > 0) --all[i][j];
        }
        g[all[i][1]].push_back(all[i][2]);
        g[all[i][2]].push_back(all[i][1]);
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == 2) {
            used[i] = 0;
            dfs(i);
        }
    }
    vector <set <int>> all_o(n), all_i(n);
    for (int i = 0; i < m; ++i) {
        if (all[i][0] == 1) {
            if (used[all[i][1]] == 0) {
                all_o[all[i][2]].insert(all[i][1]);
                all_i[all[i][1]].insert(all[i][2]);
            }
            else {
                all_o[all[i][1]].insert(all[i][2]);
                all_i[all[i][2]].insert(all[i][1]);
            }
        } else {
            if (used[all[i][1]] == 1) {
                all_o[all[i][2]].insert(all[i][1]);
                all_i[all[i][1]].insert(all[i][2]);
            }
            else {
                all_o[all[i][1]].insert(all[i][2]);
                all_i[all[i][2]].insert(all[i][1]);
            }
        }
    }
    set <pair <int, int>> s;
    for (int i = 0; i < n; ++i) {
        s.insert(make_pair((int)all_o[i].size(), i));
    }
    int cur = 0;
    vector <int> x(n);
    while (!s.empty()) {
        pair <int, int> now = *s.begin();
        s.erase(s.begin());
        if (now.first > 0) {
            cout << "NO";
            return 0;
        }
        x[now.second] = cur;
        ++cur;
        for (int i : all_i[now.second]) {
            s.erase(make_pair(all_o[i].size(), i));
            all_o[i].erase(now.second);
            s.insert(make_pair(all_o[i].size(), i));
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) cout << "L ";
        else cout << "R ";
        cout << x[i] << "\n";
    }
}

/*

 */