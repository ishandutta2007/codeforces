#include <bits/stdc++.h>
using namespace std;

// clang-format off
// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
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
    template <class T> void re(vector<T> &a) { F0R (i, sz(a)) re(a[i]); }
    template <class T, size_t SZ> void re(array<T, SZ> &a) { F0R (i, SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template <class T, typename V = decltype(declval<const T &>().begin()), typename S = typename enable_if<!is_same<T, string>::value, bool>::type> void pr(const T &x);
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

#define TRACE(x) x
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

    template <typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(const vector<pair<T1, T2>> &v, const T1 &x) { return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; }); }
    template <typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(const vector<pair<T1, T2>> &v, const T1 &x) { return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; }); }
    template <typename I> struct reversed { I &v_; explicit reversed(I &v) : v_{v} {} auto begin() const { return rbegin(v_); } auto end() const { return rend(v_); } };
}
using namespace __algorithm;

struct __monostate {
    friend istream &operator>>(istream &is, const __attribute__((unused)) __monostate &ms) { return is; }
    friend ostream &operator<<(ostream &os, const __attribute__((unused)) __monostate &ms) { return os; }
} ms;

namespace __io {
    void setIn(string s) { freopen(s.c_str(), "r", stdin); }
    void setOut(string s) { freopen(s.c_str(), "w", stdout); }
    void setIO(string s = "") { ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(15); if (sz(s)) { setIn(s + ".in"), setOut(s + ".out"); } }
}
using namespace __io;
// }}}
// sparse_table {{{
template<typename T, typename F> struct sparse_table {
    int SZ;
    F tt; // idempotent
    vector<vector<T>> table;

    sparse_table() {}
    template<typename I> sparse_table(int SZ_, F tt_, I init) : SZ(SZ_), tt(tt_) {
        const int L = 32 - __builtin_clz(max(SZ - 1, 1));
        table.resz(L, vector<T>(SZ));

        for (int i = 0; i < SZ; i++) table[0][i] = init(i);

        for (int l = 0; l + 1 < L; l++)
            for (int i = 0; i + (2 << l) <= SZ; i++)
                table[l+1][i] = tt(table[l][i], table[l][i + (1 << l)]);
    }

    // Accumulates the elements at indices in [i, j) in O(1)
    T operator()(int i, int j) const {
        assert(0 <= i && i < j && j <= SZ);
        int l = j - i - 1 ? 31 - __builtin_clz(j - i - 1) : 0;
        return tt(table[l][i], table[l][j - (1 << l)]);
    }
};
// }}}

// clang-format on

const string YES = "YES", NO = "NO";

void solve() {
    int n;
    re(n);
    vi a(n);
    re(a);

    int big = *max_element(all(a));
    {
        vi loc;
        for (int i = 0; i < n; i++) {
            if (a[i] == big)
                loc.pb(i);
        }
        if (sz(loc) >= 3) {
            int x = loc[1];
            int y = 1;
            int z = n - x - y;
            ps(YES);
            ps(x, y, z);
            return;
        }
    }

    auto tt = [](int u, int v) -> int { return min(u, v); };
    auto init = [&](int i) { return a[i]; };
    sparse_table<int, decltype(tt)> min(n, tt, init);
    vi prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = max(prefix[i], a[i]);
    }
    vi suffix(n + 1);
    for (int i = 0; i < n; i++) {
        suffix[i + 1] = max(suffix[i], a[n - 1 - i]);
    }

    int x = 0, z = 0;
    while (true) {
        int v = std::max(a[x], a[n - 1 - z]);
        if (v == big)
            break;
        while (a[x] <= v)
            x++;
        while (a[n - 1 - z] <= v)
            z++;

        for (auto &[i, j] : {mp(x, z), {x - 1, z}, {x, z - 1}}) {
            if (i <= 0 || j <= 0)
                continue;

            if (prefix[i] != v)
                continue;
            if (suffix[j] != v)
                continue;
            if (min(i, n - j) != v)
                continue;

            ps(YES);
            ps(i, n - i - j, j);
            return;
        }
    }

    ps(NO);
}

int main() {
    setIO();

    int T;
    re(T);
    F0R (t, T)
        solve();

    return 0;
}