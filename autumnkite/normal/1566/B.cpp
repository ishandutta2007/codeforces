#include <bits/stdc++.h>

void solve() {
    std::string a;
    std::cin >> a;
    int c = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i] == '0' && (i == 0 || a[i - 1] == '1')) {
            ++c;
        }
    }
    std::cout << std::min(c, 2) << "\n";
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