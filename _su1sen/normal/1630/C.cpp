#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &e : a) {
        std::cin >> e;
        --e;
    }

    std::vector<std::vector<int>> bin(n);
    for (int i = 0; i < n; ++i) {
        bin[a[i]].push_back(i);
    }
    std::vector<int> rs(n, -1);
    for (int i = 0; i < n; ++i) {
        if (bin[i].size() <= 1) continue;
        int l = bin[i].front();
        int r = bin[i].back();
        rs[l] = r;
    }
    int ans = 0;
    int i = 0;
    while (i < n) {
        while (i < n and rs[i] <= i) ++i;
        if (i == n) break;
        int r = rs[i];
        ans += r - i - 1;
        for (++i; i < r; ++i) rs[r] = std::max(rs[r], rs[i]);
    }

    std::cout << ans << '\n';

    return 0;
}