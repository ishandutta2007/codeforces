#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    std::cin >> q;
    std::vector<int> a(q + 1), c(q + 1);
    int LG = std::__lg(q + 1) + 1;
    std::vector<std::vector<int>> fa(q + 1, std::vector<int>(LG, -1));
    std::cin >> a[0] >> c[0];
    for (int i = 1; i <= q; ++i) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int p;
            std::cin >> p;
            std::cin >> a[i] >> c[i];
            fa[i][0] = p;
            for (int j = 1; j < LG && fa[i][j - 1] != -1; ++j) {
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
            }
        } else {
            int x;
            std::cin >> x;
            int w;
            std::cin >> w;
            int u = x, k = 0;
            for (int j = LG - 1; j >= 0; --j) {
                if (fa[u][j] != -1 && a[fa[u][j]]) {
                    u = fa[u][j];
                    k += 1 << j;
                }
            }
            int now = 0;
            long long ans = 0;
            while (now < w && k >= 0) {
                int u = x;
                for (int j = 0; (1 << j) <= k; ++j) {
                    if (k >> j & 1) {
                        u = fa[u][j];
                    }
                }
                if (now + a[u] <= w) {
                    now += a[u];
                    ans += 1ll * a[u] * c[u];
                    a[u] = 0;
                    --k;
                } else {
                    ans += 1ll * (w - now) * c[u];
                    a[u] -= w - now;
                    now = w;
                }
            }
            std::cout << now << " " << ans << std::endl;
        }
    }
}