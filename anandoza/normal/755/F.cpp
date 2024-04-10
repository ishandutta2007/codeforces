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
#include <bitset>
#include <vector>
#include <cassert>

/* Accepts a collection of integers with sum at most MAX_SUM.
 * Computes its set of subset sums in O(MAX_SUM * sqrt(sum) / MACHINE_WORD_SIZE)
 */
template<int MAX_SUM, typename InputIterator>
std::bitset<MAX_SUM + 1> subset_sum(InputIterator first, InputIterator last) {
    int sum = accumulate(first, last, 0);
    assert(sum <= MAX_SUM);

    static std::vector<int> count(MAX_SUM + 1);

    for (InputIterator iter = first; iter != last; iter++)
        count[*iter]++;

    std::bitset<MAX_SUM + 1> result;
    result[0] = 1;

    for (int val = 1; val <= sum; val++) {
        if (count[val] > 2) {
            int pairs = (count[val] - 1) / 2;
            count[2 * val] += pairs;
            count[val] -= 2 * pairs;
        }

        while (count[val]) {
            result |= result << val;
            count[val]--;
        }
    }

    return result;
}

// clang-format on

vvi find_cycles(const vi &p) {
    const int n = sz(p);
    vb visited(n);

    vvi cycles;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        vi c;
        for (int j = i; c.empty() || j != i; j = p[j]) {
            c.push_back(j);
            visited[j] = true;
        }

        if (sz(c) > 1)
            cycles.push_back(c);
    }

    return cycles;
}

const int MAX = 1e6;

int main() {
    setIO();

    int n, k;
    re(n, k);
    vi p(n);
    re(p);
    for (auto &i : p)
        i--;

    vvi cycles = find_cycles(p);
    vi c;
    trav (i, cycles)
        c.push_back(sz(i));

    // min
    {
        auto possible = subset_sum<MAX, decltype(c.begin())>(all(c));

        if (possible[k]) {
            ps(k);
        } else {
            ps(k + 1);
        }
    }

    // max
    {
        sort(rall(c));
        int left = k;
        int ans = 0;
        int extra = 0;
        for (int i : c) {
            int eff = i / 2;
            if (i % 2)
                extra++;
            ans += 2 * min(eff, left);
            left -= min(eff, left);
        }
        ans += min(extra, left);

        ps(ans);
    }

    return 0;
}