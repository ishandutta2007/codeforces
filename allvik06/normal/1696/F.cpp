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

struct dsu {
    int n;
    vector <int> p, sz;

    dsu(int n) : n(n) {
        p.resize(n * n);
        sz.resize(n * n, 1);
        for (int i = 0; i < n * n; ++i) p[i] = i;
    }

    inline int get_num(int x, int y) {
        return n * x + y;
    }

    int parent(int v) {
        if (p[v] == v) return v;
        p[v] = parent(p[v]);
        return p[v];
    }

    inline void unite(int x, int y) {
        x = parent(x);
        y = parent(y);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        p[x] = y;
        sz[y] += sz[x];
    }
};

vector <vector <int>> g;
vector <bool> used;

void find_d(int v, int u, int cur, int p, vector <vector <int>>& d) {
    d[u][v] = cur;
    for (int i : g[v]) {
        if (i == p) continue;
        find_d(i, u, cur + 1, v, d);
    }
}

int find_sz(int v) {
    int sz = 1;
    used[v] = true;
    for (int i : g[v]) {
        if (!used[i]) sz += find_sz(i);
    }
    return sz;
}

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        dsu now(n);
        vector <vector <string>> all(n, vector <string> (n));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cin >> all[i][j];
                for (int k = 0; k < n; ++k) {
                    if (all[i][j][k] == '1') now.unite(now.get_num(min(i, k), max(i, k)), now.get_num(min(j, k), max(j, k)));
                }
            }
        }
        vector <vector <int>> flex(n * n);
        for (int i = 0; i < n * n; ++i) {
            flex[now.parent(i)].push_back(i);
        }
        vector <vector <int>> d(n, vector <int> (n));
        bool f = false;
        vector <pair <int, int>> edges;
        for (int i = 0; i < n * n; ++i) {
            if (now.p[i] == i && now.sz[i] == n - 1) {
                g.assign(n, {});
                edges.clear();
                for (auto j : flex[i]) {
                    int x = j / n, y = j % n;
                    edges.emplace_back(x, y);
                    g[x].push_back(y);
                    g[y].push_back(x);
                }
                used.assign(n, false);
                if (find_sz(0) != n) continue;
                for (int j = 0; j < n; ++j) {
                    find_d(j, j, 0, -1, d);
                }
                bool ok = true;
                for (int j = 0; j < n; ++j) {
                    for (int z = j + 1; z < n; ++z) {
                        for (int k = 0; k < n; ++k) {
                            bool o = (all[j][z][k] == '1');
                            bool tw = (d[j][k] == d[z][k]);
                            if (o != tw) {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok) {
                            break;
                        }
                    }
                    if (!ok) break;
                }
                if (ok) {
                    cout << "Yes\n";
                    for (auto j : edges) cout << j.first + 1 << " " << j.second + 1 << "\n";
                    f = true;
                    break;
                }
            }
        }
        if (!f) cout << "No\n";
    }
}

/*

 */