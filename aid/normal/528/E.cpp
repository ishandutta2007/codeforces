#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y): x(x), y(y) {}

    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
};

struct Line {
    double a, b, c;

    Line() {}

    Line(double a, double b, double c): a(a), b(b), c(c) {}
};

const double EPS = 1e-9;
const int MAXN = 3005;
Line l[2 * MAXN];

double cp(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

bool operator<(const Point &a, const Point &b) {
    return cp(a, b) > EPS;
}

bool operator<(const Line &a, const Line &b) {
    return Point(a.a, a.b) < Point(b.a, b.b);
}

Point intersect(const Line &l0, const Line &l1) {
    double d = l0.a * l1.b - l0.b * l1.a;
    return Point(((-l0.c) * l1.b - l0.b * (-l1.c)) / d,
                 (l0.a * (-l1.c) - (-l0.c) * l1.a) / d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> l[i].a >> l[i].b >> l[i].c;
        l[i].c *= -1;
        if(l[i].a < -EPS) {
            l[i].a *= -1;
            l[i].b *= -1;
            l[i].c *= -1;
        }
    }
    sort(l, l + n);
    for(int i = 0; i < n; i++)
        l[n + i] = l[i];
    double ans = 0;
    for(int i = 0; i < n; i++) {
        Point sum(0, 0);
        for(int j = i + 1; j < n + i; j++) {
            Point cur = intersect(l[i], l[j]);
            ans += cp(cur, sum);
            sum = sum + cur;
        }
    }
    ans *= -3;
    ans /= (long long)n * (n - 1) * (n - 2);
    cout << ans << '\n';
    return 0;
}