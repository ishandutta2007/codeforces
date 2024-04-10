#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int ans = 2 * n - 1;
    for (int i = 0; i + 2 < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            bool flag = true;
            for (int x = i; x < j; ++x) {
                for (int y = x + 1; y < j; ++y) {
                    if ((a[x] <= a[y] && a[y] <= a[j]) ||
                        (a[x] >= a[y] && a[y] >= a[j])) {
                        flag = false;
                    }
                }
            }
            if (flag) {
                ++ans;
            } else {
                break;
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