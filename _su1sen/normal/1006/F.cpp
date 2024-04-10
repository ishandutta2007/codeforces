#include <bits/stdc++.h>

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
    long long k;
    read(n, m, k);
    vec<vec<ll>> a(n, vec<ll>(m));
    for (auto &row : a) read(row);
    if (n == 1 and m == 1) {
        if (a[0][0] == k) {
            print(1);
        } else {
            print(0);
        }
        return 0;
    }
    int l = (n + m - 2) / 2;
    int r = (n + m - 2) - l - 1;
    map<int, map<ll, int>> mp;
    rep(i, 1 << l) {
        int step_r = __builtin_popcount(i);
        int step_d = l - step_r;
        if (step_r >= m or step_d >= n) continue;
        int x = 0, y = 0;
        ll sum = a[x][y];
        rep(j, l) {
            if ((i >> j) & 1) {
                sum ^= a[x][++y];
            } else {
                sum ^= a[++x][y];
            }
        }
        ++mp[x * m + y][sum];
    }
    ll ans = 0;
    rep(i, 1 << r) {
        int step_l = __builtin_popcount(i);
        int step_u = r - step_l;
        if (step_l >= m or step_u >= n) continue;
        int x = n - 1, y = m - 1;
        ll sum = a[x][y];
        rep(j, r) {
            if ((i >> j) & 1) {
                sum ^= a[x][--y];
            } else {
                sum ^= a[--x][y];
            }
        }
        int x1 = x - 1, y1 = y;
        if (x1 >= 0 and mp[x1 * m + y1].count(sum ^ k)) {
            ans += mp[x1 * m + y1][sum ^ k];
        }
        int x2 = x, y2 = y - 1;
        if (y2 >= 0 and mp[x2 * m + y2].count(sum ^ k)) {
            ans += mp[x2 * m + y2][sum ^ k];
        }
    }
    print(ans);
    return 0;
}