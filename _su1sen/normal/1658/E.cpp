#include <iostream>
#include <optional>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector a(n, std::vector<int>(n));
    std::vector<int> inv(n * n);
    std::vector<int8_t> erased(n * n, false);
    std::vector<int8_t> ans(n * n, false);

    auto erase = [&](int u, int v) {
        if ((u ^ v) & 1) return;
        int i = (u + v) >> 1, j = (u - v) >> 1;
        if (i < 0 or i >= n or j < 0 or j >= n) return;
        erased[a[i][j]] = true;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
            --a[i][j];
            inv[a[i][j]] = i * n + j;
        }
    }

    int min_u = 0, max_u = 2 * (n - 1);
    int min_v = -(n - 1), max_v = +(n - 1);
    for (int val = n * n; val --> 0;) {
        if (erased[val]) continue;
        erased[val] = true;
        ans[val] = true;

        int ij = inv[val];
        int i = ij / n, j = ij % n;
        int cu = i + j, cv = i - j;

        for (int u = min_u; u <= cu - k - 1; ++u) for (int v = min_v; v <= max_v; ++v) {
            erase(u, v);
        }
        for (int u = cu + k + 1; u <= max_u; ++u) for (int v = min_v; v <= max_v; ++v) {
            erase(u, v);
        }
        for (int v = min_v; v <= cv - k - 1; ++v) for (int u = min_u; u <= max_u; ++u) {
            erase(u, v);
        }
        for (int v = cv + k + 1; v <= max_v; ++v) for (int u = min_u; u <= max_u; ++u) {
            erase(u, v);
        }
        min_u = std::max(min_u, cu - k);
        max_u = std::min(max_u, cu + k);
        min_v = std::max(min_v, cv - k);
        max_v = std::min(max_v, cv + k);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << (ans[a[i][j]] ? 'M' : 'G');
        }
        std::cout << '\n';
    }

    return 0;
}