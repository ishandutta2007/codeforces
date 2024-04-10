#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = n % 2 + 2; i < n; i += 2) {
        p[i] = i + 1;
        p[i + 1] = i;
    }
    if (n % 2) {
        p[0] = 2, p[1] = 0, p[2] = 1;
    } else {
        p[0] = 1, p[1] = 0;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << p[i] + 1 << " ";
    }
    std::cout << "\n";
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