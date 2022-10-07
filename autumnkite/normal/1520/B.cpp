#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int k = 1; k <= 9; ++k) {
        int v = 0;
        for (int i = 1; i <= 9; ++i) {
            v = v * 10 + k;
            if (v <= n) {
                ++ans;
            }
        }
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