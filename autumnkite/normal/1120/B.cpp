#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = t[i] - s[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        a[i + 1] -= a[i];
    }
    if (a[n - 1]) {
        std::cout << -1 << "\n";
        return 0;
    }
    std::cout << std::accumulate(a.begin(), a.end(), 0ll,
    [&](long long s, int x) {
        return s + abs(x);
    }) << "\n";

    int tot = 100000;

    auto dfs = [&](auto &self, int x, int d) -> void {
        if (!tot) {
            return;
        }
        if (!isdigit(s[x + 1] + d)) {
            self(self, x + 1, -d);
            if (!tot) {
                return;
            }
        }
        std::cout << x + 1 << " " << d << "\n";
        --tot;
        s[x] += d;
        s[x + 1] += d;
    };

    for (int i = 0; i < n; ++i) {
        while (s[i] < t[i]) {
            dfs(dfs, i, 1);
            if (!tot) {
                return 0;
            }
        }
        while (s[i] > t[i]) {
            dfs(dfs, i, -1);
            if (!tot) {
                return 0;
            }
        }
    }
}