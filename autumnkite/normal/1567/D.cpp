#include <bits/stdc++.h>

void solve() {
    int s, n;
    std::cin >> s >> n;
    for (int i = 1; i < n; ++i) {
        int v = pow(10, (int)log10(s - n + i));
        std::cout << v << " ";
        s -= v;
    }
    std::cout << s << "\n";
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