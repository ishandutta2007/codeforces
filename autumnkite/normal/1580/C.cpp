#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];
    }

    int B = sqrt(q);
    std::vector<int> lst(n, -1), delta(q);
    std::vector<std::vector<int>> sum(B + 1, std::vector<int>(B));
    int now = 0;
    for (int i = 0; i < q; ++i) {
        int op, k;
        std::cin >> op >> k;
        --k;
        int v, p;
        if (op == 1) {
            v = 1;
            p = i;
            lst[k] = i;
        } else {
            v = -1;
            p = lst[k];
            lst[k] = -1;
        }
        int L = a[k] + b[k];
        if (L <= B) {
            for (int j = (p + a[k]) % L, t = 0; t < b[k]; ++t, j = (j + 1) % L) {
                sum[L][j] += v;
            }
        } else {
            auto add = [&](int x, int v) {
                if (x < q) {
                    delta[x] += v;
                }
                if (x < i) {
                    now += v;
                }
            };
            for (int j = p + a[k]; j < q; j += L) {
                add(j, v);
                add(j + b[k], -v);
            }
        }
        now += delta[i];
        int ans = now;
        for (int j = 2; j <= B; ++j) {
            ans += sum[j][i % j];
        }
        std::cout << ans << "\n";
    }
}