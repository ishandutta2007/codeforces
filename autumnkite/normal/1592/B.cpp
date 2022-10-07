#include <bits/stdc++.h>

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> b(a);
    std::sort(b.begin(), b.end());
    for (int i = n - x; i < x; ++i) {
        if (b[i] != a[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
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