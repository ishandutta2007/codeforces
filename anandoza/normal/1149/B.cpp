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

// clang-format on

constexpr char A = 'a';
constexpr int MAX = 250 + 1;
constexpr int INF = 1e9;
const string YES = "YES", NO = "NO";
const int Z = 26;

int main() {
    setIO();

    int n, q;
    re(n, q);

    string s;
    re(s);
    vvi indices(Z, vi(n, INF));
    for (int i = 0; i < sz(s); i++) {
        indices[s[i] - A][i] = i + 1;
    }
    for (int c = 0; c < Z; c++) {
        for (int i = sz(s) - 1; i > 0; i--) {
            ckmin(indices[c][i - 1], indices[c][i]);
        }
    }
    auto get = [&](int i, int c) {
        if (i >= sz(s))
            return INF;
        return indices[c][i];
    };

    vector<vvi> dp(MAX, vvi(MAX, vi(MAX, INF)));
    dp[0][0][0] = 0;
    array<int, 3> len{};
    vector<vector<int>> words(3);

    for (int query = 0; query < q; query++) {
        char type;
        re(type);

        int dim;
        re(dim);
        dim--;

        if (type == '+') {
            len[dim]++;

            char letter;
            re(letter);
            int c = letter - A;
            words[dim].push_back(c);

            auto fill = [&](int i, int j, int k) {
                dp[i][j][k] = INF;
                if (i - 1 >= 0)
                    ckmin(dp[i][j][k], get(dp[i - 1][j][k], words[0][i - 1]));
                if (j - 1 >= 0)
                    ckmin(dp[i][j][k], get(dp[i][j - 1][k], words[1][j - 1]));
                if (k - 1 >= 0)
                    ckmin(dp[i][j][k], get(dp[i][j][k - 1], words[2][k - 1]));
            };

            for (int i = dim == 0 ? len[0] : 0; i <= len[0]; i++) {
                for (int j = dim == 1 ? len[1] : 0; j <= len[1]; j++) {
                    for (int k = dim == 2 ? len[2] : 0; k <= len[2]; k++) {
                        if (i + j + k == 0)
                            continue;
                        fill(i, j, k);
                    }
                }
            }
        } else {
            len[dim]--;
            words[dim].pop_back();
        }

        bool ans = dp[len[0]][len[1]][len[2]] != INF;
        ps(ans ? YES : NO);
    }

    return 0;
}