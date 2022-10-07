// 
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n, -1);
    for (int i = 1; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
    }

    int B = sqrt(n), C = (n - 2) / B + 1;
    std::vector<int> L(C), R(C), bel(n);
    bel[0] = -1;
    for (int i = 1; i < n; ++i) {
        bel[i] = (i - 1) / B;
    }
    for (int i = 0; i < C; ++i) {
        L[i] = i * B + 1;
        R[i] = std::min((i + 1) * B, n - 1);
    }

    std::vector<int> d(C);
    std::vector<bool> ok(C);
    std::vector<int> b(n);

    auto build = [&](int x) {
        ok[x] = true;
        for (int i = L[x]; i <= R[x]; ++i) {
            a[i] = std::max(a[i] - d[x], 0);
            if (a[i] < L[x]) {
                b[i] = a[i];
            } else {
                b[i] = b[a[i]];
                ok[x] = false;
            }
        }
        d[x] = 0;
        return;
    };

    for (int i = 0; i < C; ++i) {
        build(i);
    }

    auto father = [&](int x) {
        return x == 0 ? -1 : std::max(a[x] - d[bel[x]], 0);
    };

    auto jump = [&](int x) {
        return x == 0 ? -1 : (ok[bel[x]] ? father(x) : b[x]);
    };

    int now_time = 0;
    std::vector<int> vis(n), lst(n);

    auto bf_LCA = [&](int u, int v, int t) {
        t = father(t);
        ++now_time;
        for (int x = u; x != t; x = father(x)) {
            vis[x] = now_time;
        }
        for (int x = v; x != t; x = father(x)) {
            if (vis[x] == now_time) {
                return x;
            }
        }
        return 0;
    };

    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l, r, x;
            std::cin >> l >> r >> x;
            --l, --r;
            if (bel[l] < bel[r]) {
                for (int i = bel[l] + 1; i <= bel[r] - 1; ++i) {
                    d[i] = std::min(d[i] + x, n);
                    if (!ok[i]) {
                        build(i);
                    }
                }
                for (int i = l; i <= R[bel[l]]; ++i) {
                    a[i] = std::max(a[i] - x, 0);
                }
                if (!ok[bel[l]]) {
                    build(bel[l]);
                }
                for (int i = L[bel[r]]; i <= r; ++i) {
                    a[i] = std::max(a[i] - x, 0);
                }
                if (!ok[bel[r]]) {
                    build(bel[r]);
                }
            } else {
                for (int i = l; i <= r; ++i) {
                    a[i] = std::max(a[i] - x, 0);
                }
                if (!ok[bel[l]]) {
                    build(bel[l]);
                }
            }
        } else {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            ++now_time;
            for (int x = u, y = u; x != -1; x = jump(x)) {
                vis[x] = now_time;
                lst[x] = y;
                y = x;
            }
            for (int x = v, y = v; x != -1; x = jump(x)) {
                if (vis[x] == now_time) {
                    std::cout << bf_LCA(lst[x], y, x) + 1 << "\n";
                    break;
                }
                y = x;
            }
        }
    }
}