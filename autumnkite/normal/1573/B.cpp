#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(2 * n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        --x;
        p[x] = i;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        --x;
        p[x] = i;
    }

    int ans = 2 * n, mn = 2 * n;
    for (int i = 1; i < 2 * n; i += 2) {
        mn = std::min(mn, p[i - 1]);
        ans = std::min(ans, mn + p[i]);
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