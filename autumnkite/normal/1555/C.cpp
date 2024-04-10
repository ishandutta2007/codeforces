#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int sa = 0, sb = std::accumulate(b.begin(), b.end(), 0);
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        sb -= b[i];
        ans = std::min(ans, std::max(sa, sb));
        sa += a[i];
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