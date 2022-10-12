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
// modnum {{{
#include <cstdint>
#include <cassert>
#include <limits>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <unordered_map>

using v_t = int;
using vv_t = int64_t;

template<v_t MOD> struct modnum {
    static_assert(std::numeric_limits<v_t>::max() / 2 >= MOD, "Addition overflows v_t");
    static_assert(std::numeric_limits<vv_t>::max() / MOD >= MOD, "Multiplication overflows vv_t");

    v_t v;
    modnum() : v(0) {}
    modnum(vv_t _v) : v(v_t(_v % MOD)) { if (v < 0) v += MOD; }
    explicit operator v_t() const { return v; }
    friend std::istream& operator >> (std::istream& i, modnum& n) { vv_t w; i >> w; n = modnum(w); return i; }
    friend std::ostream& operator << (std::ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
    friend bool operator <  (const modnum& a, const modnum& b) { return a.v <  b.v; }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // x must be less than 2^32 * m so that x / m fits in a 32-bit integer.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
        asm("divl %4\n"
                : "=a" (quot), "=d" (rem)
                : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = fast_mod(vv_t(v) * o.v); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(vv_t e) const {
        if (e < 0) return 1 / this->pow(-e);
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        v_t g = MOD, x = 0, y = 1;
        for (v_t r = v; r != 0; ) {
            v_t q = g / r;
            g %= r; std::swap(g, r);
            x -= q * y; std::swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }

    static constexpr v_t totient() {
        v_t tot = MOD, tmp = MOD;
        for (v_t p = 2; p * p <= tmp; p++) if (tmp % p == 0) {
            tot = tot / p * (p - 1);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot = tot / tmp * (tmp - 1);
        return tot;
    }

    static v_t primitive_root() {
        if (MOD == 1) return 0;
        if (MOD == 2) return 1;

        v_t tot = totient(), tmp = tot;
        std::vector<int> tot_pr;
        for (v_t p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);

        for (v_t r = 2; r < MOD; r++) if (std::gcd(r, MOD) == 1) {
            bool root = true;
            for (v_t p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }

    static modnum generator() { static modnum g = primitive_root(); return g; }
    static v_t discrete_log(modnum v) {
        static const v_t M = ceil(std::sqrt(MOD));
        static std::unordered_map<v_t, v_t> table;
        if (table.empty()) {
            modnum e = 1;
            for (v_t i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }
        }
        static modnum f = generator().pow(totient() - M);

        for (v_t i = 0; i < M; i++) {
            if (table.count(v.v)) return table[v.v] + i * M;
            v *= f;
        }
        assert(false);
    }

    static modnum unity_root(int deg) {
        assert(totient() % deg == 0);
        return generator().pow(totient() / deg);
    }

    static modnum unity_root(int deg, int pow) {
        static std::vector<modnum> table{ 0, 1 };
        while (int(table.size()) <= deg) {
            modnum w = unity_root(int(table.size()));
            for (int s = int(table.size()), i = s / 2; i < s; i++) {
                table.push_back(table[i]);
                table.push_back(table[i] * w);
            }
        }
        return table[deg + (pow < 0 ? deg + pow : pow)];
    }

    static modnum factorial(int n) {
        static std::vector<modnum> fact = {1};
        assert(n >= 0);
        if (int(fact.size()) <= n) {
            int had = fact.size();
            fact.resize(n + 1);
            for (int i = had; i <= n; i++) fact[i] = fact[i-1] * i;
        }
        return fact[n];
    }
    static modnum inverse_factorial(int n) {
        static std::vector<modnum> finv = {1};
        assert(n >= 0);
        if (int(finv.size()) <= n) {
            int had = finv.size();
            finv.resize(n + 1), finv[n] = factorial(n).inv();
            for (int i = n - 1; i >= had; i--) finv[i] = finv[i+1] * (i+1);
        }
        return finv[n];
    }

    static modnum small_inv(int n) {
        assert(n > 0); return factorial(n - 1) * inverse_factorial(n);
    }

    static modnum ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        return factorial(n) * inverse_factorial(r) * inverse_factorial(n - r);
    }
};
// }}}
// polynomial_hash {{{
// {{{ numeric/modnum.cpp }}}

#include <vector>
#include <chrono>
#include <random>
#include <array>
#include <cassert>
#include <iostream>

template<typename x_t, int EvaluationPoints, int AlphabetSize>
struct polynomial_hash {
    static x_t pow(int point, int exponent) {
        static std::vector<x_t> x(EvaluationPoints, 1);

        if (int(x.size()) == EvaluationPoints) {
            x.push_back(AlphabetSize);

            std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

            for (int i = 1; i < EvaluationPoints; i++)
                x.push_back(AlphabetSize + rng() % std::max(256, AlphabetSize));
        }

        while (exponent * EvaluationPoints + point >= int(x.size()))
            for (int i = 0; i < EvaluationPoints; i++)
                x.push_back(*(x.end() - EvaluationPoints) * x[EvaluationPoints + i]);

        return x[exponent * EvaluationPoints + point];
    }

    int N;
    std::array<x_t, EvaluationPoints> data;

    polynomial_hash () : N(0) { data.fill(0); }

    polynomial_hash (x_t v) : N(1) { assert(v.v < AlphabetSize); data.fill(v); }

    polynomial_hash (int _N, std::array<x_t, EvaluationPoints> _data) : N(_N), data(_data) {}

    static polynomial_hash concatenate(const polynomial_hash& a, const polynomial_hash& b) {
        std::array<x_t, EvaluationPoints> res;
        for (int i = 0; i < EvaluationPoints; i++)
            res[i] = a.data[i] * pow(i, b.N) + b.data[i];
        return { a.N + b.N, res };
    }

    void extend(const polynomial_hash& b) {
        for (int i = 0; i < EvaluationPoints; i++)
            data[i] = data[i] * pow(i, b.N) + b.data[i];
        N += b.N;
    }

    void square() {
        for (int i = 0; i < EvaluationPoints; i++)
            data[i] = data[i] * pow(i, N) + data[i];
        N += N;
    }

    bool operator == (const polynomial_hash &o) const {
        return N == o.N && data == o.data;
    }

    bool operator < (const polynomial_hash &o) const {
        return N != o.N ? N < o.N : data < o.data;
    }

    friend std::ostream& operator << (std::ostream& o, const polynomial_hash& h) {
        o << h.N;
        for (int i = 0; i < EvaluationPoints; i++)
            o << " " << h.data[i];
        return o;
    }

    template<typename InputIterator>
    static std::vector<polynomial_hash> get_prefixes(InputIterator begin, InputIterator end) {
        std::vector<polynomial_hash> res = { polynomial_hash{} };
        for (InputIterator iter = begin; iter != end; iter = next(iter))
            res.push_back(concatenate(res.back(), polynomial_hash(x_t(*iter))));
        return res;
    }

    static polynomial_hash get_substring(const std::vector<polynomial_hash> &prefixes, int first, int last) {
        std::array<x_t, EvaluationPoints> res;
        for (int i = 0; i < EvaluationPoints; i++)
            res[i] = prefixes[last].data[i] - pow(i, last - first) * prefixes[first].data[i];
        return { last - first, res };
    }
};
// }}}

// clang-format on

using H = polynomial_hash<modnum<int(1e9 + 7)>, 2, 256>;

string rep(const string &s, int n) {
    string ans;
    for (int i = 0; i < n; i++)
        ans += s;
    return ans;
}

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

int main() {
    setIO();

    int n, k;
    re(n, k);
    string s;
    re(s);

    if (n > k) {
        n = k;
    }
    s.resize(n);

    for (int i = 1; i < n; i++) {
        if (s[i] > s[0]) {
            s.resize(i);
            break;
        }
    }
    n = sz(s);

    auto slow = [&]() {
        string ans = rep(s.substr(0, 1), k);
        vector<pair<pair<string, string>, int>> cand;
        for (int i = 1; i <= n; i++) {
            string block = s.substr(0, i);
            string res;
            while (sz(res) < k)
                res += block;
            res.resize(k);
            ckmin(ans, res);

            cand.push_back({{res, block}, i});
        }
        sort(all(cand));
        for (auto i : cand)
            pd(i);
        vi score(n);
        for (int i = 0; i < n; i++)
            score[cand[i].s - 1] = i;
        for (int i = 0; i < n; i++) {
            pd(i, score[i]);
        }
        return ans;
    };

#ifdef ANAND_LOCAL
    auto slow_ans = slow();
#endif

    auto s_prefixes = H::get_prefixes(all(s));

    auto get_hash = [&](int len, int target) {
        auto block = H::get_substring(s_prefixes, 0, len);
        int so_far = 0;
        H hash;

        int b = target / len;

        while (b > 0) {
            if (b & 1) {
                hash.extend(block);
                so_far = so_far + len;
            }
            block.square();
            len *= 2;
            b >>= 1;
        }

        int leftover = target - so_far;
        hash.extend(H::get_substring(s_prefixes, 0, leftover));
        return hash;
    };

    int best = n;
    for (int i = n; i >= 1; i--) {
        auto is_diff = [&](int target) { return !(get_hash(i, target) == get_hash(best, target)); };
        int first_diff = binarysearch(is_diff, 1, k + 1);
        if (first_diff == k + 1)
            continue;
        int index = first_diff - 1;
        char ours = s[index % i], theirs = s[index % best];
        assert(ours != theirs);
        if (ours < theirs)
            best = i;
    }

    s.resize(best);

    string ans;
    while (sz(ans) < k)
        ans += s;
    ans.resize(k);
    ps(ans);

#ifdef ANAND_LOCAL
    pd(ans);
    pd(slow_ans);
    // assert(ans == slow_ans);
#endif

    return 0;
}