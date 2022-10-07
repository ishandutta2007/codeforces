#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end(), std::greater<int>());
    std::vector<int> sa(n + 1), sb(n + 1);
    for (int i = 0; i < n; ++i) {
        sa[i + 1] = sa[i] + a[i];
    }
    for (int i = 0; i < n; ++i) {
        sb[i + 1] = sb[i] + b[i];
    }
    auto check = [&](int x) {
        int k = x + n - (x + n) / 4;
        return 100 * std::min(k, x) + sa[k - std::min(k, x)] >= sb[std::min(k, n)];
    };
    int l = -1, r = 3 * n;
    while (l + 1 < r) {
        int mid = r - (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    std::cout << r << "\n";
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