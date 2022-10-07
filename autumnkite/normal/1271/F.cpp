#include <bits/stdc++.h>

void solve() {
    int a[3], b[3];
    int d[8] = {};
    for (int i = 2; i >= 0; --i) {
        std::cin >> a[i];
    }
    for (int i = 2; i >= 0; --i) {
        std::cin >> b[i];
    }
    int c[3] = {};
    for (int i = 7; i >= 1; --i) {
        std::cin >> d[i];
        for (int j = 0; j < 3; ++j) {
            if (i >> j & 1) {
                c[j] += d[i];
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (c[i] > a[i] + b[i]) {
            std::cout << -1 << "\n";
            return;
        }
    }
    int f[8] = {};
    for (f[7] = 0; f[7] <= d[7]; ++f[7]) {
        for (f[6] = 0; f[6] <= d[6]; ++f[6]) {
            int ta[3] = {a[0], a[1], a[2]};
            int tb[3] = {b[0], b[1], b[2]};
            for (int i : {6, 7}) {
                for (int j = 0; j < 3; ++j) {
                    if (i >> j & 1) {
                        ta[j] -= f[i];
                        tb[j] -= d[i] - f[i];
                    }
                }
            }
            int l[3] = {d[3] + d[5] - tb[0], d[3] - tb[1], d[5] - tb[2]};
            int r[3] = {ta[0], ta[1], ta[2]};
            l[1] = std::max(l[1], 0);
            l[2] = std::max(l[2], 0);
            r[1] = std::min(r[1], d[3]);
            r[2] = std::min(r[2], d[5]);
            bool ok = true;
            for (int i = 0; i < 3; ++i) {
                ok &= ta[i] >= 0;
                ok &= tb[i] >= 0;
            }
            for (int i = 0; i < 3; ++i) {
                ok &= l[i] <= r[i];
            }
            if (!ok || r[1] + r[2] < l[0] || l[1] + l[2] > r[0]) {
                continue;
            }
            for (f[3] = l[1]; f[3] <= r[1]; ++f[3]) {
                for (f[5] = l[2]; f[5] <= r[2]; ++f[5]) {
                    if (l[0] <= f[3] + f[5] && f[3] + f[5] <= r[0]) {
                        int ta[3] = {a[0], a[1], a[2]};
                        int tb[3] = {b[0], b[1], b[2]};
                        for (int i : {3, 5, 6, 7}) {
                            for (int j = 0; j < 3; ++j) {
                                if (i >> j & 1) {
                                    ta[j] -= f[i];
                                    tb[j] -= d[i] - f[i];
                                }
                            }
                        }
                        for (int i = 0; i < 3; ++i) {
                            f[1 << i] = std::min(d[1 << i], ta[i]);
                        }
                        for (int i = 7; i >= 1; --i) {
                            std::cout << f[i] << " \n"[i == 1];
                        }
                        return;
                    }
                }
            }
        }
    }
    std::cout << -1 << "\n";
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