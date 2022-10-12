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
// monotonic_stack {{{
#include <algorithm>
#include <cassert>
#include <functional>
#include <stack>

template <typename T, typename LessThan = std::less<T>>
struct monotonic_stack {
    std::stack<std::pair<T, T>> data;
    LessThan less_than;

  public:
    bool empty() const { return data.empty(); }
    int size() const { return data.size(); }
    T top() const { return data.top().first; };

    void push(const T &item) {
        T next_min = empty() ? item : std::min(item, min(), less_than);
        data.push({item, next_min});
    }

    void pop() {
        assert(!empty());
        data.pop();
    }

    T min() const {
        assert(!empty());
        return data.top().second;
    };

    T min(const T &default_value) const { return empty() ? default_value : min(); }
};
// }}}
// monotonic_queue {{{
// {{{ data_structures/monotonic_stack }}}

#include <algorithm>
#include <cassert>
#include <functional>

template <typename T, typename LessThan = std::less<T>>
struct monotonic_queue {
    monotonic_stack<T, LessThan> in, out;
    LessThan less_than;

  public:
    bool empty() const { return in.empty() && out.empty(); }
    int size() const { return in.size() + out.size(); }
    T front() {
        assert(!empty());
        refill();
        return out.top();
    }

    void push(const T &item) { in.push(item); }

    void pop() {
        assert(!empty());
        refill();
        out.pop();
    }

    T min() const {
        assert(!empty());
        if (in.empty())
            return out.min();
        if (out.empty())
            return in.min();
        return std::min(in.min(), out.min(), less_than);
    }

    T min(const T &default_value) const { return empty() ? default_value : min(); }

  private:
    void refill() {
        if (!out.empty())
            return;
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
};
// }}}

// clang-format on

const string NO = "Hungry", YES = "Full";
const int INF = 1e9;

int main() {
    setIO();

    int n, k;
    re(n, k);
    const int S = 2 * n + 1;

    auto make_dp = [&]() {
        array<vi, 2> dp{vi(S, INF), vi(S, INF)};
        return dp;
    };

    auto dp = make_dp();

    dp[1][0] = 0;

    auto adv = [&](int len) {
        for (int i = S - 1; i - len >= 0; i--)
            dp[1][i] = dp[1][i - len];
        for (int i = 0; i < len; i++)
            dp[1][i] = INF;
    };

    auto next = make_dp();
    auto update = [&](int len) {
        // 0 flips
        for (int i = 0; i < S; i++)
            next[0][i] = dp[0][i];
        for (int i = S - 1; i - len >= 0; i--)
            next[1][i] = dp[1][i - len];
        for (int i = 0; i < len; i++)
            next[1][i] = INF;

        for (int b = 0; b <= 1; b++) {
            monotonic_queue<int> vals;
            for (int i = 0; i < S; i++) {
                vals.push(1 + dp[1 ^ b][i]); // 1 flip
                vals.push(2 + dp[b][i]);     // 2 flips

                if (i - len - 1 >= 0) {
                    vals.pop();
                    vals.pop();
                }

                if (!vals.empty())
                    ckmin(next[b][i], vals.min());
            }
        }

        swap(dp, next);
    };

    int t = 0;
    for (int i = 0; i < k; i++) {
        int l, r;
        re(l, r);

        adv(l - t);
        t = l;
        update(r - t);
        t = r;
    }
    adv(2 * n - t);

    int ans = min(dp[0][n], dp[1][n]);
    if (ans == INF) {
        ps(NO);
        return 0;
    }
    ps(YES);
    ps(ans);

    return 0;
}