#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> f(n + 1), g(n + 1, -1);
    std::vector<int> fa(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> fa[i];
        --fa[i];
        for (int u = i; u != 0; u = fa[u]) {
            int tmp = f[fa[u]];
            if (f[u] > g[fa[u]]) {
                f[fa[u]] = g[fa[u]] = f[u];
            } else if (f[u] == g[fa[u]]) {
                f[fa[u]] = f[u] + 1;
            }
            if (f[fa[u]] == tmp) {
                break;
            }
        }
        std::cout << g[0] + 1 << " \n"[i == n];
    }
}