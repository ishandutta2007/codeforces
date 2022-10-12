#include <bits/stdc++.h>
using namespace std;

// clang-format off
// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)

#define L1(u, ...) [&](auto &&u) { return __VA_ARGS__; }
#define L2(u, v, ...) [&](auto &&u, auto &&v) { return __VA_ARGS__; }

#define sort_by(x, y) sort(all(x), [&](const auto &l, const auto &r) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template <typename T> void ckmin(T &a, const T &b) { a = min(a, b); }
template <typename T> void ckmax(T &a, const T &b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template <class T1, class T2> void re(pair<T1, T2> &p);
    template <class T> void re(vector<T> &a);
    template <class T, size_t SZ> void re(array<T, SZ> &a);

    template <class T> void re(T &x) { cin >> x; }
    void re(double &x) { string t; re(t); x = stod(t); }
    template <class Arg, class... Args> void re(Arg &first, Args &...rest) { re(first); re(rest...); }

    template <class T1, class T2> void re(pair<T1, T2> &p) { re(p.f, p.s); }
    template <class T> void re(vector<T> &a) { for (int i = 0; i < sz(a); i++) re(a[i]); }
    template <class T, size_t SZ> void re(array<T, SZ> &a) { for (int i = 0; i < SZ; i++) re(a[i]); }
}
using namespace __input;

namespace __output {
    template <typename T> struct is_outputtable { template <typename C> static constexpr decltype(declval<ostream &>() << declval<const C &>(), bool()) test(int) { return true; } template <typename C> static constexpr bool test(...) { return false; } static constexpr bool value = test<T>(int()); };
    template <class T, typename V = decltype(declval<const T &>().begin()), typename S = typename enable_if<!is_outputtable<T>::value, bool>::type> void pr(const T &x);

    template <class T, typename V = decltype(declval<ostream &>() << declval<const T &>())> void pr(const T &x) { cout << x; }
    template <class T1, class T2> void pr(const pair<T1, T2> &x);
    template <class Arg, class... Args> void pr(const Arg &first, const Args &...rest) { pr(first); pr(rest...); }

    template <class T, bool pretty = true> void prContain(const T &x) { if (pretty) pr("{"); bool fst = 1; for (const auto &a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0; if (pretty) pr("}"); }

    template <class T> void pc(const T &x) { prContain<T, false>(x); pr("\n"); }
    template <class T1, class T2> void pr(const pair<T1, T2> &x) { pr("{", x.f, ", ", x.s, "}"); }
    template <class T, typename V, typename S> void pr(const T &x) { prContain(x); }

    void ps() { pr("\n"); }
    template <class Arg> void ps(const Arg &first) { pr(first); ps(); }
    template <class Arg, class... Args> void ps(const Arg &first, const Args &...rest) { pr(first, " "); ps(rest...); }
}
using namespace __output;

#define __pn(x) pr(#x, " = ")
#ifdef ANAND_LOCAL
#define pd(...) pr("\033[1;31m"), __pn((__VA_ARGS__)), ps(__VA_ARGS__), pr("\033[0m"), cout << flush
#else
#define pd(...)
#endif

namespace __algorithm {
    template <typename T> void dedup(vector<T> &v) { sort(all(v)); v.erase(unique(all(v)), v.end()); }
    template <typename T> typename vector<T>::const_iterator find(const vector<T> &v, const T &x) { auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end(); }
    template <typename T> size_t index(const vector<T> &v, const T &x) { auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin(); }
    template <typename I> struct _reversed_struct { I &v_; explicit _reversed_struct(I &v) : v_{v} {} typename I::reverse_iterator begin() const { return v_.rbegin(); } typename I::reverse_iterator end() const { return v_.rend(); } };
    template <typename I> _reversed_struct<I> reversed(I &v) { return _reversed_struct<I>(v); }
}
using namespace __algorithm;

namespace __io {
    void setIO() { ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(15); }
}
using namespace __io;
// }}}
// point {{{
#include <iostream>
#include <vector>

template<typename T>
struct point {
    T x, y;
    point() : x(0), y(0) {}
    point(T _x, T _y) : x(_x), y(_y) {}
    friend std::istream& operator >> (std::istream& i, point& p) { return i >> p.x >> p.y; }
    friend std::ostream& operator << (std::ostream& o, const point& p) {
        return o << "(" << p.x << ", " << p.y << ")";
    }

