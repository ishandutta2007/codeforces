#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

struct Point {
    int x, y;

    Point () {}
    Point (int _x, int _y) {
        x = _x;
        y = _y;
    }

    void read() {
        scanf("%d%d", &x, &y);
    }

    double dist(Point o) {
        return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
    }
} a[100100];

struct Line {
    double a, b, c;

    Line () {}
    Line (Point p, Point q) {
        a = q.y - p.y;
        b = p.x - q.x;
        c = -a * p.x - b * p.y;
    }
    Line (double _a, double _b, double _c) {
        a = _a;
        b = _b;
        c = _c;
    }

    pair<Line, Line> move(double d) {
        double cnew = c - d * sqrt(a * a + b * b);
        return mp(Line(a, b, cnew), Line(a, b, -cnew));
    }

    double dist(Point p) {
        return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }
};

int n;

bool valid(int i, int j, int t, double D) {
    t %= n; t += n; t %= n;
    if (t == i || t == j) return true;
    Line L = Line(a[i], a[j]);
    pair<Line, Line> p = L.move(D);
    if (p.f.dist(a[t]) < D + 1e-9) return false;
    if (p.s.dist(a[t]) < D + 1e-9) return false;
    return true;
}

bool check(double D) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = a[i].dist(a[j]);
            if (2 * D + 1e-9 > d) return false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool ok = 1;
            ok &= valid(i, j, i + 1, D);
            ok &= valid(i, j, j - 1, D);
            ok &= valid(i, j, i - 1, D);
            ok &= valid(i, j, j + 1, D);
            if (!ok) return false;
        }
    }
    return true;
}

double calc(int i, int j, int k) {
    Line l = Line(a[j], a[k]);
    double ans = l.dist(a[i]) / 2.0;
    l = Line(a[i], a[k]);
    ans = min(ans, l.dist(a[j]) / 2.0);
    l = Line(a[i], a[j]);
    ans = min(ans, l.dist(a[k]) / 2.0);
    return ans;
}

int main(){

    scanf("%d", &n);
    for (int i = 0; i < n; i++) a[i].read();

    double ans = 2.0;
    ans *= 1e9;

    for (int i = 0; i < n; i++) {
        ans = min(ans, calc(i, (i + 1) % n, (i + 2) % n));
    }

    printf("%.9f\n", ans);
    return 0;

    double l = 0, r = (1e9) * 2.0;

    cout << check(1.0) << endl;

    for (int i = 0; i < 200; i++) {
        double mid = (l + r) / 2.0;
        if (check(mid)) {
            l = mid;
        } else r = mid;
    }

    printf("%.9f\n", l);

    return 0;
}