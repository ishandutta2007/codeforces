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

pair<ll, ll> normalize(const ll den, const ll num) {
    ll g = __gcd(den, num);
    return {den / g, num / g};
}

int main() {
    int m;
    read(m);
    map<pair<ll, ll>, int> lines;
    vec<vec<pair<int, int>>> g;
    g.reserve(2 * m);
    int n = 0;
    rep(i, m) {
        ll a, b, c, d;
        read(a, b, c, d);
        auto p = normalize(b * c, a * d + b * d);
        auto q = normalize(b * c + b * d, a * d);
        if (not lines.count(p)) {
            lines[p] = n++;
            g.emplace_back();
        }
        if (not lines.count(q)) {
            lines[q] = n++;
            g.emplace_back();
        }
        int u = lines[p], v = lines[q];
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    vec<bool> vis(n, false), used(m, false);
    vec<pair<int, int>> ans;
    ans.reserve(m);
    auto dfs = [&](auto self, int u, int p, int id_par) -> void {
        vis[u] = true;
        for (auto &[v, id] : g[u]) {
            if (vis[v]) continue;
            self(self, v, u, id);
        }
        int id_prev = -1;
        for (auto &[v, id] : g[u]) {
            if (v == p or used[id]) continue;
            if (id_prev >= 0) {
                ans.push_back({id, id_prev});
                used[id] = used[id_prev] = true;
                id_prev = -1;
            } else {
                id_prev = id;
            }
        }
        if (id_prev >= 0 and id_par >= 0) {
            ans.push_back({id_prev, id_par});
            used[id_prev] = used[id_par] = true;
        }
    };
    rep(i, n) if (not vis[i]) dfs(dfs, i, -1, -1);
    print(ans.size());
    for (auto &[i, j] : ans) {
        print(i + 1, j + 1);
    }
    return 0;
}