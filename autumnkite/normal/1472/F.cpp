#include <bits/stdc++.h>

void solve() {
    int m, n;
    std::cin >> m >> n;
    std::vector<int> r(n), c(n), v;
    for (int i = 0; i < n; ++i) {
        std::cin >> r[i] >> c[i];
        --r[i], --c[i];
        v.push_back(c[i]);
    }
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    std::vector<int> st(v.size());
    for (int i = 0; i < n; ++i) {
        c[i] = std::lower_bound(v.begin(), v.end(), c[i]) - v.begin();
        st[c[i]] |= 1 << r[i];
    }
    bool ok = st[0] == 3;
    for (int i = 1; i < (int)v.size(); ++i) {
        if (st[i] == 3) {
            if (!ok) {
                std::cout << "NO\n";
                return;
            }
            continue;
        }
        if (ok) {
            ok = false;
            continue;
        }
        bool par = (v[i] - v[i - 1]) & 1;
        if (st[i - 1] == st[i]) {
            if (!par) {
                std::cout << "NO\n";
                return;
            } else {
                ok = true;
            }
        } else {
            if (par) {
                std::cout << "NO\n";
                return;
            } else {
                ok = true;
            }
        }
    }
    if (!ok) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
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