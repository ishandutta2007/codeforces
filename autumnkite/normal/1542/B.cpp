#include <bits/stdc++.h>

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    long long pw = 1;
    while (pw <= n) {
        if ((n - pw) % b == 0) {
            std::cout << "Yes\n";
            return;
        }
        if (a == 1) {
            break;
        }
        pw *= a;
    }
    std::cout << "No\n";
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