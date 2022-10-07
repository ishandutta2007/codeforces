#include <bits/stdc++.h>

void solve() {
    long long n;
    std::cin >> n;
    if (n <= 6) {
        std::cout << 15 << "\n";
    } else if (n <= 8) {
        std::cout << 20 << "\n";
    } else if (n <= 10) {
        std::cout << 25 << "\n";
    } else {
        int t = (n - 10) % 10 + 10;
        if (t & 1) {
            ++t;
        }
        std::cout << (n - 10) / 10 * 25 + t / 2 * 5 << "\n";
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