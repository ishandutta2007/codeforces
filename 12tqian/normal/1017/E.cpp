#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define trav(t, a) for (auto& t : a)

#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef double db;

template <class T> bool ckmax(T& a, T b) { return a < b ? a = b, 1 : 0; }
template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }

template <typename T> struct Point {
public:
    T x, y;
    Point() : x(0), y(0) {}
    Point(T x_, T y_) : x(x_), y(y_) {}
    template <typename U> explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}
    Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}
    Point(const std::complex<T>& p) : x(real(p)), y(imag(p)) {}
    explicit operator std::pair<T, T> () const { return std::pair<T, T>(x, y); }
    explicit operator std::complex<T> () const { return std::complex<T>(x, y); }

    friend std::ostream& operator << (std::ostream& o, const Point& p) { 
        return o << '(' << p.x << ',' << p.y << ')'; }
    friend std::istream& operator >> (std::istream& i, Point& p) { return i >> p.x >> p.y; }
    friend bool operator == (const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
    friend bool operator != (const Point& a, const Point& b) { return !(a == b); }
    friend bool operator < (const Point& a, const Point& b) { 
        return (a.x != b.x ? a.x < b.x : a.y < b.y); }

    friend T norm(const Point& a) { return a.x * a.x + a.y * a.y; }
    friend T abs(const Point& p) { return std::hypot(p.x, p.y); }
    friend T unit(const Point& a) { if (a == Point()) return a; return a / abs(a); }
    friend Point conj(const Point& a) { return Point(a.x, -a.y); }
    friend Point perp(const Point& a) { return Point(-a.y, a.x); }
    friend long double arg(const Point& p) { return atan2(p.y, p.x); }
    friend Point dir(long double angle) { return Point(cos(angle), sin(angle)); }

    Point& operator += (const Point& p) { x += p.x, y += p.y; return *this; }
    Point& operator -= (const Point& p) { x -= p.x, y -= p.y; return *this; }
    Point& operator *= (const T& t) { x *= t, y *= t; return *this; }
    Point& operator /= (const T& t) { x /= t, y /= t; return *this; }
    Point& operator *= (const Point& t) { 
        Point res = Point(x, y) * t; x = res.x, y = res.y; return *this; }
    Point& operator /= (const Point& t) { 
        Point res = Point(x, y) / t; x = res.x, y = res.y; return *this; }

    friend Point operator + (const Point& a, const Point& b) { return Point(a.x + b.x, a.y + b.y); }
    friend Point operator - (const Point& a, const Point& b) { return Point(a.x - b.x, a.y - b.y); }
    friend Point operator * (const Point& a, const T& t) { return Point(a.x * t, a.y * t); }
    friend Point operator * (const T& t ,const Point& a) { return Point(t * a.x, t * a.y); }
    friend Point operator / (const Point& a, const T& t) { return Point(a.x / t, a.y / t); }
    friend Point operator * (const Point& a, const Point& b) { 
        return Point(a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y); }
    friend Point operator / (const Point& a, const Point& b) { 
        return Point(a * conj(b) / norm(b)); }

    friend T int_norm(const Point& a) { return __gcd(a.x, a.y); }
    friend T int_unit(const Point& a) { if (a == Point()) return a; return a / int_norm(a); }

    friend T cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
    friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
    friend T area(const Point& a, const Point& b, const Point& c) { return cross(b - a, c - a); }

    // Returns conj(a) * b
    friend Point rotation(const Point& a, const Point& b) { return Point(dot(a, b), cross(a, b)); }

    friend bool same_dir(const Point& a, const Point& b) { return cross(a, b) == 0 && dot(a, b) > 0; }

    // check if 180 <= s..t < 360
    friend bool is_reflex(const Point& a, const Point& b) { 
        auto c = cross(a, b); return c ? (c < 0) : (dot(a, b) < 0); }

    // operator < (s, t) for angles in [base, base+2pi)
    friend bool angle_less(const Point& base, const Point& s, const Point& t) {
        int r = is_reflex(base, s) - is_reflex(base, t);
        return r ? (r < 0) : (0 < cross(s, t));
    }

    friend bool angle_cmp(const Point& base) {
        return [base](const Point& s, const Point& t) { return angle_less(base, s, t); };
    }
    friend bool angle_cmp_center(const Point& center, const Point& dir) {
        return [center, dir](const Point& s, const Point& t) -> bool { 
            return angle_less(dir, s - center, t - center); };
    }

    // is p in [s,t] taken ccw? 1/0/-1 for in/border/out
    friend int angle_between(const Point& s, const Point& t, const Point& p) {
        if (same_dir(p, s) || same_dir(p, t)) return 0;
        return angle_less(s, p, t) ? 1 : -1;
    }
};

