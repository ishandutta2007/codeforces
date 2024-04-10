#include <bits/stdc++.h>

struct point {
    int x, y;

    point() : x(), y() {}
    point(int _x, int _y) : x(_x), y(_y) {}

    point operator-(const point &rhs) const {
        return point(x - rhs.x, y - rhs.y);
    }

    friend long long cross(const point &a, const point &b) {
        return 1ll * a.x * b.y - 1ll * a.y * b.x;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    ++k;
    std::vector<point> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].x >> a[i].y;
    }

    auto check = [&](long long x) {
        typedef std::pair<int, long long> state;
        std::vector<std::vector<state>> f(n, std::vector<state>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j < n; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    long long s = cross(a[k] - a[i], a[j] - a[i]);
                    s += f[i][k].second + f[k][j].second;
                    f[i][j] = std::max(f[i][j], state(
                        f[i][k].first + f[k][j].first + (s >= x),
                        s >= x ? 0ll : s
                    ));
                }
            }
        }
        return f[0][n - 1].first >= k;
    };

    long long l = 1, r = 1e18;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    std::cout << l << "\n";
}