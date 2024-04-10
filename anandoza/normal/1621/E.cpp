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

    template <class T1, class T2> void re(pair<T1, T2> &p) { re(p.first, p.second); }
    template <class T> void re(vector<T> &a) { for (auto &x : a) re(x); }
    template <class T, size_t SZ> void re(array<T, SZ> &a) { for (auto &x : a) re(x); }
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
    template <class T1, class T2> void pr(const pair<T1, T2> &x) { pr("{", x.first, ", ", x.second, "}"); }
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
    template <typename I> struct _range_struct { const I first_, last_; explicit _range_struct(const I first, const I last) : first_{first}, last_{last} {} I begin() const { return first_; } I end() const { return last_; } };
    template <typename I> _range_struct<I> range(const I first, const I last) { return _range_struct<I>(first, last); }
}
using namespace __algorithm;

namespace __io {
    void setIO() { ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(15); }
}
using namespace __io;
// }}}
// frac {{{
template<typename v_t = long long> struct frac {
    v_t n, d;
    frac(v_t _n, v_t _d = 1) : n(_n), d(_d) {
        assert(n != 0 || d != 0);
        if (d < 0) { n *= -1; d *= -1; }
        v_t g = gcd(abs(n), d);
        n /= g;
        d /= g;
    }
    friend ostream& operator << (ostream& o, const frac& f) {
        return o << f.n << "/" << f.d;
    }

#define define_relational_operator(OP) \
    friend bool operator OP (const frac& a, const frac& b) { \
        return a.n * b.d OP b.n * a.d; \
    }
    define_relational_operator(<)
    define_relational_operator(<=)
    define_relational_operator(==)
    define_relational_operator(!=)
    define_relational_operator(>)
    define_relational_operator(>=)

    friend frac min(const frac a, const frac b) { return a <= b ? a : b; }
    friend frac max(const frac a, const frac b) { return a >= b ? a : b; }

    frac& operator += (const frac& b) { return *this = frac(n*b.d+b.n*d, d*b.d); }
    frac& operator -= (const frac& b) { return *this = frac(n*b.d-b.n*d, d*b.d); }
    frac& operator *= (const frac& b) { return *this = frac(n*b.n, d*b.d); }
    frac& operator /= (const frac& b) { return *this = frac(n*b.d, d*b.n); }
    friend frac operator + (const frac& a, const frac& b) { return frac(a) += b; }
    friend frac operator - (const frac& a, const frac& b) { return frac(a) -= b; }
    friend frac operator * (const frac& a, const frac& b) { return frac(a) *= b; }
    friend frac operator / (const frac& a, const frac& b) { return frac(a) /= b; }

    explicit operator double() const { return double(n)/d; }
    v_t floor() { assert(d > 0); return n / d - ((n < 0) && (n % d)); }
    v_t ceil() { assert(d > 0); return n / d + ((n > 0) && (n % d)); }

    // canonical continued fraction
    vector<v_t> to_cont() const {
        if (d == 0) return { LLONG_MAX };
        vector<v_t> cont;
        for (v_t n = this->n, d = this->d; ; swap(n, d)) {
            v_t f = (n >= 0 ? n : n - d + 1) / d;
            cont.push_back(f);
            n -= f * d;
            if (n == 0) break;
        }
        return cont;
    }

    static frac from_cont(const vector<v_t>& cont) {
        v_t n = 1, d = 0;
        for (int i = int(cont.size()) - 1; i >= 0; i--) {
            swap(n, d);
            n += d * cont[i];
        }
        return { n, d };
    }

    // "best" fraction in (x, y): minimizes both n and d
    friend frac best_in(const frac x, const frac y) {
        assert(x < y);

        vector<v_t> x1 = x.to_cont(), y1 = y.to_cont();
        vector<v_t> x2 = x1; x2.back()--; x2.push_back(1);
        vector<v_t> y2 = y1; y2.back()--; y2.push_back(1);

        auto z = [](const vector<v_t>& a, const vector<v_t>& b) {
            vector<v_t> c;
            for (int i = 0; ; i++) {
                v_t ai = i < a.size() ? a[i] : LLONG_MAX;
                v_t bi = i < b.size() ? b[i] : LLONG_MAX;
                if (ai != bi) {
                    c.push_back(min(ai, bi) + 1);
                    return from_cont(c);
                }
                c.push_back(ai);
            }
        };

        frac ans = { 1, 0 };
        for (const frac f : {z(x1, y1), z(x1, y2), z(x2, y1), z(x2, y2)}) {
            if (x < f && f < y && (ans.d == 0 || f.d < ans.d))
                ans = f;
        }
        return ans;
    }
};
// }}}
// segment_tree {{{
#include <vector>
#include <cassert>

