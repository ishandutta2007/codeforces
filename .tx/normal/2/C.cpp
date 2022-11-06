#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct point {
    double x, y;

    point operator-(const point& r) const {
        return point{x - r.x, y - r.y};
    }

    point operator+(const point& r) const {
        return point{x + r.x, y + r.y};
    }

    double operator*(const point& r) const {
        return x * r.y - y * r.x;
    }

    double operator%(const point& r) const {
        return x * r.x + y * r.y;
    }

    point rot(double ang) const {
        double nx = x * cos(ang) - y * sin(ang);
        double ny = x * sin(ang) + y * cos(ang);
        return point{nx, ny};
    }

    point norm() const {
        double t = sqrt(x * x + y * y);
        return point{x / t, y / t};
    }

    point operator*(double k) const {
        return point{x * k, y * k};
    }
};

double dist(point a, point b) {
    return dist(a.x, a.y, b.x, b.y);
}

tuple<point, double> calc(point a, double r1, point b, double r2) {
    double ax = (r1 * b.x + r2 * a.x) / (r1 + r2);
    double ay = (r1 * b.y + r2 * a.y) / (r1 + r2);

    double bx = (r2 * a.x - r1 * b.x) / (r2 - r1);
    double by = (r2 * a.y - r1 * b.y) / (r2 - r1);

    double cx = (ax + bx) / 2;
    double cy = (ay + by) / 2;
    double cr = dist(ax, ay, bx, by) / 2;
    return make_tuple(point{cx, cy}, cr);
};

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scidd(x1, y1, r1);
    scidd(x2, y2, r2);
    scidd(x3, y3, r3);

    if (r1 == r2 && r2 == r3) {

        double t1 = r1 / (r1 + r2);
        double tx1 = x1 + (x2 - x1) * t1;
        double ty1 = y1 + (y2 - y1) * t1;

        double a1 = x2 - x1;
        double b1 = y2 - y1;
        double c1 = -a1 * tx1 - b1 * ty1;

        double t2 = r2 / (r2 + r3);
        double tx2 = x2 + (x3 - x2) * t2;
        double ty2 = y2 + (y3 - y2) * t2;

        double a2 = x3 - x2;
        double b2 = y3 - y2;
        double c2 = -a2 * tx2 - b2 * ty2;

        double ad = a1 * b2 - a2 * b1;
        double ax = (-c1 * b2 + c2 * b1) / ad;
        double ay = (-a1 * c2 + a2 * c1) / ad;

        cout << setprecision(11) << fixed << ax << " " << ay << "\n";
    } else {
        if (r1 == r2) {
            swap(x1, x3);
            swap(y1, y3);
            swap(r1, r3);
        }
        if (r1 == r3) {
            swap(x1, x2);
            swap(y1, y2);
            swap(r1, r2);
        }

        point a = point{x1, y1};
        double ar = r1;

        point b = point{x2, y2};
        double br = r2;

        point c = point{x3, y3};
        double cr = r3;

        point t1, t2;
        double tr1, tr2;

        tie(t1, tr1) = calc(a, ar, b, br);
        tie(t2, tr2) = calc(a, ar, c, cr);

        if (tr1 < tr2) {
            swap(t1, t2);
            swap(tr1, tr2);
        }

        point z1, z2;

        double d = dist(t1, t2);

        double ang = acos((tr1 * tr1 + d * d - tr2 * tr2) / (2 * tr1 * d));
        if (ang != ang) {
            return 0;
        }
        z1 = (t2 - t1).rot(ang).norm() * tr1 + t1;
        z2 = (t2 - t1).rot(-ang).norm() * tr1 + t1;

        double f1 = asin(r1 / dist(z1, a));
        double f2 = asin(r1 / dist(z2, a));

        if (f1 > f2) {
            cout << setprecision(11) << fixed << z1.x << " " << z1.y << "\n";
        } else {
            cout << setprecision(11) << fixed << z2.x << " " << z2.y << "\n";
        }
    }


    return 0;
}