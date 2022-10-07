#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int x = std::min_element(a.begin(), a.end()) - a.begin();
    int y = std::max_element(a.begin(), a.end()) - a.begin();
    if (x > y) {
        std::swap(x, y);
    }
    std::cout << std::min({y + 1, n - x, x + 1 + n - y}) << "\n";
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