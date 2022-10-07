#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    std::vector<int> p;

    auto dfs = [&](auto &self, int u, int fa) -> void {
        p.push_back(u);
        for (int v : E[u]) {
            if (v != fa) {
                self(self, v, u);
                p.push_back(u);
            }
        }
    };

    dfs(dfs, 0, -1);

    auto query = [&](int l, int r) {
        std::vector<int> tmp;
        for (int i = l; i <= r; ++i) {
            tmp.push_back(p[i]);
        }
        std::sort(tmp.begin(), tmp.end());
        tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
        std::cout << "? " << tmp.size() << " ";
        for (int x : tmp) {
            std::cout << x + 1 << " ";
        }
        std::cout << std::endl;
        int res;
        std::cin >> res;
        return res;
    };

    int max = query(0, 2 * (n - 1));

    auto solve = [&](auto &self, int l, int r) -> void {
        if (l + 1 == r) {
            std::cout << "! " << p[l] + 1 << " " << p[r] + 1 << std::endl;
            return;
        }
        int mid = (l + r) >> 1;
        if (query(l, mid) == max) {
            self(self, l, mid);
        } else {
            self(self, mid, r);
        }
    };

    solve(solve, 0, 2 * (n - 1));
}