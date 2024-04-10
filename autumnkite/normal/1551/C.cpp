#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int ans = 0;
    for (char c = 'a'; c <= 'e'; ++c) {
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            for (char x : a[i]) {
                if (x == c) {
                    ++v[i];
                } else {
                    --v[i];
                }
            }
        }
        std::sort(v.begin(), v.end(), std::greater<int>());
        int now = 0;
        for (int i = 0; i < n; ++i) {
            now += v[i];
            if (now > 0) {
                ans = std::max(ans, i + 1);
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