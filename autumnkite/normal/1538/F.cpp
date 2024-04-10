#include <bits/stdc++.h>

void solve() {
    long long l, r;
    std::cin >> l >> r;
    long long ans = 0;
    for (long long i = 1; i <= r; i *= 10) {
        ans += r / i - l / i;
    }
    std::cout << ans << "\n";
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