#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int ans = 0;
    for (int v = -30; v <= 30; ++v) {
        int now = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > v) {
                now = 0;
            } else {
                now += a[i];
                ans = std::max(ans, now - v);
                if (now < 0) {
                    now = 0;
                }
            }
        }
    }
    std::cout << ans << "\n";
}