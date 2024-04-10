#include <bits/stdc++.h>

struct point {
    int x, y;

    point() : x(), y() {}
    point(int _x, int _y) : x(_x), y(_y) {}

    point operator-(const point &rhs) const {
        return point(x - rhs.x, y - rhs.y);
    }
};

long long cross(const point &p, const point &q) {
    return 1ll * p.x * q.y - 1ll * p.y * q.x;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<point> a(n);
    std::vector<int> p(n, -1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].x >> a[i].y;
        if (p[0] == -1 || a[i].y < a[p[0]].y) {
            p[0] = i;
        }
    }
    std::string s;
    std::cin >> s;
    s += 'L';

    std::vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        id[i] = i;
    }

    for (int i = 0; i < n - 1; ++i) {
        id.erase(std::find(id.begin(), id.end(), p[i]));
        auto cmp = [&](int x, int y) {
            return cross(a[x] - a[p[i]], a[y] - a[p[i]]) > 0;
        };
        if (s[i] == 'L') {
            p[i + 1] = *std::min_element(id.begin(), id.end(), cmp);
        } else {
            p[i + 1] = *std::max_element(id.begin(), id.end(), cmp);
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << p[i] + 1 << " \n"[i == n - 1];
    }
}