    T norm() const { return x * x + y * y; }
    double len() const { return sqrt(norm()); }
    double ang() const { return atan2(y, x); }
    point<T> conj() const { return { x, -y }; }

    point& operator += (const point& o) { x += o.x; y += o.y; return *this; }
    point& operator -= (const point& o) { x -= o.x; y -= o.y; return *this; }
    point& operator *= (const T& c) { x *= c; y *= c; return *this; }
    point& operator /= (const T& c) { x /= c; y /= c; return *this; }
    friend point operator + (const point& a, const point& b) { return point(a) += b; }
    friend point operator - (const point& a, const point& b) { return point(a) -= b; }
    friend point operator * (const point& a, const T& c) { return point(a) *= c; }
    friend point operator * (const T& c, const point& a) { return point(a) *= c; }
    friend point operator / (const point& a, const T& c) { return point(a) /= c; }

    bool operator == (const point& o) const { return x == o.x && y == o.y; }
    bool operator != (const point& o) const { return x != o.x || y != o.y; }
    bool operator < (const point& o) const { return (x != o.x) ? x < o.x : y < o.y; }
    bool operator > (const point& o) const { return (x != o.x) ? x > o.x : y > o.y; }
    bool operator <= (const point& o) const { return !(*this > o); }

    friend T dot(const point& a, const point& b) { return a.x * b.x + a.y * b.y; }
    friend T cross(const point& a, const point& b) { return a.x * b.y - a.y * b.x; }
    friend T cross(const point& p, const point& a, const point& b) { return cross(a - p, b - p); }

    friend point<T> operator * (const point& a, const point& b) {
        return { a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x };
    }
    friend point<T> operator / (const point& a, const point& b) {
        return a * b.conj() / b.norm();
    }

    point dir() const { return point(*this) / len(); }
    point rotate(const double& ang) const { return *this * point(cos(ang), sin(ang)); }

    double dist(const point& a) const { return (a - *this).len(); }
    double dist(const point& a, const point& b) {
        return abs(cross(*this, a, b)) / a.dist(b);
    }
    point reflect(const point& a, const point& b) const {
        return a + ((*this - a) / (b - a)).conj() * (b - a);
    }
    point foot(const point& a, const point& b) const {
        return (*this + this->reflect(a, b)) / 2;
    }
    friend point extension(const point& a, const point& b, const point& c, const point& d) {
        T u = cross(a, b, c), v = cross(a, b, d);
        return (d * u - c * v) / (u - v);
    }

    using polygon = std::vector<point<T>>;

    friend polygon seg_intersect(point a, point b, point c, point d) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);

        T a1 = cross(a, b, c), a2 = cross(a, b, d);
        if (a1 > a2) swap(a1, a2);
        if (!(a1 <= 0 && a2 >= 0)) return {};

        if (a1 == 0 && a2 == 0) {
            if (cross(a, c, d) != 0) return {};
            point<T> x1 = max(a, c), x2 = min(b, d);
            if (x1 > x2) return {};
            if (x1 == x2) return { x1 };
            return { x1, x2 };
        }

        point<T> z = extension(a, b, c, d);
        if (a <= z && z <= b) return { z };
        return {};
    }

    friend std::ostream& operator << (std::ostream& o, const polygon& poly) {
        o << "{";
        for (auto pt : poly) o << " " << pt;
        return o << " }";
    }

    enum class Classification { in, out, on };
    Classification classify(const polygon& p) const {
        bool ans = 0;
        for (int i = 0; i < int(p.size()); i++) {
            point<T> a = p[i], b = p[(i + 1) % p.size()];
            if (cross(a, b, *this) == 0 && min(a, b) <= *this && *this <= max(a, b))
                return Classification::on;
            if (a.y > b.y) swap(a, b);
            if (a.y <= y && y < b.y && cross(*this, a, b) > 0) ans ^= 1;
        }
        return ans ? Classification::in : Classification::out;
    }

    friend polygon convex_hull(const std::vector<point>& pts) {
        point pivot = *min_element(all(pts));
        auto sorted = pts;
        sort(all(sorted), [&pivot](const point& p, const point& q) {
            T cp = cross(pivot, p, q);
            if (cp != 0) return cp > 0;
            return pivot.dist(p) < pivot.dist(q);
        });

        int j = 0;
        polygon res(pts.size());
        for (const point& p : sorted) {
            while (j > 1 && cross(res[j - 2], res[j - 1], p) <= 0)
                j--;
            res[j++] = p;
        }
        res.erase(res.begin() + j, res.end());
        return res;
    }

    // twice the signed area
    friend T area(const polygon& p) {
        T a = 0;
        for (int i = 0; i < int(p.size()); i++)
            a += cross(p[i], p[i+1 < sz(p) ? i+1 : 0]);
        return a;
    }

    // sorts CCW for vectors in the same half-plane
    template <typename U> static int sign(const U &v) { return (v > 0) - (v < 0); }
    friend int compare_by_angle(const point &a, const point &b) { return sign(cross(b, a)); }
    friend int compare_by_angle(const point &a, const point &b, const point &origin) { return sign(cross(origin, b, a)); }

    // sorts by angle CCW from the positive x-axis
    template <typename I> friend void sort_by_angle(I first, I last, const point<T> &origin = point<T>{}) {
        first = partition(first, last, [&](const point<T> &p) { return p == origin; });
        auto pivot = partition(first, last, [&](const point<T> &p) { return p > origin; });
        auto compare = [&](const point<T> &l, const point<T> &r) { return compare_by_angle(l, r, origin) < 0; };
        sort(first, pivot, compare);
        sort(pivot, last, compare);
    }
};
// }}}

