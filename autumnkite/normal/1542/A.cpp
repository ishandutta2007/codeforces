#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int cnt[2] = {};
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        std::cin >> x;
        ++cnt[x & 1];
    }
    if (cnt[0] == n) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
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