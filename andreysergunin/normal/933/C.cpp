#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;


const double EPS = 1e-9; 
const double PI = acos(-1);

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

double dist(const Point &a, const Point &b) {
    return mySqrt(dot(a - b, a - b));
}

Point footPerp(const Point &a, const Point &b, const Point &c) {
    double x = dot(a - b, c - b) / dist(c - b);
    return b + (c - b) * (x / dist(c - b));
}

double dist(const Point &a, const Point &b, const Point &c) {
    return dist(a - footPerp(a, b, c));
}

vector<Point> intersect(const Point &cen1, double r1, const Point &cen2, double r2) {
    double d = dist(cen1 - cen2);
    if (lt(r1 + r2, d) || gt(abs(r1 - r2), d))
        return {};
    double l = ((sqr(r1) - sqr(r2)) / d  + d) / 2;
    double h = mySqrt(sqr(r1) - sqr(l));
    Point a = cen1 + (cen2 - cen1) * (l / d);
    Point b = {(cen2 - cen1).y, -(cen2 - cen1).x};
    b = b * (h / dist(cen2 - cen1));
    if (b == Point{0, 0})
        return {a};
    return {a + b, a - b};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout); 

    int n;
    cin >> n;

    vector<Point> a(n);
    vector<int> r(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> r[i];
    }

    if (n == 1) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 2) {
        vector<Point> d = intersect(a[0], r[0], a[1], r[1]);

        if (sz(d) == 2) {
            cout << 4 << endl;
        } else {
            cout << 3 << endl;
        }
        return 0;
    }

    vector<Point> c;
    vector<vector<Point>> b(n);
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        vector<Point> d = intersect(a[i], r[i], a[j], r[j]);

        for (int k = 0; k < sz(d); ++k) {
            b[i].push_back(d[k]);
            b[j].push_back(d[k]);
            c.push_back(d[k]);
        }
        if (sz(d) != 0) {
            ++cnt;
        }
    }


    sort(all(c));
    c.resize(unique(all(c)) - c.begin());

    for (int i = 0; i < n; ++i) {
        sort(all(b[i]));
        b[i].resize(unique(all(b[i])) - b[i].begin());
    }

    int v = sz(c);
    int e = 0;
    for (int i = 0; i < n; ++i) {
        e += sz(b[i]);
    }

    int comp = max(1, n - cnt);

    // cout << "! " << v << " " << e << " "  << comp << endl;

    int f = e - v + comp + 1;
    cout << f << endl;


    return 0;
}