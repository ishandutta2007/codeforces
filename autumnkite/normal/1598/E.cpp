#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += 2 * std::min(n - i, m - j) - 1;
            ans += std::min(n - i - 1, m - j);
            ans += std::min(n - i, m - j - 1);
        }
    }

    auto walkLU = [&](int x, int y, int d) {
        int len = 0;
        while (x >= 0 && y >= 0 && !a[x][y]) {
            ++len;
            if (d) {
                --x;
            } else {
                --y;
            }
            d ^= 1;
        }
        return len;
    };

    auto walkRD = [&](int x, int y, int d) {
        int len = 0;
        while (x < n && y < m && !a[x][y]) {
            ++len;
            if (d) {
                ++x;
            } else {
                ++y;
            }
            d ^= 1;
        }
        return len;
    };

    while (q--) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        if (a[x][y]) {
            a[x][y] = 0;
            ans += walkLU(x, y, 0) * walkRD(x, y, 1);
            ans += walkLU(x, y, 1) * walkRD(x, y, 0);
            --ans;
        } else {
            ans -= walkLU(x, y, 0) * walkRD(x, y, 1);
            ans -= walkLU(x, y, 1) * walkRD(x, y, 0);
            ++ans;
            a[x][y] = 1;
        }
        std::cout << ans << "\n";
    }
}