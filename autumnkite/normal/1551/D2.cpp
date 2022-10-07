#include <bits/stdc++.h>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    bool op = false;
    if (m & 1) {
        std::swap(n, m);
        k = n * m / 2 - k;
        op = true;
    }

    std::vector<std::string> a(n, std::string(m, 'a'));

    int tn = n;
    if (n & 1) {
        for (int i = 0; i < m; i += 2) {
            a[n - 1][i] = a[n - 1][i + 1] = 'a' + (i >> 1 & 1);
        }
        --tn;
        k -= m / 2;
    }

    if (k < 0 || k & 1) {
        std::cout << "NO\n";
        return;
    }

    for (int i = 0; i < m; i += 2) {
        for (int j = 0; j < tn; ++j) {
            if (k) {
                --k;
                a[j][i] = a[j][i + 1] = 'c' + 2 * (i >> 1 & 1) + (j & 1);
            } else {
                a[j][i] = a[j + 1][i] = 'g' + (j >> 1 & 1);
                a[j][i + 1] = a[j + 1][i + 1] = 'i' + (j >> 1 & 1);
                ++j;
            }
        }
    }

    std::cout << "YES\n";
    if (op) {
        std::swap(n, m);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (op) {
                std::cout << a[j][i];
            } else {
                std::cout << a[i][j];
            }
        }
        std::cout << "\n";
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