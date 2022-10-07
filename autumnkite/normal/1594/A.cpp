#include <bits/stdc++.h>

void solve() {
    long long n;
    std::cin >> n;
    std::cout << -n + 1 << " " << n << "\n";
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