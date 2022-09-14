#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = double; 
// using ld = __float128;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;
 
    int tests = 1;
    // cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

const ld INF = 2e5;
const ld EPS = 1e-9;

bool eq(ld a, ld b) {
    return abs(a - b) < EPS;
}

struct Point {
    Point() {}
    Point(ld x, ld y) : x(x), y(y) {}

    ld x, y;

    Point operator+=(const Point &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point operator-=(const Point &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};

Point operator+(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

Point operator*(const Point &a, ld c) {
    return {a.x * c, a.y * c};
}

Point operator/(const Point &a, ld c) {
    return {a.x / c, a.y / c};
}

istream &operator>>(istream &stream, Point &a) {
    stream >> a.x >> a.y;
    return stream;
}

ostream &operator<<(ostream &stream, const Point &a) {
    stream << a.x << " " << a.y;
    return stream;
}

bool operator<(const Point &a, const Point &b) {
    return tie(a.x, a.y) < tie(b.x, b.y);
}

bool operator>(const Point &a, const Point &b) {
    return tie(a.x, a.y) > tie(b.x, b.y);
}

ld dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
} 

ld cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

Point intersect(const Point &a, const Point &b, ld y) {
    return (a * (b.y - y) + b * (y - a.y)) / (b.y - a.y);
}


struct Line {
    Line() {};
    Line(Point a, Point b) : a(a), v(b - a) {};
    Point a;
    Point v;
};

bool lineComp(const Line &a, const Line &b) {
    Point origin{0, 0};
    if (a.v < origin && origin < b.v) {
        return true;
    } else if (a.v > origin && origin > b.v) {
        return false;
    }
    return cross(a.v, b.v) > 0;
}

bool posSide(Line l, Point a) {
    return cross(l.v, a - l.a) > 0;
}

Point intersect(const Line &a, const Line &b) {
    ld x = cross(b.v, a.a - b.a) / cross(a.v, b.v);
    // ld x = b.v.x * (a.a - b.a).y - b.v.y * (a.a - b.a).x;
    // x /= (a.v.x * b.v.y - a.v.y * b.v.x);
    return a.a + (a.v * x);
}

ld dist(const Point &a) {
    return hypotl(a.x, a.y);
}

vector<Point> intersect(vector<Line> lines) {
    int n = sz(lines);
    sort(lines.begin(), lines.end(), lineComp);
    vector<int> sides;
    int m = 0;
    for (int i = 0; i < 2 * n; ) {
        int k = i % n;
        while (i < 2 * n && eq(cross(lines[k].v, lines[i % n].v), 0)) {
            if (posSide(lines[k], lines[i % n].a)) {
                k = i % n;
            }
            ++i;
        }
        while (m > 1 && !posSide(lines[k], intersect(lines[sides[m - 1]], lines[sides[m - 2]]))) {
            --m;
            sides.pop_back();
        }
        ++m;
        sides.push_back(k);
    }

    vector<int> used(n, -1);
    int s = -1, f = -1;
    for (int i = 0; i < m; ++i) {
        if (used[sides[i]] != -1) {
            s = used[sides[i]];
            f = i;
            break;
        }
        used[sides[i]] = i;
    }
    vector<Point> inter;
    for (int i = s; i < f; ++i)  {
        inter.push_back(intersect(lines[sides[i]], lines[sides[(i == f - 1 ? s : i + 1)]]));
    }
    return inter;
}

ld area(const vector<Point> &p) {
    ld ans = 0;
    int n = sz(p);
    for (int i = 0; i < n; ++i) {
        int j = i + 1 == n ? 0 : i + 1;
        ans += cross(p[i] - p[0], p[j] - p[0]);
    }
    return abs(ans) / 2;
}


ld get(Point a, Point b, Point c, Point d, ld x) {
    if (eq(a.y, c.y)) {
        return 0;
    }
    // cerr << a << endl;
    // cerr << b << endl;
    // cerr << c << endl;
    // cerr << d << endl;
    // cerr << x << endl;


    vector<Line> lines;
    if (!eq(a.x, b.x)) {
        lines.push_back(Line(a, b));
    }
    if (!eq(c.x, d.x)) {
        lines.push_back(Line(d, c));
    }
    lines.push_back(Line(c, a));
    lines.push_back(Line(b, d));
    ld ans = 2 * area({a, b, d, c});
    a.x = 2 * x - a.x;
    b.x = 2 * x - b.x;
    c.x = 2 * x - c.x;
    d.x = 2 * x - d.x;

    lines.push_back(Line(a, c));
    lines.push_back(Line(d, b));

    // for (auto l : lines) {
    //     cerr << l.a << " " << l.v << endl;
    // }

    // cerr << area(intersect(lines)) << endl;

    // cerr << (ans - area(intersect(lines))) / 2 << endl;
    // cerr << endl;

    return (ans - area(intersect(lines))) / 2;
}

struct Event {
    ld t, a, b, c;
};

bool operator<(const Event &a, const Event &b) {
    return a.t < b.t;
}

void solve() {      
    int n, q;
    cin >> n >> q;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    int shift = 0;
    for (int i = 1; i < n; ++i) {   
        if (p[i].y < p[shift].y) {
            shift = i;
        }
    }
    rotate(p.begin(), p.begin() + shift, p.end());

    vector<pair<Point, Point>> seg;
    seg.push_back({p[0], p[0]});

    auto prv = [&](int k) {
        return k == 0 ? n - 1 : k - 1;
    };
    auto nxt = [&](int k) {
        return k == n - 1 ? 0 : k + 1;
    };

    int u = nxt(0), v = prv(0);
    while (u != v) {
        if (p[u].y < p[v].y) {
            seg.push_back({p[u], intersect(p[v], p[nxt(v)], p[u].y)});
            u = nxt(u);
        } else {
            seg.push_back({p[v], intersect(p[u], p[prv(u)], p[v].y)});
            v = prv(v);
        }
    }
    seg.push_back({p[u], p[u]});


    for (int i = 0; i < sz(seg); ++i) {
        if (seg[i].first > seg[i].second) {
            swap(seg[i].first, seg[i].second);
        }
    }

    ld ca = 0, cb = 0, cc = 0;

    vector<Event> events;


    for (int i = 0; i + 1 < sz(seg); ++i) {
        auto [a, b] = seg[i];
        auto [c, d] = seg[i + 1];
        vector<ld> t = {-INF, a.x, b.x, (a.x + b.x) / 2, c.x, d.x, (c.x + d.x) / 2, INF};
        sort(all(t));
        int s = 1;

        for (int j = 1; j < sz(t); ++j) {
            if (!eq(t[j], t[s - 1])) {
                t[s] = t[j];
                ++s;
            }
        }
        t.resize(s);

        vector<array<ld, 4>> arr;

        for (int j = 0; j + 1 < sz(t); ++j) {
            vector<ld> x = {
                t[j], (t[j] + t[j + 1]) / 2, t[j + 1]
            };
            vector<ld> y = {
                get(a, b, c, d, x[0]),
                get(a, b, c, d, x[1]),
                get(a, b, c, d, x[2])
            };
            x = {-1, 0, 1};
            
            ld aa = 0, bb = 0, cc = 0;
            for (int k = 0; k < 3; ++k) {
                ld q = (x[k] - x[(k + 1) % 3]) * (x[k] - x[(k + 2) % 3]);
                aa += 1. / q * y[k];
                bb -= (x[(k + 1) % 3] + x[(k + 2) % 3]) / q * y[k];
                cc += x[(k + 1) % 3] * x[(k + 2) % 3] / q * y[k];
            }

            ld delta = (t[j + 1] - t[j]) / 2;
            aa /= delta * delta;
            bb /= delta;

            ld shift = -(t[j + 1] + t[j]) / 2;
            cc += shift * bb + shift * shift * aa;
            bb += 2 * shift * aa;

            arr.push_back({aa, bb, cc, t[j]});
        }

        ca += arr[0][0];
        cb += arr[0][1];
        cc += arr[0][2];

        for (int j = 1; j < sz(arr); ++j) {
            events.push_back({arr[j][3], 
                arr[j][0] - arr[j - 1][0], 
                arr[j][1] - arr[j - 1][1], 
                arr[j][2] - arr[j - 1][2]
            });
        }
    }

    sort(all(events));

    // cerr << ca << " " << cb << " " << cc << endl;
    // for (auto e : events) {
    //     cerr << e.t << " " << e.a << " " << e.b << " " << e.c << endl;
    // }

    vector<pii> queries(q);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(all(queries));

    int ptr = 0;
    vector<ld> res(q);

    for (auto [t, i] : queries) {
        while (ptr < sz(events) && events[ptr].t < t) {
            ca += events[ptr].a;
            cb += events[ptr].b;
            cc += events[ptr].c;
            ++ptr;
        }
        // cerr << ca << " " << cb << " " << cc << endl;
        res[i] = ca * t * t + cb * t + cc;
    }

    for (int i = 0; i < q; ++i) {
        cout << res[i] << "\n"; 
    }

}