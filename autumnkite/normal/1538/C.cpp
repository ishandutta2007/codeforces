#include <bits/stdc++.h>

void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int pl = std::lower_bound(a.begin(), a.end(), l - a[i]) - a.begin();
        int pr = std::upper_bound(a.begin(), a.end(), r - a[i]) - a.begin();
        ans += pr - pl;
        ans -= l <= 2 * a[i] && 2 * a[i] <= r;
    }
    std::cout << ans / 2 << "\n";
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