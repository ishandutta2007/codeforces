#include <bits/stdc++.h>

#pragma region

using namespace std;

// ! type aliases
using int128 = __int128_t;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

template <typename T>
using vec = std::vector<T>;
template <typename T>
using vec2 = vec<vec<T>>;
template <typename T>
using vec3 = vec<vec2<T>>;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = unordered_map<T, U>;

// ! macros
#define rep(i, n)           for (int i = 0; i < n; ++i)
#define reps(i, n, s)       for (int i = 0; i < n; i += s)
#define replr(i, l, r)      for (int i = l; i < r; ++i)
#define replrs(i, l, r, s)  for (int i = l; i < r; i += s)
#define rrep(i, n)          for (int i = (n) - 1; i >= 0; --i)
#define rreps(i, n, s)      for (int i = (n) - 1; i >= 0; i -= s)
#define rreplr(i, l, r)     for (int i = (r) - 1; i >= l; --i)
#define rreplrs(i, l, r, s) for (int i = (r) - 1; i >= l; i -= s)

#define all(iterable) (iterable).begin(), (iterable).end()

// ! constants
constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

constexpr int IINF = (1 << 30) - 1;
constexpr ll LINF = (1LL << 62) - 1; 

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
template <typename T>
void print(const vec<T>& v, const size_t begin_index, const size_t length, const string sep = " ", const string end = "\n") {
    int n = begin_index + length;
    replr(i, begin_index, n) cout << v[i] << (i < n - 1 ? sep : end);
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

// ! utility functions
template <typename T>
bool chmin(T &x, T &y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmin(T &x, T &&y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, T &y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, T &&y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}

#pragma endregion

// ! code from here


/**
 * Graph g : (int u, auto f) { for (int v : adjacent(u)) f(v); }
 */
template <typename Graph>
class euler_tour {
    public:
        euler_tour(int n, int root, Graph g) : n(n), m(ceil_pow2(2 * n)) {
            dep.resize(n + 1), visit.resize(n), leave.resize(n);
            seg.assign(2 * m, n);
            dfs(g, root);
            for (int k = m - 1; k > 0; --k) seg[k] = argmin(seg[(k << 1) | 0], seg[(k << 1) | 1]);
        }
        int lca(int u, int v) const {
            if (visit[u] > visit[v]) return lca(v, u);
            int res = n;
            for (int l = m + visit[u], r = m + visit[v] + 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = argmin(res, seg[l++]);
                if (r & 1) res = argmin(res, seg[--r]);
            }
            return res;
        }
        inline int dist(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
        inline int depth(int u) const { return dep[u]; }
        inline int visit_time(int u) const { return visit[u]; }
        inline int leave_time(int u) const { return leave[u]; }
        inline int parent(int u) const {
            int p = seg[m + leave[u]];
            return p == n ? -1 : p;
        }
    private:
        const int n, m;
        std::vector<int> visit, leave, dep, seg;
        void dfs(Graph g, int root) {
            dep[root] = 0, dep[n] = std::numeric_limits<int>::max();
            int k = 0;
            auto f = [&](auto self, int u, int p) -> void {
                visit[u] = k, seg[m + k++] = u;
                g(u, [&](int v){ if (v != p) dep[v] = dep[u] + 1, self(self, v, u); });
                leave[u] = k, seg[m + k++] = p;
            };
            f(f, root, n);
        }
        inline int argmin(int u, int v) const { return dep[u] < dep[v] ? u : v; }
        static int ceil_pow2(const int n) {
            int k = 1;
            while (k < n) k <<= 1;
            return k;
        }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    read(t);
    while (t --> 0) {
        int n;
        read(n);
        vec<vec<int>> tree(n);
        rep(i, n - 1) {
            int u, v;
            read(u, v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        euler_tour et(n, 0, [&](int u, auto f) { for (int v : tree[u]) f(v); });
        vec<int> par(n);
        vec<ll> subtree(n, 1);
        auto dfs = [&](auto self, int u, int p) -> ll {
            par[u] = p;
            for (int v : tree[u]) {
                if (v != p) {
                    subtree[u] += self(self, v, u);
                }
            }
            return subtree[u];
        };
        dfs(dfs, 0, -1);
        vec<ll> ans(n + 1, 0);
        for (int v : tree[0]) {
            ans[0] += subtree[v] * (subtree[v] - 1) / 2;
        }
        int u = 1, v = 0;
        auto on_path = [&](int k) {
            return et.dist(u, k) + et.dist(v, k) == et.dist(u, v);
        };
        auto is_descendant = [&](int k, int p) {
            return et.lca(p, k) == p;
        };
        int c = 1;
        while (par[c] != 0) c = par[c];
        ll con_0 = ll(n) * ll(n - 1) / 2 - ans[0];
        ll con_01 = ll(subtree[1]) * ll(n - subtree[c]);
        ans[1] = con_0 - con_01;
        replr(k, 2, n) {
            if (on_path(k)) continue;
            if (is_descendant(k, u)) {
                ll sv = v == 0 ? n - subtree[c] : subtree[v];
                ans[k] = (subtree[u] - subtree[k]) * sv;
                u = k;
            } else if (is_descendant(k, v)) {
                ll sv = v == 0 ? n - subtree[c] : subtree[v];
                if (v == 0 and is_descendant(k, c)) {
                    ans[k] = subtree[u] * sv;
                    break;
                }
                ans[k] = subtree[u] * (sv - subtree[k]);
                v = k;
            } else {
                ans[k] = subtree[u] * subtree[v];
                break;
            }
        }
        bool is_path_graph = true;
        rep(i, n) {
            is_path_graph &= tree[i].size() <= 2;
        }
        ans[n] = is_path_graph;
        print(ans);
    }
    return 0;
}