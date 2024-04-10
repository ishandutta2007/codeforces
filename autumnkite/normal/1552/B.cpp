#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 5>> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cin >> a[i][j];
        }
    }
    int id = 0;
    for (int i = 1; i < n; ++i) {
        int c = 0;
        for (int j = 0; j < 5; ++j) {
            c += a[i][j] < a[id][j];
        }
        if (c >= 3) {
            id = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (id != i) {
            int c = 0;
            for (int j = 0; j < 5; ++j) {
                c += a[i][j] < a[id][j];
            }
            if (c >= 3) {
                std::cout << -1 << "\n";
                return;
            }
        }
    }
    std::cout << id + 1 << "\n";
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