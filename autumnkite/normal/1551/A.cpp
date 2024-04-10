#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    if (n % 3 == 0) {
        std::cout << n / 3 << " " << n / 3 << "\n";
    } else if (n % 3 == 1) {
        std::cout << n / 3 + 1 << " " << n / 3 << "\n";
    } else {
        std::cout << n / 3 << " " << n / 3 + 1 << "\n";
    }
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