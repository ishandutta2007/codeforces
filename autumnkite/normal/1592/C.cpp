#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    std::vector<int> s(n);
    
    auto build = [&](auto &self, int u, int fa) -> void {
        s[u] = a[u];
        for (int v : E[u]) {
            if (v != fa) {
                self(self, v, u);
                s[u] ^= s[v];
            }
        }
    };

    build(build, 0, -1);

    if (s[0] == 0) {
        std::cout << "YES\n";
        return;
    }

    if (k == 2) {
        std::cout << "NO\n";
        return;
    }

    std::vector<int> ex(n);
    
    auto dfs = [&](auto &self, int u, int fa) -> bool {
        ex[u] = 0;
        for (int v : E[u]) {
            if (v != fa) {
                if (self(self, v, u)) {
                    return true;
                }
                if (ex[u] && ex[v]) {
                    return true;
                }
                ex[u] |= ex[v];
            }
        }
        if (s[u] == 0 && ex[u]) {
            return true;
        }
        ex[u] |= s[u] == s[0];
        return false;
    };

    if (dfs(dfs, 0, -1)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}