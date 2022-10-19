#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

using namespace std;

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m;
    cin >> n >> m;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; --p[i];
    }
    vector <pair <int, int>> edges(m);
    vector <vector <pair <int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        edges[i] = make_pair(x, y);
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
    }
    vector <int> ind(n, -1), flex;
    vector <vector <int>> gg(m);
    for (int i = 0; i < n; ++i) {
        if (ind[i] != -1) continue;
        int cur = i, cnt = 0;
        flex.clear();
        while (ind[cur] == -1) {
            ind[cur] = cnt++;
            cur = p[cur];
            flex.push_back(cur);
        }
        for (int j : flex) {
            sort(g[j].begin(), g[j].end(), [&](pair <int, int> f, pair <int, int> s) {
               int l1, l2;
               if (ind[f.first] > ind[j]) l1 = ind[f.first] - ind[j];
               else l1 = ind[f.first] + cnt - ind[j];
               if (ind[s.first] > ind[j]) l2 = ind[s.first] - ind[j];
               else l2 = ind[s.first] + cnt - ind[j];
               return l1 < l2;
            });
            for (int k = 0; k < (int)g[j].size() - 1; ++k) {
                gg[g[j][k].second].push_back(g[j][k + 1].second);
            }
        }
    }
    vector <int> ord;
    vector <bool> used(m);

    function <void(int)> dfs = [&](int v) {
        used[v] = true;
        for (int i : gg[v]) {
            if (!used[i]) dfs(i);
        }
        ord.push_back(v);
    };

    for (int i = 0; i < m; ++i) {
        if (!used[i]) dfs(i);
    }
    reverse(ord.begin(), ord.end());
    for (int i : ord) cout << i + 1 << " ";
}

/*

 */