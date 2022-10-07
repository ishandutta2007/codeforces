#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::string s;
    std::cin >> s;
    long long G = 0, W = 0;
    long long ans = 0;
    long long now = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'G') {
            ans += a[i] * 5;
            now += a[i];
            G += a[i] * 2;
        } else if (s[i] == 'W') {
            ans += a[i] * 3;
            now += a[i];
            W += a[i];
        } else {
            if (now < a[i]) {
                if (W) {
                    ans += (a[i] - now) * 3;
                } else {
                    ans += (a[i] - now) * 5;
                }
                now = a[i];
            }
            ans += a[i];
            now -= a[i];
        }
        G = std::min(G, now);
    }
    long long t = std::min(now, G);
    std::cout << ans - 2 * t - std::min(now - t, W * 2) << "\n";
}