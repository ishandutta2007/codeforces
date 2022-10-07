#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cout << std::string(i, '(') + std::string(i, ')')
                   + std::string(n - i, '(') + std::string(n - i, ')') << "\n";
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