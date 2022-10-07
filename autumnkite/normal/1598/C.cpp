#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    long long sum = std::accumulate(a.begin(), a.end(), 0ll);

    if ((2 * sum) % n != 0) {
        std::cout << 0 << "\n";
        return;
    }

    sum = 2 * sum / n;
    std::map<int, int> mp;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += mp[sum - a[i]];
        ++mp[a[i]];
    }
    std::cout << ans << "\n";
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