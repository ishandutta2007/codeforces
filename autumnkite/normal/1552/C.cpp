#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> x(k), y(k);
    std::vector<bool> vis(2 * n);
    for (int i = 0; i < k; ++i) {
        std::cin >> x[i] >> y[i];
        --x[i], --y[i];
        vis[x[i]] = vis[y[i]] = true;
    }
    std::vector<int> p;
    for (int i = 0; i < 2 * n; ++i) {
        if (!vis[i]) {
            p.push_back(i);
        }
    }
    for (int i = 0; i < n - k; ++i) {
        x.push_back(p[i]);
        y.push_back(p[i + n - k]);
    }
    auto dist = [&](int x, int y) {
        return (y - x + 2 * n) % (2 * n);
    };
    auto check = [&](int x, int y, int z) {
        return dist(x, z) + dist(z, y) == dist(x, y);
    };
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans += check(x[i], y[i], x[j]) != check(x[i], y[i], y[j]);
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}