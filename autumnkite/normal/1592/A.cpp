#include <bits/stdc++.h>

void solve() {
    int n, H;
    std::cin >> n >> H;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    int t = H / (a[0] + a[1]) * 2;
    H %= (a[0] + a[1]);
    if (H > 0 && H <= a[0]) {
        ++t;
    } else if (H > a[0]) {
        t += 2;
    }
    std::cout << t << "\n";
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