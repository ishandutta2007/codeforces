#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) {
        std::cin >> x;
    }
    std::set<std::pair<int, int>> S;
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            S.emplace(a[i], i);
        }
    }
    std::vector<std::pair<int, int>> ans;
    while ((int)S.size() > 1) {
        auto x = --S.end(), y = std::prev(--S.end());
        int px = x->second, py = y->second;
        --a[px], --a[py];
        ans.emplace_back(px, py);
        S.erase(x), S.erase(y);
        if (a[px]) {
            S.emplace(a[px], px);
        }
        if (a[py]) {
            S.emplace(a[py], py);
        }
    }
    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        std::cout << x + 1 << " " << y + 1 << "\n";
    }
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