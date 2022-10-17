#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++) 
#define f0r(i, a) f1r(i, 0, a)
#define trav(t, a) for (auto& t : a)
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;
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

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    // BEGIN TESTING
    // vector<Point<ll>> v(n);
    // f0r(i, n) {
    //     cin >> v[i].x >> v[i].y;
    // }
    // auto sign = [&](ll x) -> int {
    //     if (x > 0) return 1;
    //     if (x < 0) return -1;
    //     return 0;
    // };
    // auto respond = [&](int t, int x, int y, int z) -> ll {
    //     x--, y--, z--;
    //     if (t == 2) {
    //         return abs(area(v[x], v[y], v[z]));
    //     } else {
    //         return sign(cross(v[y]-v[x], v[z]-v[x]));
    //     }
    // };
    auto query = [&](int t, int x, int y, int z) {
        // try to give this to me in counter clockwise order
        // if query t = 1, x, y, z in CCW returns +, else returns -
        cout << t << " " << y+1 << " " << z+1 << " " << x+1 << endl;
        ll ret; 
        // ret = respond(t,y+1, z+1, x+1);
        // cout << ret << endl;
        cin >> ret;
        return ret;
    };
    int e1 = 0;
    int e2 = 1;
    vi L, R;
    vl A(n);
    f1r(i, 2, n) { 
        if (query(2, e1, i, e2) > 0) {
            R.pb(i);
        } else {
            L.pb(i);
        }
    }
    int nl = sz(L);
    int nr = sz(R);
    f1r(i, 2, n) {
        A[i] = query(1, e1, e2, i);
    }
    vi hull;
    hull.pb(e2);
    {
        sort(all(L), [&](int x, int y) {
            return A[x] < A[y];
        });
        deque<int> d;
        int big = -1;
        if (sz(L)) big = L.back();
        while (sz(L)) {
            int x = L.back();
            L.pop_back();
            if (sz(d) == 0) {
                d.pb(x);
            } else {
                if (query(2, e2, x, big) > 0) {
                    d.push_front(x);
                } else {
                    d.push_back(x);
                }
            }
        }
        for (int x : d) hull.pb(x);
        hull.pb(e1);
    }
    {
        sort(all(R), [&](int x, int y) {
            return A[x] < A[y];
        });
        deque<int> d;
        int big = -1;
        if (sz(R)) big = R.back();
        while (sz(R)) {
            int x = R.back();
            R.pop_back();
            if (sz(d) == 0) {
                d.pb(x);
            } else {
                if (query(2, e1, x, big) > 0) {
                    d.push_front(x);
                } else {
                    d.push_back(x);
                }
            }
        }
        for (int x : d) hull.eb(x);
    }
    cout << 0 << " ";
    vi res;
    int id = 0;
    f0r(i, n) {
        if (hull[i] == 0) id = i;
    }
    f0r(i, n) {
        res.eb(hull[(id+i)%n]);
    }
    for (int x : res) {
        cout << x+1 << " ";
    }
    cout << endl;

    return 0;
}