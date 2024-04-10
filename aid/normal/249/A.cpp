#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    long double x, y;

    Point() {}

    Point(long double _x, long double _y): x(_x), y(_y) {}

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
};

const long double EPS = 1e-9;

long double cp(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

long double sp(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

long double len(const Point &p) {
    return sqrt(sp(p, p));
}

Point intersect(const Point &a, const Point &b, long double y) {
    return Point(a.x + (b.x - a.x) * (y - a.y) / (b.y - a.y), y);
}

long double dist(const Point &a, const Point &b, const Point &c) {
    return fabs(cp(b - a, c - a)) / len(b - c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(20);
    long double y0, y1, yw, r;
    Point b;
    cin >> y0 >> y1 >> yw >> b.x >> b.y >> r;
    yw -= r;
    Point p = intersect(b, Point(0, 2 * yw - (y0 + r)), yw);
    if(dist(Point(0, y1), p, Point(0, y0 + r)) < r - EPS)
        cout << -1 << '\n';
    else
        cout << p.x << '\n';
    return 0;
}