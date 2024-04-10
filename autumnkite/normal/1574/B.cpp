#include <bits/stdc++.h>

void solve() {
    int a[3], m;
    std::cin >> a[0] >> a[1] >> a[2] >> m;
    std::sort(a, a + 3);
    int L = 0, R = a[0] + a[1] + a[2] - 3;
    if (a[2] > a[0] + a[1]) {
        L = a[2] - a[0] - a[1] - 1;
    }
    if (L <= m && m <= R) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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