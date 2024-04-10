#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        sum += x;
    }
    sum %= n;
    std::cout << sum * (n - sum) << "\n";
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