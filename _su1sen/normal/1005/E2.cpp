#include <bits/stdc++.h>

template <typename T>
class fenwick_tree {
    public:
        fenwick_tree(size_t n, T zero): _n(n), _zero(zero) { init(); }
        fenwick_tree(size_t n): _n(n), _zero(0) { init(); }

        T prefix_sum(int r) const {
            T res = 0;
            while (r) {
                res += _dat[r];
                r -= -r & r;
            }
            return res;
        }
        T suffix_sum(int l) const { return _sum_all - prefix_sum(l); }
        T sum(int l, int r) const { return prefix_sum(r) - prefix_sum(l); }
        void add(int i, T v) {
            ++i;
            while (i <= _n) {
                _dat[i] += v;
                i += -i & i;
            }
            _sum_all += v;
        }
        void update(int i, T v) { add(i, v - sum(i, i + 1)); }
        void build(std::function<T(int)> gen) {
            _sum_all = _zero;
            for (int i = 0; i < _n; ++i) {
                _sum_all += _dat[i + 1] = gen(i);
            }
            for (int i = 1; i <= _n; ++i) {
                int p = i + (-i & i);
                if (p <= _n) _dat[p] += _dat[i];
            }
        }
    private:
        const size_t _n;
        const T _zero;
        std::vector<T> _dat;
        T _sum_all;
        void init() {
            _sum_all = _zero;
            _dat.resize(_n + 1);
            _dat.assign(_n + 1, _zero);
        }
};

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

int main() {
    int n, m;
    read(n, m);
    vec<int> a(n);
    ll ans = (ll) n * (n + 1) / 2;
    vec<int> zeros;
    {
        int l = 0;
        rep(i, n) {
            int v;
            read(v);
            if (v < m) {
                a[i] = -1;
            } else if (v == m) {
                a[i] = 0;
                ll w = i - l + 1;
                ans -= w * (w - 1) / 2;
                l = i + 1;
                zeros.push_back(i);
            } else {
                a[i] = 1;
            }
        }
        ll w = n - l + 1;
        ans -= w * (w - 1) / 2;
        zeros.push_back(n);
    }

    vec<int> p(n + 1);
    p[0] = 0;
    rep(i, n) {
        if (a[i] == -1) {
            p[i + 1] = p[i] - 1;
        } else {
            p[i + 1] = p[i] + 1;
        }
    }
    fenwick_tree<int> fp(2 * n + 2);
    int geta = n;
    auto iter_z = zeros.begin();
    repl(j, (*iter_z) + 1, n + 1) {
        fp.add(geta + p[j], 1);
    }
    rep(i, n) {
        ans -= fp.prefix_sum(geta + p[i] + 1);
        if (i == *iter_z) {
            int l = *iter_z;
            ++iter_z;
            int r = *iter_z;
            repl(j, l + 1, r + 1) {
                fp.add(geta + p[j], -1);
            }
        }
    }

    vec<int> q(n + 1);
    q[0] = 0;
    rep(i, n) {
        if (a[i] == 1) {
            q[i + 1] = q[i] + 1;
        } else {
            q[i + 1] = q[i] - 1;
        }
    }
    fenwick_tree<int> fq(2 * n + 2);
    iter_z = zeros.begin();
    repl(j, (*iter_z) + 1, n + 1) {
        fq.add(geta + q[j], 1);
    }
    rep(i, n) {
        ans -= fq.suffix_sum(geta + q[i] + 1);
        if (i == *iter_z) {
            int l = *iter_z;
            ++iter_z;
            int r = *iter_z;
            repl(j, l + 1, r + 1) {
                fq.add(geta + q[j], -1);
            }
        }
    }
    print(ans);
    return 0;
}