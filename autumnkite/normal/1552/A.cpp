#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string a;
    std::cin >> a;
    std::string b = a;
    std::sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] != b[i];
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