using P = point<double>;
const double PI = acos(-1);
const double PI2 = 2 * PI;
const double EPS = 1e-11;

// clang-format on

// Returns first i in [l, r] s.t. predicate(i) is true. Never evaluates r.
template <typename I, typename P> I binarysearch(const P &predicate, I l, I r) {
    l--;
    while (r - l > 1) {
        auto mid = l + (r - l) / 2;
        if (predicate(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

int ITER = 60;

template <typename I, typename F> I find_zero(const F &f, I l, I r) {
    for (int iter = 0; iter < ITER; iter++) {
        I m = l + (r - l) / 2;
        auto val = f(m);
        if (abs(val) < 1e-4)
            break;
        if (val > 0)
            r = m;
        else
            l = m;
    }
    return (l + r) / 2;
}

int main() {
    setIO();

    int n, q;
    re(n, q);
    vector<P> poly(n);
    re(poly);
    reverse(poly.begin() + 1, poly.end());

    vector<double> pieces(n);
    for (int i = 0; i < n; i++) {
        pieces[i] = cross(poly[i], poly[(i + 1) % n]);
    }
    vector<double> prefix_sum(n + 1);
    for (int i = 0; i < n; i++)
        prefix_sum[i + 1] = prefix_sum[i] + pieces[i];
    double target = prefix_sum.back() / 2;
    double scale = 1 / max(1.0, abs(target));

    for (int query = 0; query < q; query++) {
        P o;
        re(o);

        auto find_area = [&](double angle) -> double {
            auto find_index = [&](double angle) -> int {
                P rot = P{cos(angle), -sin(angle)};
                auto find_angle = [&](const P &p) {
                    P r = (p - o) * rot;
                    return r;
                };

                P a_front = find_angle(poly.front());
                bool top = a_front.y > 0;
                int offset = binarysearch(
                    [&](int u) {
                        P a = find_angle(poly[u]);
                        if ((a.y > 0) ^ top)
                            return a.y > 0;
                        return cross(a, a_front) > 0;
                    },
                    0, n);
                return (offset + n - 1) % n;
            };

            P dir = o + P{cos(angle), sin(angle)};
            int l = find_index(angle);
            int r = find_index(angle + PI);
            P u = extension(o, dir, poly[l], poly[(l + 1) % n]);
            P v = extension(o, dir, poly[r], poly[(r + 1) % n]);
            if (dot(dir - o, u - o) <= 0) {
                swap(l, r);
                swap(u, v);
            }

            double A = 0;
            A += cross(u, poly[(l + 1) % n]);
            A += cross(poly[r], v);
            A += cross(v, u);
            l = l % n;
            if (r < l + 1)
                A += prefix_sum.back();
            A += prefix_sum[r] - prefix_sum[l + 1];

            return (A - target) * scale;
        };

        double a_zero = find_area(0);

        if (abs(a_zero) < EPS) {
            ps(0);
            continue;
        }

        bool reverse = a_zero > 0;
        double ans;
        if (reverse)
            ans = find_zero(find_area, PI, 0.0);
        else
            ans = find_zero(find_area, 0.0, PI);

        ps(ans);
    }

    return 0;
}