#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    double p[n], u[n];
    const double maxc = 4000;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> u[i];
    }
    auto f = [&](double x, double y) {
        double res = 0;
        for(int i = 0; i < n; i++) {
            res += max({
                0.,
                p[i] - x,
                u[i] - y,
                p[i] + u[i] - p[i] * u[i] - x - y
            });
        }
        return res + a * x + b * y;
    };
    auto in = [&](double x) {
        double l = 0, r = maxc;
        for(int z = 0; z < 50; z++) {
            double eps = (r - l) / 1e3;
            double y1 = (l + r) / 2 - eps;
            double y2 = (l + r) / 2 + eps;
            if(f(x, y1) > f(x, y2)) {
                l = y1;
            } else {
                r = y2;
            }
        }
        return f(x, (l + r) / 2);
    };
    auto out = [&]() {
        double l = 0, r = maxc;
        for(int z = 0; z < 50; z++) {
            double eps = (r - l) / 1e3;
            double x1 = (l + r) / 2 - eps;
            double x2 = (l + r) / 2 + eps;
            if(in(x1) > in(x2)) {
                l = x1;
            } else {
                r = x2;
            }
        }
        return in((l + r) / 2);
    };
    cout << fixed << setprecision(6) << out() << endl;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}