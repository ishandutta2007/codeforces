#include <bits/stdc++.h>

int a0, a1, a2;
int b0, b1, b2;

void solve() {
    std::cin >> a0 >> a1 >> a2;
    std::cin >> b0 >> b1 >> b2;
    int t = std::min(a2, b1);
    a2 -= t, b1 -= t;
    std::cout << 2 * (t - std::max(0, b2 - a0 - a2)) << std::endl;
}

int main() {
    int T = 1;
    std::cin >> T;
    while (T--) {
        solve();
    }
}