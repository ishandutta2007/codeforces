#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

void solve() {
    int W, H;
    std::cin >> W >> H;
    int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;
    int w, h;
    std::cin >> w >> h;
    int ans = INF;
    if (int d = std::max(w - sx, 0); tx + d <= W) {
        ans = std::min(ans, d);
    }
    if (int d = std::max(h - sy, 0); ty + d <= H) {
        ans = std::min(ans, d);
    }
    if (int d = std::max(tx - W + w, 0); sx - d >= 0) {
        ans = std::min(ans, d);
    }
    if (int d = std::max(ty - H + h, 0); sy - d >= 0) {
        ans = std::min(ans, d);
    }
    if (ans == INF) {
        std::cout << -1 << "\n";
    } else {
        std::cout << ans << "\n";
    }
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