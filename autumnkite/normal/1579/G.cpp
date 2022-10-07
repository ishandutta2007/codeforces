#include <bits/stdc++.h>

const int INF = std::numeric_limits<int>::max() / 2;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int m = *std::max_element(a.begin(), a.end());
    std::vector<int> f(2 * m + 1);
    for (int i = n - 1; i >= 0; --i) {
        int d = a[i];
        std::vector<int> g(2 * m + 1);
        for (int l = 0; l <= 2 * m; ++l) {
            g[l] = f[std::min(l + d, 2 * m)] + d;
            if (l >= d) {
                g[l] = std::min(g[l], std::max(f[l - d] - d, 0));
            }
        }
        f.swap(g);
    }
    int ans = INF;
    for (int i = 0; i <= 2 * m; ++i) {
        ans = std::min(ans, f[i] + i);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}