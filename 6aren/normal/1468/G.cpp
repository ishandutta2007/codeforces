#include <bits/stdc++.h>

#define int long long
using namespace std;

#define EPS 1e-6
inline int cmp(int a, int b) { return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0); }

template<typename T = int>
struct Point {
    T x, y;
    Point() { x = y = 0; }
    Point(T x, T y) : x(x), y(y) {}

    Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
    Point operator * (T k) const { return Point(x*k, y*k); }
    Point operator / (T k) const { return Point(x/k, y/k); }

    T operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product
    T operator % (const Point& a) const { return x*a.y - y*a.x; } // cross product
    double norm() { return x*x + y*y; }
    double len() { return sqrt(norm()); } // hyPoint(x, y);
};

int ccw(Point<int> x, Point<int> y, Point<int> z) {
    return (y - x) % (z - x);
}

double ccw_double(Point<double> x, Point<double> y, Point<double> z) {
    return (y - x) % (z - x);
}

const int N = 200010;

int n, h;
Point<> a[N];
Point<> I;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    I = a[n];
    I.y += h;
    int id = n;
    double res = 0.0;
    Point<double> II(I.x, I.y);
    Point<double> ID(a[id].x, a[id].y);
    for (int i = n - 1; i; i--) {
        if (ccw(I, a[id], a[i]) > 0) continue;
        Point<double> cur(a[i].x, a[i].y);
        if (id == i + 1) res += (a[i + 1] - a[i]).len();
        else {
            // cout << "here" << endl;
            double low = 0, high = 1;
            Point<double> now;
            for (int it = 0; it < 40; it++) {
                double mid = 0.5 * (low + high);
                now.x = 1.0 * a[i].x + mid * (a[i + 1].x - a[i].x);
                now.y = 1.0 * a[i].y + mid * (a[i + 1].y - a[i].y);
                // cout << now.x << ' ' << now.y << endl;
                if (ccw_double(II, ID, now) > 0.0) high = mid;
                else low = mid;
            }
            res += (now - cur).len();
        }
        id = i;
        ID = cur;
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}