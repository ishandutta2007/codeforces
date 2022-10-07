#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::vector<std::tuple<int, int, int>> ans;
        for (int i = 0; i < n; ++i) {
            int p = std::min_element(a.begin() + i, a.end()) - a.begin();
            std::rotate(a.begin() + i, a.begin() + p, a.end());
            if (p > i) {
                ans.emplace_back(i + 1, n, p - i);
            }
        }
        std::cout << ans.size() << "\n";
        for (auto [l, r, d] : ans) {
            std::cout << l << " " << r << " " << d << "\n";
        }
    }
}