#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder


#pragma region

using namespace std;

// ! type aliases
using int128 = __int128_t;
using ll = long long;

template <typename T>
using vec = vector<T>;
using vi = vec<int>;
using vii = vec<vi>;
using vl = vec<ll>;
using vll = vec<vl>;

// ! macros
#define rep(i, n)          for (int i = 0; i < n; ++i)
#define reps(i, n, s)      for (int i = 0; i < n; i += s)
#define repl(i, l, r)      for (int i = l; i < r; ++i)
#define repls(i, l, r, s)  for (int i = l; i < r; i += s)
#define rrep(i, n)         for (int i = (n) - 1; i >= 0; --i)
#define rreps(i, n, s)     for (int i = (n) - 1; i >= 0; i -= s)
#define rrepl(i, l, r)     for (int i = (r) - 1; i >= l; --i)
#define rrepls(i, l, r, s) for (int i = (r) - 1; i >= l; i -= s)

#define all(iterable) (iterable).begin(), (iterable).end()

// ! constants
constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// ! I/O utilities
inline void print() { cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head& head, const Tail&... tails) {
    cout << head;
    if (sizeof...(tails)) cout << ' ';
    print(tails...);
}
template <typename T>
void print(const vec<T>& v, const string sep = " ", const string end = "\n") {
    int n = v.size();
    rep(i, n) cout << v[i] << (i < n - 1 ? sep : end);
}

constexpr void read() {}
template <typename Head, typename... Tail>
inline void read(Head& head, Tail& ...tails) {
    cin >> head;
    read(tails...);
}
template <typename T>
void read(vec<T>& a, size_t begin_index, size_t length) {
    a.resize(begin_index + length);
    while (length --> 0) cin >> a[begin_index++];
}
template <typename T>
void read(vec<T>& a) {
    read(a, 0, a.size());
}
template <typename T>
void read(vec<vec<T>>& a, size_t beg_i, size_t len_i, size_t beg_j, size_t len_j) {
    a.resize(beg_i + len_i);
    repl(i, beg_i, beg_i + len_i) read(a[i], beg_j, len_j);
}
template <typename T>
void read(vec<vec<T>>& a) {
    if (a.size()) read(a, 0, a.size(), 0, a[0].size());
}
template <typename T>
void read_graph(vec<vec<T>>& g, size_t n, size_t m, bool one_indexed_input = true) {
    g.resize(n);
    rep(i, m) {
        T u, v; cin >> u >> v;
        u -= one_indexed_input, v -= one_indexed_input;
        g[u].push_back(v), g[v].push_back(u);
    }
}
template <typename T, typename cost_t>
void read_graph(vec<vec<pair<T, cost_t>>>& g, size_t n, size_t m, bool one_indexed_input = true) {
    g.resize(n);
    rep(i, m) {
        T u, v; cost_t w; cin >> u >> v >> w;
        u -= one_indexed_input, v -= one_indexed_input;
        g[u].push_back({v, w}), g[v].push_back({u, w});
    }
}
template <typename T>
void read_digraph(vec<vec<T>>& g, size_t n, size_t m, bool one_indexed_input = true) {
    g.resize(n);
    rep(i, m) {
        T u, v; cin >> u >> v;
        u -= one_indexed_input, v -= one_indexed_input;
        g[u].push_back(v);
    }
}
template <typename T, typename cost_t>
void read_digraph(vec<vec<pair<T, cost_t>>>& g, size_t n, size_t m, bool one_indexed_input = true) {
    g.resize(n);
    rep(i, m) {
        T u, v; cost_t w; cin >> u >> v >> w;
        u -= one_indexed_input, v -= one_indexed_input;
        g[u].push_back({v, w});
    }
}

#pragma endregion


// ! code from here

ll op(ll a, ll b) { return a < b ? a : b; }
ll e() { return numeric_limits<ll>::max(); }

int main() {
    ll a, b;
    read(a, b);
    vec<ll> hs, ws;
    hs.reserve(10000);
    ws.reserve(10000);
    for (ll h = 1; h * h <= a + b; ++h) {
        if ((a + b) % h == 0) {
            hs.push_back(h);
            ws.push_back((a + b) / h);
        }
    }
    int n = hs.size();
    vec<ll> len(n);
    rep(i, n) {
        len[i] = 2 * (hs[i] + ws[i]);
    }
    atcoder::segtree<ll, op, e> seg(len);
    reverse(all(ws));
    
    ll ans = numeric_limits<ll>::max();
    for (ll x = 1; x * x <= a; ++x) {
        if (a % x) continue;
        ll y = a / x;
        int l = lower_bound(all(hs), x) - hs.begin();
        int r = ws.end() - lower_bound(all(ws), y);
        ans = min(ans, seg.prod(l, r));
    }
    for (ll x = 1; x * x <= b; ++x) {
        if (b % x) continue;
        ll y = b / x;
        int l = lower_bound(all(hs), x) - hs.begin();
        int r = ws.end() - lower_bound(all(ws), y);
        ans = min(ans, seg.prod(l, r));
    }
    print(ans);
    return 0;
}