#include <bits/stdc++.h>

#pragma region

using namespace std;

// !
#ifndef ONLINE_JUDGE
    #define _GLIBCXX_DEBUG
#endif

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
    vec<string> g(n);
    rep(i, n) read(g[i]);

    vec<vec<int>> umin(n, vec<int>(m)), dmax(n, vec<int>(m));
    vec<vec<int>> lmin(n, vec<int>(m)), rmax(n, vec<int>(m));
    rep(i, n) rep(j, m) {
        if (g[i][j] == '*') {
            if (i > 0) {
                umin[i][j] = umin[i - 1][j];
            } else {
                umin[i][j] = i;
            }
            if (j > 0) {
                lmin[i][j] = lmin[i][j - 1];
            } else {
                lmin[i][j] = j;
            }
        } else {
            umin[i][j] = i + 1;
            lmin[i][j] = j + 1;
        }
    }
    rrep(i, n) rrep(j, m) {
        if (g[i][j] == '*') {
            if (i < n - 1) {
                dmax[i][j] = dmax[i + 1][j];
            } else {
                dmax[i][j] = i;
            }
            if (j < m - 1) {
                rmax[i][j] = rmax[i][j + 1];
            } else {
                rmax[i][j] = j;
            }
        } else {
            dmax[i][j] = i - 1;
            rmax[i][j] = j - 1;
        }
    }

    vec<vec<int>> ok_row(n, vec<int>(m + 1, 0));
    vec<vec<int>> ok_col(n + 1, vec<int>(m, 0));

    vec<tuple<int, int, int>> ans;
    ans.reserve(n * m);
    rep(i, n) rep(j, m) {
        if (g[i][j] == '.') {
            continue;
        }
        int k = 1;
        int l = lmin[i][j], r = rmax[i][j], u = umin[i][j], d = dmax[i][j];
        int s = min({j - l, r - j, i - u, d - i});
        if (s) {
            ++ok_row[i][j - s], --ok_row[i][j];
            ++ok_row[i][j + 1], --ok_row[i][j + s + 1];
            ++ok_col[i - s][j], --ok_col[i + s + 1][j];
            ans.push_back({i + 1, j + 1, s});
        }
    }
    rep(i, n) rep(j, m) {
        ok_row[i][j + 1] += ok_row[i][j];
        ok_col[i + 1][j] += ok_col[i][j];
    }
    rep(i, n) rep(j, m) {
        if (g[i][j] == '*' and ok_row[i][j] + ok_col[i][j] == 0) {
            print(-1);
            return 0;
        }
    }
    print(ans.size());
    for (auto [i, j, s] : ans) {
        cout << i << ' ' << j << ' ' << s << '\n';
    }
    return 0;
}