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
// sieve {{{
enum DIVISOR_TYPE { ALL, SQUARE_FREE };
template<int MAXV> struct sieve {
    vi primes;
    struct num {
        int  least_prime;       // least prime divisor
        int  div_least_prime;   // num divided by least_prime
        char lp_multiplicity;   // multiplicity of the least prime divisor
        char mu;                // mobius function
        int  phi;               // euler's totient function

        static num ONE() { return { INT_MAX, 1, 0, 1, 1}; }

        num prod(int my_value, int p) const {
            if (p < least_prime)
                return { p, my_value, 1, char(-mu), phi * (p - 1) };
            assert(p == least_prime);
            return { p, my_value, char(lp_multiplicity + 1), 0, phi * p };
        }
    };
    vector<num> nums;
    const num& operator[](int i){ return nums[i]; }

    sieve() : nums(MAXV) {
        nums[1] = num::ONE();
        for (int v = 2; v < MAXV; v++) {
            num& n = nums[v];
            if (!n.least_prime) {
                n = nums[1].prod(1, v);
                primes.pb(v);
            }
            for (int p : primes) {
                if (p > n.least_prime || v * p >= MAXV) break;
                nums[v * p] = n.prod(v, p);
            }
        }
    }

    bool is_prime(int v) const {
        assert(0 < v && v < MAXV);
        return nums[v].least_prime == v;
    }

    int eliminate_least_prime(int v) const {
        assert(1 < v && v < MAXV);
        for (int m = nums[v].lp_multiplicity; m > 0; m--)
            v = nums[v].div_least_prime;
        return v;
    }

    const vpii& factor(int v) const {
        assert(0 < v && v < MAXV);
        static vpii res; res.clear();
        for (; v > 1; v = eliminate_least_prime(v))
            res.emplace_back(nums[v].least_prime, nums[v].lp_multiplicity);
        reverse(all(res));
        return res;
    }

    template<typename F> void for_each_divisor_unordered(int v, F f,
            DIVISOR_TYPE t = ALL, int d = 1) const {
        assert(0 < v && v < MAXV);
        if (v == 1) { f(d); return; }
        int w = eliminate_least_prime(v);
        char M = min(nums[v].lp_multiplicity, char(t == ALL ? CHAR_MAX : 1));
        for (int m = 0; m <= M; m++, d *= nums[v].least_prime) {
            for_each_divisor_unordered(w, f, t, d);
        }
    }

    const vi& unordered_divisors(int v, DIVISOR_TYPE t = ALL) const {
        assert(0 < v && v < MAXV);
        static vi res; res.clear();
        for_each_divisor_unordered(v, [&](int d) { res.pb(d); }, t);
        return res;
    }
};
// }}}

// clang-format on

constexpr int INF = 1e9;

constexpr int MAX = 3e5 + 1;
sieve<MAX> sv;

int main() {
    setIO();

    int n;
    re(n);
    vi a(n);
    re(a);
    dedup(a);
    n = sz(a);

    vi count(MAX);

    for (int x : a) {
        auto f = sv.factor(x);
        sv.for_each_divisor_unordered(x, [&](int d) { count[d]++; });
    }

    vvi primes(MAX);
    for (int i = 1; i < MAX; i++) {
        auto f = sv.factor(i);
        for (auto [p, e] : f) {
            primes[i].push_back(p);
        }
    }

    // count elements that are multiples of d * some_factor_of_x
    auto count_pie = [&](int x, int d) {
        int k = sz(primes[x]);
        ll sum = 0;
        for (int mask = 1; mask < 1 << k; mask++) {
            int parity = __builtin_popcount(mask) % 2 ? 1 : -1;
            int prod = d;
            for (int i = 0; i < k; i++) {
                if ((mask >> i) & 1)
                    prod *= primes[x][i];
            }
            sum += parity * count[prod];
        }
        return sum;
    };

    vi dist(MAX, INF);
    for (int x : a)
        dist[x] = 1;

    for (int i = MAX - 1; i >= 1; i--) {
        for (int j = i; j < MAX; j += i) {
            int not_helpful = count_pie(j / i, i);
            int total = count[i];

            if (not_helpful != total)
                ckmin(dist[i], dist[j] + 1);
        }
    }

    int ans = dist[1];

    if (ans == INF)
        ans = -1;
    ps(ans);

    return 0;
}