#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        int mx = 0;
        for (int j = 0; j < k; ++j) {
            int x;
            std::cin >> x;
            mx = std::max(mx, x - j + 1);
        }
        a[i].first = mx, a[i].second = k;
    }
    std::sort(a.begin(), a.end());
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, a[i].first - sum);
        sum += a[i].second;
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