#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int p = 1;
    while (p * p < n) {
        ++p;
    }
    if (int r = n - (p - 1) * (p - 1); r <= p) {
        std::cout << r << " " << p << "\n";
    } else {
        std::cout << p << " " << 2 * p - r << "\n";
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