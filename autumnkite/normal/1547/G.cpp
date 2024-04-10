#include <bits/stdc++.h>

class graph {
    int n;
    std::vector<std::vector<int>> E;

    int idx;
    std::vector<int> dfn, low;
    std::vector<int> sta;
    std::vector<bool> vis;

    int cnt;
    std::vector<int> bel;

    void tarjan(int u) {
        dfn[u] = low[u] = idx++;
        sta.push_back(u);
        vis[u] = true;
        for (int v : E[u]) {
            if (dfn[v] == -1) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            } else if (vis[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int v;
            do {
                v = sta.back();
                vis[v] = false;
                bel[v] = cnt;
                sta.pop_back();
            } while (v != u);
            ++cnt;
        }
    }

    std::vector<std::vector<int>> G;
    std::vector<int> deg;
    std::vector<int> ec;

public:
    graph(const std::vector<std::vector<int>> &_E)
    : n(_E.size()), E(_E), idx(0), dfn(n, -1), low(n), vis(n), cnt(0), bel(n) {
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                tarjan(i);
            }
        }
        G.resize(cnt);
        ec.resize(cnt);
        deg.resize(cnt);
        for (int u = 0; u < n; ++u) {
            for (int v : E[u]) {
                if (bel[u] != bel[v]) {
                    G[bel[u]].push_back(bel[v]);
                    ++deg[bel[v]];
                } else {
                    ++ec[bel[u]];
                }
            }
        }
    }

    std::vector<int> get_ans(int s) const {
        s = bel[s];
        std::vector<int> f(cnt);
        f[s] = ec[s] ? -1 : 1;
        std::vector<int> d(deg);
        std::vector<int> Q;
        for (int i = 0; i < cnt; ++i) {
            if (!d[i]) {
                Q.push_back(i);
            }
        }
        for (int i = 0; i < (int)Q.size(); ++i) {
            int u = Q[i];
            for (int v : G[u]) {
                --d[v];
                if (f[u]) {
                    if (f[u] == -1 || f[v] == -1 || ec[v]) {
                        f[v] = -1;
                    } else {
                        f[v] = std::min(f[u] + f[v], 2);
                    }
                }
                if (!d[v]) {
                    Q.push_back(v);
                }
            }
        }
        std::vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = f[bel[i]];
        }
        return ans;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
    }
    graph G(E);
    auto ans = G.get_ans(0);
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}