#include <bits/stdc++.h>

const long long INF = std::numeric_limits<long long>::max();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    long long sum = std::accumulate(a.begin(), a.end(), 0ll);

    int q;
    std::cin >> q;
    while (q--) {
        long long x, y;
        std::cin >> x >> y;
        int p = std::lower_bound(a.begin(), a.end(), x) - a.begin();
        long long ans = INF;
        if (p < n) {
            ans = std::min(ans, std::max(y - (sum - a[p]), 0ll));
        }
        if (p > 0) {
            ans = std::min(ans, x - a[p - 1] + std::max(y - (sum - a[p - 1]), 0ll));
        }
        std::cout << ans << "\n";
    }
}