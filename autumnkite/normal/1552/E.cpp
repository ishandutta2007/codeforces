#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    int lim = (n - 1) / (k - 1) + 1;
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n * k; ++i) {
        int v;
        std::cin >> v;
        --v;
        a[v].push_back(i);
    }
    std::vector<bool> ok(n);
    std::vector<std::pair<int, int>> ans(n);
    std::vector<int> h(n);
    int b = 0;
    while (1) {
        std::vector<std::pair<int, int>> p;
        for (int i = 0; i < n; ++i) {
            if (!ok[i]) {
                while (h[i] < k && a[i][h[i]] < b) {
                    ++h[i];
                }
                p.emplace_back(a[i][h[i] + 1], i);
            }
        }
        if (p.empty()) {
            break;
        }
        std::sort(p.begin(), p.end());
        p.resize(std::min<int>(p.size(), lim));
        for (auto [r, i] : p) {
            ok[i] = true;
            ans[i] = std::make_pair(a[i][h[i]], r);
            b = std::max(b, r + 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
}