#include <bits/stdc++.h>

void solve() {
    long long a, b;
    std::cin >> a >> b;
    if (a == b) {
        std::cout << 0 << " " << 0 << "\n";
        return;
    }
    long long g = std::abs(a - b);
    std::cout << g << " " << std::min(a % g, g - a % g) << "\n";
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