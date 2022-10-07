#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> E(1 << n);
        for (int i = 0; i < n * (1 << (n - 1)); ++i) {
            int u, v;
            std::cin >> u >> v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        std::vector<int> dep(1 << n, -1);
        std::vector<int> Q;
        Q.push_back(0);
        dep[0] = 0;
        for (int i = 0; i < (int)Q.size(); ++i) {
            int u = Q[i];
            for (int v : E[u]) {
                if (dep[v] == -1) {
                    Q.push_back(v);
                    dep[v] = dep[u] + 1;
                }
            }
        }
        std::vector<int> p(1 << n);
        p[0] = 0;
        for (int i = 0; i < n; ++i) {
            p[E[0][i]] = 1 << i;
        }
        for (int u : Q) {
            for (int v : E[u]) {
                if (dep[v] == dep[u] + 1) {
                    p[v] |= p[u];
                }
            }
        }
        std::vector<int> ans(1 << n);
        for (int i = 0; i < (1 << n); ++i) {
            ans[p[i]] = i;
        }

        for (int i = 0; i < (1 << n); ++i) {
            std::cout << ans[i] << " ";
        }
        std::cout << "\n";

        if ((n & -n) != n) {
            std::cout << -1 << "\n";
            continue;
        }

        for (int i = 0; i < (1 << n); ++i) {
            int c = 0;
            for (int j = 0; j < n; ++j) {
                if (p[i] >> j & 1) {
                    c ^= j;
                }
            }
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
}