#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[n + i] = a[i];
    }
    std::vector<std::pair<int, int>> f;
    int ans = 0;
    for (int i = 2 * n - 1; i >= 0; --i) {
        for (auto &[v, p] : f) {
            v = std::__gcd(v, a[i]);
        }
        f.emplace_back(a[i], i);
        std::vector<std::pair<int, int>> g;
        for (auto [v, p] : f) {
            if (g.empty() || g.back().first != v) {
                g.emplace_back(v, p);
            } else {
                g.back().second = p;
            }
        }
        f.swap(g);
        ans = std::max(ans, f.front().second - i);
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