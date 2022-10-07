#include <bits/stdc++.h>

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::string s;
    std::cin >> s;
    int cnt[2] = {1, 1};
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i - 1] != s[i]) {
            ++cnt[s[i] ^ '0'];
        }
    }
    if (b > 0) {
        std::cout << a * n + n * b << "\n";
    } else {
        std::cout << a * n + std::min(cnt[0], cnt[1]) * b << "\n";
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