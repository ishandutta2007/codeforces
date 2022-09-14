#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const double PI = acos(-1);

struct point {
    point() {}
    point(double x, double y): x(x), y(y) {}
    double x, y;
};

struct segment {
    segment () {}
    segment (point a, point b): a(a), b(b) {}
    point a, b;
};

template <class T>
T sqr(T a) {
    return a * a;
}

double dist(point a, point b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double crossProduct(point a1, point a2, point b1, point b2) {
    return ((a2.x - a1.x) * (b2.y - b1.y) - (a2.y - a1.y) * (b2.x - b1.x));
}

double dotProduct(point a1, point a2, point b1, point b2) {
    return ((a2.x - a1.x) * (b2.x - b1.x) + (a2.y - a1.y) * (b2.y - b1.y));
}

double dist(point c, segment seg) {
    if (dotProduct(seg.a, seg.b, seg.a, c) <= 0 || dotProduct(seg.b, seg.a, seg.b, c) <= 0)
        return min(dist(c, seg.a), dist(c, seg.b));
    return abs(crossProduct(seg.a, seg.b, seg.a, c) / dist(seg.a, seg.b));
}

int main() {
    int n;
    point a;
    cin >> n;
    cin >> a.x >> a.y;
    double dmax = 0, dmin = 1e18;
    vector<point> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i].x >> b[i].y;
    for (int i = 0; i < n; i++) {
        dmax = max(dmax, dist(a, b[i]));
        dmin = min(dmin, dist(a, b[i]));
        dmin = min(dmin, dist(a, segment(b[i], b[(i + 1) % n])));
    }
    double ans = PI * (dmax * dmax - dmin * dmin);
    printf("%.12lf", ans);
        
    
    return 0;
}