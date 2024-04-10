#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m[2];
    cin >> n >> m[0] >> m[1];
    vector<vector<int>> par(2, vector<int>(n, -1));

    auto root = [&](int x, int id) {
        if (par[id][x] == -1) par[id][x] = x;
        while (par[id][x] != x)
            x = par[id][x] = par[id][par[id][x]];
        return x;
    };
    
    vector<set<int>> active(2);
    vector<vector<vector<int>>> comp(2, vector<vector<int>>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            active[i].insert(j);
            comp[i][j].push_back(j);
        }
    }

    auto merge = [&](int x, int y, int id) {
        x = root(x, id);
        y = root(y, id);
        if (x == y) return false;
        if (comp[id][x].size() > comp[id][y].size()) swap(x, y);
        active[id].erase(x);
        for (int e : comp[id][x]) 
            comp[id][y].push_back(e);
        comp[id][x].clear();
        par[id][x] = y;
        return true;
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m[i]; j++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            merge(u, v, i);
        }
    }
    vector<pair<int, int>> res;
    while (true) {
        if (active[0].size() == 1 || active[1].size() == 1) break;
        vector<vector<int>> check(2);
        for (int i = 0; i < 2; i++) {
            int cnt = 0;
            for (auto it = active[i].begin(); cnt < 2; it++, cnt++) {
                int u = *it;
                check[i].push_back(comp[i][u][0]);
            }
        }
        bool found = false;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int ii = 0; ii < 2; ii++) {
                    for (int jj = 0; jj < 2; jj++) {
                        if (i == ii && j == jj) continue;
                        int u = check[i][j];
                        int v = check[ii][jj];
                        if (root(u, 1) != root(v, 1) && root(u, 0) != root(v, 0)) {
                            res.emplace_back(u, v);
                            merge(u, v, 0);
                            merge(u, v, 1);
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }
                if (found) break;
            }
            if (found) break;
        }
        assert(found == true);
    }
    cout << res.size() << '\n';
    for (auto e : res) 
        cout << e.first + 1 << ' ' << e.second + 1 << '\n'; 

    return 0;
}