#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    std::vector<bool> vis(n);
    std::vector<int> fa(n, -1), dep(n);

    auto dfs = [&](auto &self, int u) -> void {
        vis[u] = true;
        for (int v : E[u]) {
            if (!vis[v]) {
                fa[v] = u;
                dep[v] = dep[u] + 1;
                self(self, v);
            }
        }
    };

    dfs(dfs, 0);

    int x = std::max_element(dep.begin(), dep.end()) - dep.begin();
    
    if (dep[x] >= (n - 1) / k + 1) {
        std::vector<int> ans;
        for (int u = x; u != -1; u = fa[u]) {
            ans.push_back(u);
        }
        std::cout << "PATH\n";
        std::cout << ans.size() << "\n";
        for (int x : ans) {
            std::cout << x + 1 << " ";
        }
        std::cout << "\n";
        return 0;
    }

    std::vector<bool> leaf(n, true);
    for (int i = 0; i < n; ++i) {
        if (fa[i] != -1) {
            leaf[fa[i]] = false;
        }
    }
    std::vector<std::vector<int>> cycles;
    auto add = [&](int x, int y) {
        for (int u = x; u != -1; u = fa[u]) {
            cycles.back().push_back(u);
            if (u == y) {
                break;
            }
        }
    };
    for (int u = 0; u < n && (int)cycles.size() < k; ++u) {
        if (leaf[u]) {
            cycles.emplace_back();
            std::vector<int> anc;
            for (int v : E[u]) {
                if (v != fa[u]) {
                    anc.push_back(v);
                    if ((int)anc.size() == 2) {
                        break;
                    }
                }
            }
            if (dep[anc[0]] < dep[anc[1]]) {
                std::swap(anc[0], anc[1]);
            }
            if ((dep[u] - dep[anc[0]] + 1) % 3) {
                add(u, anc[0]);
            } else if ((dep[u] - dep[anc[1]] + 1) % 3) {
                add(u, anc[1]);
            } else {
                add(anc[0], anc[1]);
                cycles.back().push_back(u);
            }
        }
    }
    std::cout << "CYCLES\n";
    for (const auto &p : cycles) {
        std::cout << p.size() << "\n";
        for (int x : p) {
            std::cout << x + 1 << " ";
        }
        std::cout << "\n";
    }
}