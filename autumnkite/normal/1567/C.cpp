#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a, b;
    for (int i = 0; i < 5; ++i) {
        a.push_back(n % 10);
        n /= 10;
        b.push_back(n % 10);
        n /= 10;
    }
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int sa = 0, sb = 0;
    for (int x : a) {
        sa = sa * 10 + x;
    }
    for (int x : b) {
        sb = sb * 10 + x;
    }
    std::cout << (sa + 1) * (sb + 1) - 2 << "\n";
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