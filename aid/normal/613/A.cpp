#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(int _x, int _y): x(_x), y(_y) {}

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
};

const int MAXN = 100 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
Point p[MAXN];

long long sp(const Point &a, const Point &b) {
    return (long long)a.x * b.x + (long long)a.y * b.y;
}

long long cp(const Point &a, const Point &b) {
    return (long long)a.x * b.y - (long long)a.y * b.x;
}

long double len(const Point &a) {
    return sqrt(sp(a, a));
}

long double dist(const Point &q, const Point &a, const Point &b) {
    if(sp(b - a, q - a) <= 0)
        return len(q - a);
    if(sp(a - b, q - b) <= 0)
        return len(q - b);
    return fabs(cp(a - q, b - q)) / len(b - a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n;
    Point q;
    cin >> n >> q.x >> q.y;
    for(int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    p[n] = p[0];
    long double l = INF, r = 0;
    for(int i = 0; i < n; i++) {
        r = max(r, len(p[i] - q));
        l = min(l, dist(q, p[i], p[i + 1]));
    }
    cout << M_PI * (r * r - l * l) << '\n';
    return 0;
}