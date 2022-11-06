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

#define double long double

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

struct point {
    double x, y;

    point operator-(const point& r) const {
        return point{x - r.x, y - r.y};
    }

    point operator+(const point& r) const {
        return point{x + r.x, y + r.y};
    }

    point operator*(double k) const {
        return point{x * k, y * k};
    }

    double operator*(const point& r) const {
        return x * r.y - y * r.x;
    }
};

point norm(const point& r) {
    double t = sqrt(r.x * r.x + r.y * r.y);
    return point{r.x / t, r.y / t};
}

point rot(const point& r, double ang) {
    point res;
    res.x = r.x * cos(ang) - r.y * sin(ang);
    res.y = r.x * sin(ang) + r.y * cos(ang);
    return res;
}

double dist(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool is_inter(point a, double ra, point b, double rb) {
    double d = dist(a, b);
    double r1 = max(ra, rb);
    double r2 = min(ra, rb);
    if (d >= r1 && r1 + r2 >= d) {
        return true;
    }

    if (d < r1 && d + r2 >= r1) {
        return true;
    }

    return false;
}

bool p_ins(point a, double ra, point p) {
    return dist(a, p) <= ra;
}

bool inter3(point a, double ra, point b, double rb, point c, double rc) {
    if (p_ins(a, ra, c) && p_ins(b, rb, c)) {
        return true;
    }

    if (!is_inter(a, ra, b, rb)) {
        return false;
    }

    double d = dist(a, b);
    double ang = acos((ra * ra + d * d - rb * rb) / (2 * ra * d));

    point z1 = rot(norm(b - a), ang) * ra + a;
    point z2 = rot(norm(b - a), -ang) * ra + a;

    if (p_ins(c, rc, z1) || p_ins(c, rc, z2)) {
        return true;
    }

    return false;
}

bool check(point a, double ra, point b, double rb, point c, double rc) {
    if (ra < 0 || rb < 0 || rc < 0) {
        return false;
    }
    bool f = inter3(a, ra, b, rb, c, rc) ||
            inter3(a, ra, c, rc, b, rb) ||
            inter3(b, rb, c, rc, a, ra);
    return f;
}

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << setprecision(11) << fixed;

    scid(t1, t2);
    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    double o1 = dist(a, c) + dist(c, b);
    double o2 = dist(a, b);

    double a1 = 0;
    double a2 = 0;

    if (dist(a, b) + dist(b, c) * 2 - o1 <= t1) {
        a1 = dist(a, b) + min<double>(t2, t1 + o1 - dist(a, b) - dist(b, c) * 2);
    } else {
        double l = 0;
        double r = 1;
        point t;
        for (int i = 0; i < 1000; i++) {
            double m = (l + r) / 2;
            t.x = a.x + (b.x - a.x) * m;
            t.y = a.y + (b.y - a.y) * m;
            if (dist(a, t) + dist(t, c) + dist(c, b) - o1 <= t1) {
                l = m;
            } else {
                r = m;
            }
        }
        a1 = dist(a, t);
    }


    if (dist(a, c) + dist(b, c) - o2 <= t2) {
        a2 = dist(a, c) + dist(b, c) + min<double>(t1, t2 + o2 - dist(a, c) - dist(b, c));
    } else {
        double l = 0;
        double r = 1;
        point t;
        for (int i = 0; i < 1000; i++) {
            double m = (l + r) / 2;
            t.x = a.x + (c.x - a.x) * m;
            t.y = a.y + (c.y - a.y) * m;
            if (dist(a, t) + dist(t, b) - o2 <= t2) {
                l = m;
            } else {
                r = m;
            }
        }
        a2 = dist(a, t);
    }

    double ac = dist(a, c);
    double ab = dist(a, b);
    double bc = dist(b, c);
    double ang = acos((ac * ac + ab * ab - bc * bc) / (2 * ab * ac));
    if ((b - a) * (c - a) < 0) {
        ang = -ang;
    }
    double l = 0;
    double r = 1e5;

    for (int i = 0; i < 2000; i++) {
        double m = (l + r) / 2;
        if (check(a, m, c, o1 + t1 - m - dist(b, c), b, o2 + t2 - m)) {
            l = m;
        } else {
            r = m;
        }
    }

    double a3 = l;

    cout << max(a1, max(a2, a3));

    return 0;
}