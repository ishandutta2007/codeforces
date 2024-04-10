#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex>
#include <ctime>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()


const double EPS = 1e-9;

bool eq(double a, double b) {
    return abs(a - b) < EPS;
}

bool lt(double a, double b) {
    return (a - b < -EPS);
}

bool gt(double a, double b) {
    return (a - b > EPS);
}

bool leq(double a, double b) {
    return a - b < EPS;
}

bool geq(double a, double b) {
    return a - b > -EPS;
}

double mySqrt(double a) {
    return (eq(a, 0) ? 0 : sqrt(a));
}

double sqr(double a) {
    return a * a;
}

const double INF = 1e18;

struct Point {
    Point() {};
    Point(double x, double y): x(x), y(y) {}
    double x;
    double y;


    Point operator += (const Point &other) {
        x = x + other.x;
        y = y + other.y;
        return *this;
    }

    Point operator + (const Point &other) const {
        Point temp = *this;
        return temp += other;
    }

    Point operator -= (const Point &other) {
        x = x - other.x;
        y = y - other.y;
        return *this;
    }

    Point operator - (const Point &other) const {
        Point temp = *this;
        return temp -= other;
    }

    Point operator * (double c) const{
        return Point{x * c, y * c};
    }

    Point operator / (double c) const{
        return Point{x / c, y / c};
    }

    bool operator == (const Point &other) const {
        return eq(x, other.x) && eq(y, other.y);
    }

    bool operator < (const Point &other) const {
        if (eq(x, other.x))
            return lt(y, other.y);
        return lt(x, other.x);
    }

    bool operator > (const Point &other) const {
        if (eq(x, other.x))
            return gt(y, other.y);
        return gt(x, other.x);
    }
};

istream &operator >> (std::istream &stream, Point &a) {
    stream >> a.x >> a.y;
    return stream;
}

ostream &operator << (std::ostream &stream, const Point &a) {
    stream << a.x << " " << a.y;
    return stream;
}

double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

double dist(const Point &a) {
    return mySqrt(dot(a, a));
}

int main() {
    int n;
    Point a;
    Point b;
    Point t;
    cin >> a >> b >> t;
    cin >> n;
    double sum = 0;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        sum += 2 * dist(p[i] - t);
    }

    int m1 = -1, m2 = -1;

    for (int i = 0; i < n; ++i) {
        if (m1 == -1 || dist(a - p[i]) - dist(p[i] - t) < dist(a - p[m1]) - dist(p[m1] - t)) {
            m2 = m1;
            m1 = i;
        }
        else {
            if (m2 == -1 || dist(a - p[i]) - dist(p[i] - t) < dist(a - p[m2]) - dist(p[m2] - t))
                m2 = i;
        }
    }

    double ans = sum + dist(a - p[m1]) - dist(p[m1] - t);

    for (int i = 0; i < n; ++i) {
        if (i != m1)
            ans = min(ans, sum + dist(p[m1] - a) + dist(p[i] - b) - dist(p[m1] - t) - dist(p[i] - t));
        else
            if (n > 1) {
                ans = min(ans, sum + dist(p[m2] - a) + dist(p[i] - b) - dist(p[m2] - t) - dist(p[i] - t));
            }
    }

    int m3 = -1;
    for (int i = 0; i < n; ++i)
        if (m3 == -1 || dist(b - p[i]) - dist(p[i] - t) < dist(b - p[m3]) - dist(p[m3] - t))
            m3 = i;

    ans = min(ans, sum + dist(b - p[m3]) - dist(p[m3] - t));

    cout.precision(12);
    cout << ans << endl;

    return 0;
}