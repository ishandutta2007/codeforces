#include <bits/stdc++.h>

void solve() {
    double a, b, c, v;
    std::cin >> a >> b >> c >> v;

    double ans = 0;

    auto dfs = [&](auto self, int k, std::vector<double> a, double now) -> void {
        double s = std::accumulate(a.begin(), a.end(), 0.0);
        ans += (k + 1) * now * (1 - s);
        for (int i = 0; i < (int)a.size(); ++i) {
            auto b(a);
            double tmp = std::min(a[i], v);
            for (int j = 0; j < (int)a.size(); ++j) {
                if (j != i) {
                    b[j] += tmp / a.size();
                }
            }
            if (a[i] < v + 1e-9) {
                b.erase(b.begin() + i);
            } else {
                b[i] -= v;
            }
            self(self, k + 1, b, now * a[i]);
        }
    };

    dfs(dfs, 0, {a, b}, 1);
    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cout.setf(std::ios::fixed);
    std::cout.precision(12);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}