namespace ConvexHull {

template <class T>
std::pair<std::vector<int>, std::vector<int>> upper_lower_hull(const std::vector<Point<T>>& v) {
    std::vector<int> p((int) v.size()), upper, lower;
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&v](int a, int b) { return v[a] < v[b]; });
    for (int& i : p) {
        while ((int) upper.size() > 1 && 
            area(v[upper[(int) upper.size() - 2]], v[upper.back()], v[i]) >= 0) 
            upper.pop_back();
        upper.push_back(i);
        while ((int) lower.size() > 1 && 
            area(v[lower[(int) lower.size() - 2]], v[lower.back()], v[i]) <= 0) 
            lower.pop_back();
        lower.push_back(i);
    }
    return {upper, lower};
}

template <class T> std::vector<int> hull_index(const std::vector<Point<T>>& v) {
    std::vector<int> upper, lower;
    tie(upper, lower) = upper_lower_hull(v);
    if ((int) lower.size() <= 1) 
        return lower;
    if (v[lower[0]] == v[lower[1]])
        return {0};
    lower.insert(lower.end(), 1 + upper.rbegin(), upper.rend() - 1);
    return lower;
}

template <class T> std::vector<Point<T>> convex_hull(const std::vector<Point<T>>& v) {
    std::vector<int> w = hull_index(v);
    std::vector<Point<T>> res;
    for (auto& t : w)
        res.push_back(v[t]);
    return res;
}

} // ConvexHull

namespace Geometry2D {

template <class T> int sign(T x) { return (x > 0) - (x < 0); }
template <class T> Point<T> reflect(const Point<T>& p, const Point<T>& a, const Point<T>& b) {
        return a + conj((p - a) / (b - a)) * (b - a); }
template <class T> Point<T> foot( const Point<T>& p, const Point<T>& a, const Point<T>& b) {
        return (p + reflect(p, a, b)) / (T) 2; }
template <class T> bool on_segment(Point<T> p, Point<T> a, Point<T> b) {
    return area(a, b, p) == 0 && dot(p - a, p - b) <= 0; }

template <class T>
std::vector<Point<T>> segment_intersect(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
    T x = area(a, b, c), y = area(a, b, d);
    T X = area(c, d, a), Y = area(c, d, b);
    if (sign(x) * sign(y) < 0 && sign(X) * sign(Y) < 0)
        return {(d * x - c * y) / (x - y)};
    std::set<Point<T>> s;
    if (on_segment(a, c, d))
        s.insert(a);
    if (on_segment(b, c, d))
        s.insert(b);
    if (on_segment(c, a, b))
        s.insert(c);
    if (on_segment(d, a, b))
        s.insert(d);
    return {s.begin(), s.end()};
}

template <class T> Point<T> extension(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
    T x = cross(a, b, c);
    T y = cross(a, b, d);
    return (d * x - c * y) / (x - y);
}

template <class T> std::pair<int, Point<T>> line_intersect(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
    // returns -1 if infinitely, 0 if none, 1 if unique 
    if (cross(b - a, d - c) == 0)
        return {-(cross(a, c, d) == 0), Point<T>()};
    else 
        return {1, extend(a, b, c, d)};
}

template <class T> T line_dist(Point<T> p, Point<T> a, Point<T> b) {
    return abs(area(p, a, b)) / abs(a - b); }

template <class T> T point_segment_dist(Point<T> p, Point<T> a, Point<T> b) {
    if (dot(p - a, b - a) <= 0)
        return abs(p - a);
    if (dot(p - b, a - b) <= 0)
        return abs(p - b);
    return line_dist(p, a, b);
}

template <class T> T segment_segment_dist(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
    std::vector<Point<T>> v = segment_intersect(a, b, c, d);
    if (!v.empty())
        return 0;
    return std::min({point_segment_dist(a, c, d), point_segment_dist(b, c, d), 
        point_segment_dist(c, a, b), point_segment_dist(d, a, b)});
}

template <class T> std::pair<Point<T>, T> centroid_area(const std::vector<Point<T>> v) {
    // pair of centroid and area, positive means CCW, negative means CW
    Point<T> centroid(0, 0);
    T area = 0;
    for (int i = 0; i < (int) v.size(); i++) {
        int j = (i + 1) % ((int) v.size());
        T a = cross(v[i], v[j]);
        centroid += a * (v[i] + v[j]);
        area += a;
    }
    return {centroid / area / (T) 3, area / 2};
}

template<class T> int polygon_point(const std::vector<Point<T>>& p, Point<T> z) {
    // returns -1 if outside, 0 if on, 1 if inside
    int n = (int) p.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        Point<T> x = p[i], y = p[(i + 1) % n];
        if (x.y > y.y) 
            std::swap(x, y);
        if (on_segment(z, x, y))
            return 0;
        ans ^= (x.y <= z.y && y.y > z.y && area(z, x, y) > 0);
    }
    return ans ? 1 : -1;
}

} // Geometry2D

