#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> id(2 * n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        id[x] = i;
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 1; i * j <= 2 * n && j < i; ++j) {
            if (id[i] != -1 && id[j] != -1) {
                ans += i * j == id[i] + id[j];
            }
        }
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