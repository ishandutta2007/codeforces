#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;

    auto calc = [&](int x, int y, bool op) {
        int pw = 1;
        int res = 0;
        while (x || y) {
            int v = !op ? x % k + y % k : x % k + k - y % k;
            res += v % k * pw;
            pw *= k;
            x /= k;
            y /= k;
        }
        return res;
    };
    
    int v = 0;
    for (int i = 0; i < n; ++i) {
        int y = calc(v, i, i & 1);
        std::cout << y << std::endl;
        int s;
        std::cin >> s;
        if (s) {
            return;
        }
        v = calc(y, v, 1);
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