namespace Hashing {

const int MOD = 1e9 + 7;

std::mt19937 rng((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);
const std::array<int, 2> base = {BDIST(rng), BDIST(rng)};
std::vector<std::array<int, 2>> pows = {{1, 1}};

std::array<int, 2> operator + (std::array<int, 2> l, std::array<int, 2> r) {
    for (int i = 0; i < 2; i++)
        if ((l[i] += r[i]) >= MOD)
            l[i] -= MOD;
    return l;
}

std::array<int, 2> operator - (std::array<int, 2> l, std::array<int, 2> r) {
    for (int i = 0; i < 2; i++)
        if ((l[i] -= r[i]) < 0)
            l[i] += MOD;
    return l;
}

std::array<int, 2> operator * (std::array<int, 2> l, std::array<int, 2> r) {
    for (int i = 0; i < 2; i++)
        l[i] = (long long) l[i] * r[i] % MOD;
    return l;
}

std::array<int, 2> make_hash(int c) {
    return {c, c};
}

struct HashRange {
    std::vector<std::array<int, 2>> pre = {{0, 0}};
    std::vector<int> s;

    void add(int c) {
        s.push_back(c);
        pre.push_back(base * pre.back() + make_hash(c));
    }

    void add(std::vector<int> t) {
        for (auto& c : t)
            add(c);
    }

    void extend(int len) {
        while ((int) pows.size() <= len)
            pows.push_back(base * pows.back());
    }
    
    std::array<int, 2> hash(int l, int r) {
        int len = r + 1 - l;
        extend(len);
        return pre[r + 1] - pows[len] * pre[l];
    }
};

} // Hashing

using namespace Hashing;
using namespace Geometry2D;
using namespace ConvexHull;

using P = Point<ll>;

int n, m;

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll av(ll x) {
    if (x < 0) return -x;
    return x;
}

vector<ll> gen(vector<P> v) {
    int sz = sz(v);
    vector<ll> res;
    f0r(i, sz) {
        int j = (i+1)%sz;
        int k = (i+2)%sz;
        ll d1 = norm(v[j]-v[i]);
        ll d2 = norm(v[j]-v[k]);
        ll d3 = norm(v[k]-v[i]);
        res.pb(d1);     
        int mult = 1;
        if (d1 + d2 > d3) mult = -1;
        res.pb(mult * area(v[i], v[j], v[k]));
    }
    return res;
}

bool is_rotation(vector<ll> a, vector<ll> b) {
    vi lps(n);
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < n) {
        if (a[i] == b[len]) {
            lps[i] = ++len;
            ++i;
        } else {
            if (len == 0) {
                lps[i] = 0;
                ++i;
            } else {
                len = lps[len - 1];
            }
        }
    }
    i = 0;
    for (int k = lps[n-1]; k < n; k++) {
        if (b[k] != a[i++]) 
            return false;
    }
    return true;
}

void no() {
    cout << "NO\n";
    exit(0);
}

void yes() {
    cout << "YES\n";
    exit(0);
}

template <class T> get_pos(vector<T> v, int x) {
    return lower_bound(all(v), x) - v.begin();
}

int mod(ll x) {
    return ((x%MOD) + MOD)%MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    vector<P> v1(n), v2(m);

    f0r(i, n) cin >> v1[i];
    f0r(i, m) cin >> v2[i];

    v1 = convex_hull(v1);
    v2 = convex_hull(v2);

    n = sz(v1);
    m = sz(v2);

    if (n != m) no();

    vector<ll> c1 = gen(v1);
    vector<ll> c2 = gen(v2);

    n = sz(c1);

    vector<ll> store;
    trav(t, c1) store.pb(t);
    trav(t, c2) store.pb(t);

    vi a(n), b(n);

    f0r(i, n) a[i] = mod(c1[i]), b[i] = mod(c2[i]);
    HashRange h1, h2;

    h1.add(a);
    h1.add(a);

    h2.add(b);

    f0r(i, n) {
        if (h1.hash(i, i+n-1) == h2.hash(0, n-1)) {
            yes();
        }
    }

    no();

    if (is_rotation(c1, c2)) yes();
    else no();

    return 0;
}