#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> b >> a;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            if (b[i] == '0') {
                b[i] = '2';
                ++ans;
            } else if (i > 0 && b[i - 1] == '1') {
                b[i - 1] = '2';
                ++ans;
            } else if (i + 1 < n && b[i + 1] == '1') {
                b[i + 1] = '2';
                ++ans;
            }
        }
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