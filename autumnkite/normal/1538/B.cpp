#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int sum = std::accumulate(a.begin(), a.end(), 0);
    if (sum % n != 0) {
        std::cout << -1 << "\n";
    } else {
        sum /= n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += a[i] > sum;
        }
        std::cout << ans << "\n";
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