#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
    std::vector<int> a(n), b(n);
    std::vector<int> ca(n), cb(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];
        --a[i], --b[i];
        ++ca[a[i]], ++cb[b[i]];
    }
    for (int i = 0; i < n; ++i) {
        ans -= 1ll * (ca[a[i]] - 1) * (cb[b[i]] - 1);
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