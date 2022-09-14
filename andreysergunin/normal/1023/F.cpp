#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 500500;

int p[MAXN], weight[MAXN];

int get(int v) {
    if (p[v] == v) {
        return v;
    }
    return p[v] = get(p[v]);
}

bool unite(int v, int u) {
    v = get(v);
    u = get(u);
    if (u == v) {
        return false;
    }
    if (weight[u] < weight[v]) {
        swap(u, v);
    }
    p[v] = u;
    weight[u] += weight[v];
    return true;
}

vector<int> g[MAXN];
int vis[MAXN];
int up[MAXN][20];
int tin[MAXN], tout[MAXN], depth[MAXN];
int timer = 0;

void dfs(int v, int p = -1) {
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    tin[v] = ++timer;
    for (int i = 0; i < 20; ++i) {
        up[v][i] = -1;
    }
    up[v][0] = p;
    for (int i = 1; i < 20; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
        if (up[v][i] == -1) {
            break;
        }
    }

    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
    }
    tout[v] = ++timer;
}

bool anc(int v, int u) {
    return (tin[v] <= tin[u] && tout[u] <= tout[v]);
}

int lca(int v, int u) {
    if (anc(v, u)) {
        return v;
    }
    for (int i = 19; i >= 0; --i) {
        if (up[v][i] != -1 && !anc(up[v][i], u)) {
            v = up[v][i];
        }
    }
    return up[v][0];
}

set<pair<int, int>> setik;

bool unite1(int v, int u) {
    v = get(v);
    u = get(u);
    if (u == v) {
        return false;
    }
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    p[v] = u;
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, k, m;
    cin >> n >> k >> m;

    vector<pair<int, int>> e(k + m);
    vector<int> w(k + m);

    for (int i = 0; i < k; ++i) {
        cin >> e[i].first >> e[i].second;
        --e[i].first; --e[i].second;
    }

    for (int i = k; i < k + m; ++i) {
        cin >> e[i].first >> e[i].second;
        --e[i].first; --e[i].second;
        cin >> w[i];
    }

    vector<int> used(k + m);

    for (int i = 0; i < k; ++i) {
        int u = e[i].first, v = e[i].second;
        if (u > v) {
            swap(u, v);
        }
        setik.insert({u, v});
    }

    for (int i = 0; i < n; ++i) {
        weight[i] = 1;
        p[i] = i;
    }

    for (int i = 0; i < k + m; ++i) {
        if (unite(e[i].first, e[i].second)) {
            used[i] = true;
            int u = e[i].first, v = e[i].second;
            g[u].push_back(v);
            g[v].push_back(u);
            // cout << u << " " << v << endl;
        }
    }

    dfs(0);

    ll res = 0;

    for (int i = 0; i < n; ++i) {
        weight[i] = 1;
        p[i] = i;
    }

    for (int i = 0; i < k + m; ++i) {
        if (!used[i]) {
            int u = get(e[i].first), v = get(e[i].second);
            int t = lca(u, v);
            // cout << u << " " << v << " " << t << endl;

            while (!anc(u, t)) {
                int x = min(u, up[u][0]);
                int y = max(u, up[u][0]);
                if (setik.count({x, y})) {
                    res += w[i];
                    setik.erase({x, y});
                }
                unite1(u, up[u][0]);
                u = get(u);
            }

            u = v;

            while (!anc(u, t)) {
                int x = min(u, up[u][0]);
                int y = max(u, up[u][0]);
                if (setik.count({x, y})) {
                    res += w[i];
                    setik.erase({x, y});
                }
                unite1(u, up[u][0]);
                u = get(u);
            }
        }
    }

    if (!setik.empty()) {
        res = -1;
    }

    cout << res << endl;

    
}