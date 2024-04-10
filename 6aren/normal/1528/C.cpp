#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

vector<int> g[2][N];
int l[2][N], r[2][N];
int timer = 0, n;
set<pair<int, int>> s;
int res = 0;

void dfs(int id, int u) {
    l[id][u] = ++timer;
    for (int e : g[id][u]) {
        dfs(id, e);
    }
    r[id][u] = timer;
}

void solve(int u) {
    pair<int, int> erased = {-1, -1};
    auto it = s.lower_bound({l[1][u], 0});
    if (!s.empty() && it != s.begin()) {
        it--;
        if (it->second >= r[1][u]) {
            erased = *it;
            // cout << erased.first << ' ' << erased.second << endl;
            s.erase(it);
        }
    }
    s.insert({l[1][u], r[1][u]});
    res = max<int>(res, s.size());
    for (auto e : g[0][u]) {
        solve(e);
    }
    s.erase({l[1][u], r[1][u]});
    if (erased.first != -1) s.insert(erased);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) g[i][j].clear();
            for (int j = 2; j <= n; j++) {
                int pi; cin >> pi;
                g[i][pi].push_back(j);
            }
            dfs(i, 1);
            timer = 0;
        }
        s.clear();
        res = 0;
        solve(1);
        cout << res << '\n';
    }

    return 0;
}