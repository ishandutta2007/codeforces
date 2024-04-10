#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int a = 0, b = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        int c;
        std::cin >> c;
        if (c == 1) {
            ++a;
        } else {
            ++b;
        }
        sum += c;
    }
    if (sum & 1) {
        std::cout << "NO\n";
        return;
    }
    sum /= 2;
    for (int i = 0; i <= b && 2 * i <= sum; ++i) {
        if (sum - 2 * i <= a) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
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