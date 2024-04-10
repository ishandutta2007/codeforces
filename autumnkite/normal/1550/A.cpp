#include <bits/stdc++.h>

void solve() {
    int sum;
    std::cin >> sum;
    int p = 1;
    int now = 1;
    while (now < sum) {
        p += 2;
        now += p;
    }
    std::cout << (p + 1) / 2 << "\n";
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