template<typename T, typename AssociativeOperation>
struct segment_tree {
    int SZ;
    T identity;
    AssociativeOperation TT;
    std::vector<T> data;

    segment_tree() {}

    segment_tree(int _SZ, T _identity, AssociativeOperation _TT)
            : SZ(_SZ), identity(_identity), TT(_TT) {
        data.resize(2 * SZ, identity);
    }

    // Returns the value at index i
    const T& operator[](int i) const {
        assert(0 <= i && i < SZ);
        return data[SZ + i];
    }

    // Assigns fn(i) at index i for each i in [0, SZ)
    template<typename Function>
    void assign(Function fn) {
        for (int i = 0; i < SZ; i++)
            data[SZ + i] = fn(i);
        for (int i = SZ - 1; i; i--)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
    }

    // Assigns v at index i
    void assign(int i, T v) {
        assert(0 <= i && i < SZ);
        data[i += SZ] = v;
        for (i /= 2; i; i /= 2)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
    }

    // Returns the result of a left fold of the elements at indices in [first, last) over TT
    T accumulate(int first, int last) const {
        assert(0 <= first && last <= SZ);
        T left = identity, right = identity;
        for (first += SZ, last += SZ; first < last; first /= 2, last /= 2) {
            if (first & 1) left  = TT(left, data[first++]);
            if (last  & 1) right = TT(data[--last], right);
        }
        return TT(left, right);
    }
};
// }}}

// clang-format on

using F = frac<ll>;

void solve() {
    int n, m;
    re(n, m);
    vi t(n);
    re(t);
    sort(rall(t));

    vvi groups(m);
    vector<ll> sums;
    for (auto &g : groups) {
        int k;
        re(k);
        g.resize(k);
        re(g);

        sums.push_back(accumulate(all(g), 0LL));
    }

    vector<pair<F, int>> avg;
    for (int i = 0; i < m; i++) {
        avg.push_back({F(sums[i], sz(groups[i])), i});
    }
    sort(rall(avg));

    vector<int> inv(m);
    for (int i = 0; i < m; i++)
        inv[avg[i].second] = i;

    segment_tree none(m, false, L2(u, v, u || v));
    for (int i = 0; i < m; i++) {
        if (t[i] < avg[i].first)
            none.assign(i, true);
    }

    segment_tree lose(m, false, L2(u, v, u || v));
    for (int i = 0; i < m; i++) {
        if (i + 1 >= sz(t) || t[i + 1] < avg[i].first)
            lose.assign(i, true);
    }

    segment_tree gain(m, false, L2(u, v, u || v));
    for (int i = 1; i < m; i++) {
        if (i - 1 >= sz(t) || t[i - 1] < avg[i].first)
            gain.assign(i, true);
    }

    string ans = "";
    for (int i = 0; i < m; i++) {
        for (int v : groups[i]) {
            ll new_sum = sums[i] - v;
            F new_avg(new_sum, sz(groups[i]) - 1);

            int old_pos = inv[i];
            int new_pos = lower_bound(all(avg), make_pair(new_avg, i), std::greater<pair<F, int>>()) - avg.begin();

            if (new_pos > old_pos)
                new_pos--;

            pd(v, avg[old_pos], new_avg, old_pos, new_pos);

            bool bad = false;
            if (old_pos == new_pos) {
                bad |= none.accumulate(0, new_pos);
                bad |= none.accumulate(new_pos + 1, m);
                bad |= t[new_pos] < new_avg;
            } else {
                if (new_pos > old_pos) {
                    bad |= none.accumulate(0, old_pos);
                    bad |= gain.accumulate(old_pos + 1, new_pos + 1);
                    bad |= t[new_pos] < new_avg;
                    bad |= none.accumulate(new_pos + 1, m);
                } else {
                    bad |= none.accumulate(0, new_pos);
                    bad |= t[new_pos] < new_avg;
                    bad |= lose.accumulate(new_pos, old_pos);
                    bad |= none.accumulate(old_pos + 1, m);
                }
            }

            ans.push_back(bad ? '0' : '1');
        }
    }

    ps(ans);
}

int main() {
    setIO();

    int T;
    re(T);
    for (int t = 0; t < T; t++)
        solve();

    return 0;
}