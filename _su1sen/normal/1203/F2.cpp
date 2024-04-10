#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, r;
    std::cin >> n >> r;
    std::vector<std::pair<int, int>> pos, neg;
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        (b >= 0 ? pos : neg).emplace_back(a, b);
    }
    int ans = 0;
    std::sort(pos.begin(), pos.end());
    for (auto [a, b] : pos) {
        if (r >= a) r += b, ++ans;
    }
    std::sort(neg.begin(), neg.end(), [](auto &p1, auto &p2) {
        auto [a1, b1] = p1;
        auto [a2, b2] = p2;
        return a1 + b1 > a2 + b2;
    });
    std::vector<int> dp(r + 1, 0);
    for (auto [a, b] : neg) {
        for (int j = std::min(r - a, r + b); j >= 0; --j) {
            dp[j - b] = std::max(dp[j - b], dp[j] + 1);
        }
    }
    std::cout << ans + *std::max_element(dp.begin(), dp.end()) << std::endl;
    return 0;
}