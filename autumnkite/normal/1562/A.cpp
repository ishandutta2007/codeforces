#include <bits/stdc++.h>

void solve() {
    int l, r;
    std::cin >> l >> r;
    if (r / 2 + 1 >= l) {
        std::cout << r % (r / 2 + 1) << "\n";
    } else {
        std::cout << r - l << "\n";
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