#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> cnt;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        v -= i;
        ans += cnt[v];
        ++cnt[v];
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}