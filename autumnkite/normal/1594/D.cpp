#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> E(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::string s;
        std::cin >> u >> v >> s;
        --u, --v;
        E[u].emplace_back(v, s == "imposter");
        E[v].emplace_back(u, s == "imposter");
    }

    std::vector<int> col(n, -1);

    int cnt[2];

    auto dfs = [&](auto &self, int u, int c) -> bool {
        if (col[u] != -1) {
            return col[u] == c;
        }
        col[u] = c;
        ++cnt[c];
        for (auto [v, w] : E[u]) {
            if (!self(self, v, c ^ w)) {
                return false;
            }
        }
        return true;
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            cnt[0] = cnt[1] = 0;
            if (!dfs(dfs, i, 0)) {
                std::cout << -1 << "\n";
                return;
            }
            ans += std::max(cnt[0], cnt[1]);
        }
    }
    std::cout << ans << "\n";
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