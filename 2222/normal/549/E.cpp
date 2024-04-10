#include <bits/stdc++.h>

using namespace std;

struct Point { int x, y; };

int det(int a, int b, int c, int d) { return a * d - b * c; }

int det(const Point &p, const Point &q, const Point &o) {
    return det(p.x - o.x, p.y - o.y, q.x - o.x, q.y - o.y);
}

int convexHull(Point *a, int n) {
    if(n < 3) return n;
    swap(*a, *min_element(a, a + n, [](const Point &a, const Point &b) {
        return a.x < b.x || a.x == b.x && a.y < b.y;
    }));
    sort(a + 1, a + n, [a](const Point &p, const Point &q) {
        auto d = det(p, q, *a);
        return d < 0 || d == 0 && (a->x - p.x) * (q.x - p.x) + (a->y - p.y) * (q.y - p.y) < 0;
    });
    int h = 1;
    for (int i = 2; i < n; ++i) {
        while (h > 0 && det(a[h - 1], a[h], a[i]) >= 0)
            --h;
        swap(a[++h], a[i]);
    }
    return h + 1;
}

bool solve(const Point *a, const Point *b, int n, int m, int i, int j) {
    int dx = a[i].y - a[j].y;
    int dy = a[j].x - a[i].x;
    double minR = -1e100, maxR = 1e100;
    int mid = -1;
    for (int k = i + 1; k < j; ++k) {
        int ka = a[k].x - a[i].x;
        int kb = a[k].y - a[i].y;
        auto r = (double)((a[k].x - a[j].x) * ka + (a[k].y - a[j].y) * kb) / (dx * ka + dy * kb);
        if (r > minR) {
            mid = k;
            minR = r;
        }
    }
    for (int k = j; ; ) {
        if (++k == n) k = 0;
        if (k == i) break;
        int ka = a[k].x - a[i].x;
        int kb = a[k].y - a[i].y;
        auto r = (double)((a[k].x - a[j].x) * ka + (a[k].y - a[j].y) * kb) / (dx * ka + dy * kb);
        maxR = min(maxR, r);
    }
    bool yes = true;
    for (int k = 0; k < m; ++k) {
        int ka = b[k].x - a[i].x;
        int kb = b[k].y - a[i].y;
        int kc = (b[k].x - a[j].x) * ka + (b[k].y - a[j].y) * kb;
        int kd = dx * ka + dy * kb;
        auto r = (double)kc / kd;
        if (kd > 0) {
            maxR = min(maxR, r);
        } else if (kd < 0) {
            minR = max(minR, r);
        } else if (kc <= 0) {
            yes = false;
            break;
        }
        if (minR >= maxR) {
            yes = false;
            break;
        }
    }
    return yes || mid >= 0 && (solve(a, b, n, m, i, mid) || solve(a, b, n, m, mid, j));
}

bool solve(Point *a, Point *b, int n, int m) {
    if (n == 1) return true;
    int h = convexHull(a, n);
    return solve(a, b, h, m, 0, h - 1);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Point> all(n + m);
    for (auto &p : all)
        scanf("%d%d", &p.x, &p.y);
    auto a = all.data();
    auto b = a + n;
    puts(solve(a, b, n, m) || solve(b, a, m, n) ? "YES" : "NO");
    return 0;
}