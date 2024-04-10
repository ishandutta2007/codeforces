#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int a, b;
    std::cin >> a >> b;
    int n = a + b;
    int ans = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        int g = n / l;
        r = n / g;
        if (a < g || b < g) {
            continue;
        }
        int la = (a + g) / (g + 1), ra = a / g;
        int lb = (b + g) / (g + 1), rb = b / g;
        if (la <= ra && lb <= rb) {
            ans += std::max(0, std::min(ra + rb, r) - std::max(l, la + lb) + 1);
        }
    }
    std::cout << ans << "\n";
}