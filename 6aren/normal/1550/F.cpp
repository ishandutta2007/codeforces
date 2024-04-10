#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q, s, d;

int p[N], a[N];
vector<int> cp[N];
vector<int> g[N];
int dp[N];

int dis(int u, int v) {
    int foo = abs(a[u] - a[v]);
    return abs(foo - d);
}

void dfs(int u, int p, int best = 0) {
    dp[u] = best;
    for (int e : g[u]) {
        if (e == p) continue;
        dfs(e, u, max(best, dis(e, u)));
    }
}


int root(int x) {
    return p[x] == x ? x : p[x] = root(p[x]);
}

bool merge(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (cp[u].size() > cp[v].size()) swap(u, v);
    p[u] = v;
    for (int e : cp[u]) cp[v].push_back(e);
    cp[u].clear();
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q >> s >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<pair<int, int>> edges;

    while (edges.size() != n - 1) {
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            cp[i] = {i};
        }
        for (auto edge : edges) {
            merge(edge.first, edge.second);
        }
        vector<vector<int>> components;
        for (int i = 1; i <= n; i++) {
            if (p[i] == i) components.push_back(cp[i]);
        }
        int n_comp = components.size();
        set<pair<int, int>> ori, added;
        for (int i = 0; i < n_comp; i++) {
            for (int e : components[i]) {
                ori.insert({a[e], e});
                added.insert({a[e] + d, e});
            }
        }
        vector<pair<int, int>> best(n_comp);
        for (int i = 0; i < n_comp; i++) {
            int mn = 2e9;
            pair<int, int> id = {-1, -1};
            {
                for (int e : components[i]) {
                    ori.erase({a[e], e});
                }
                for (int e : components[i]) {
                    int val = a[e] + d;
                    auto it = ori.lower_bound(make_pair(val, 0));
                    if (it != ori.end()) {
                        if (abs(it->first - val) < mn) {
                            mn = abs(it->first - val);
                            id = {e, it->second};
                        }
                    }
                    if (it != ori.begin()) {
                        it--;
                        if (abs(it->first - val) < mn) {
                            mn = abs(it->first - val);
                            id = {e, it->second};
                        }
                    }
                }
                for (int e : components[i]) {
                    ori.insert({a[e], e});
                }
            }
            {
                for (int e : components[i]) {
                    added.erase({a[e] + d, e});
                }
                for (int e : components[i]) {
                    int val = a[e];
                    auto it = added.lower_bound(make_pair(val, 0));
                    if (it != added.end()) {
                        if (abs(it->first - val) < mn) {
                            mn = abs(it->first - val);
                            id = {e, it->second};
                        }
                    }
                    if (it != added.begin()) {
                        it--;
                        if (abs(it->first - val) < mn) {
                            mn = abs(it->first - val);
                            id = {e, it->second};
                        }
                    }
                }
                for (int e : components[i]) {
                    added.insert({a[e] + d, e});
                }
            }
            best[i] = id;
        }
        for (int i = 0; i < n_comp; i++) {
            if (best[i].first == -1) continue;
            if (merge(best[i].first, best[i].second)) edges.push_back(best[i]);
        }
    }

    for (auto e : edges) {
        g[e.first].push_back(e.second);
        g[e.second].push_back(e.first);
    }

    dfs(s, 0);

    while (q--) {
        int i, k;
        cin >> i >> k;
        cout << (dp[i] <= k ? "YES\n" : "NO\n");
    }

    return 0;
}