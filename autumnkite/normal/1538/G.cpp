#include <bits/stdc++.h>

void solve() {
    long long p, q, a, b;
    std::cin >> p >> q >> a >> b;
    if (a < b) {
        std::swap(a, b);
    }
    long long lim = std::min(p / a, q / b);
    if (a == b) {
        std::cout << lim << "\n";
        return;
    }
    long long x = (p * a - q * b) / (a * a - b * b);
    x = std::max(x, 0ll);
    x = std::min(x, lim);

    auto calc_y = [&](long long x) {
        return std::min((p - a * x) / b, (q - b * x) / a);
    };

    long long ans = x + calc_y(x);
    if (x + 1 <= lim) {
        ans = std::max(ans, x + 1 + calc_y(x + 1));
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