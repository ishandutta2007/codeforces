#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < 2 * n; ++i) {
        if (i & 1) {
            std::cout << a[i / 2] << " ";
        } else {
            std::cout << a[i / 2 + n] << " ";
        }
    }
    std::cout << "\n";
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