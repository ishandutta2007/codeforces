#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;

    Point() {}

    Point(double _x, double _y): x(_x), y(_y) {}

    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator*(double k) const {
        return Point(x * k, y * k);
    }

    Point operator/(double k) const {
        return Point(x / k, y / k);
    }
};

struct Line {
    double a, b, c;

    Line(double _a, double _b, double _c): a(_a), b(_b), c(_c) {}

    Line(const Point &p, const Point &q): a(q.y - p.y), b(p.x - q.x),
                                          c(-a * p.x - b * p.y) {}
};

const int MAXN = 1005;
const double EPS = 1e-9;
Point a[MAXN], b[MAXN];

double cp(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double sp(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

double len(const Point &p) {
    return sqrt(sp(p, p));
}

double dist(const Point &p, const Line &l) {
    return fabs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

bool onLine(const Point &p, const Line &l) {
    return fabs(l.a * p.x + l.b * p.y + l.c) < EPS;
}

bool onSeg(const Point &p, const Point &a, const Point &b) {
    return fabs(len(p - a) + len(b - p) - len(b - a)) < EPS;
}

pair<Point, Point> intersect(const Point &o, double r, const Line &l) {
    Point h(l.a, l.b);
    double d = dist(o, l);
    h = h / len(h) * d;
    if(!onLine(o + h, l))
        h = h * -1;
    Point p(-l.b, l.a);
    p = p / len(p) * sqrt(r * r - d * d);
    return make_pair(o + h + p, o + h - p);
}

bool solve(const Point &a, const Point &b, const Point &o, double r) {
    Line l(a, b);
    if(dist(o, l) > r + EPS)
        return false;
    pair<Point, Point> p = intersect(o, r, l);
    return onSeg(p.first, a, b) || onSeg(p.second, a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    Point p;
    cin >> p.x >> p.y >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    a[n] = a[0];
    int m;
    Point q;
    cin >> q.x >> q.y >> m;
    for(int i = 0; i < m; i++)
        cin >> b[i].x >> b[i].y;
    b[m] = b[0];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(solve(a[i], a[i + 1], b[j] + p - q, len(q - p)) ||
               solve(b[j], b[j + 1], a[i] + q - p, len(p - q))) {
                cout << "YES\n";
                return 0;
            }
    cout << "NO\n";
    return 0;
}