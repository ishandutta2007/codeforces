#include <bits/stdc++.h>

#pragma region

using namespace std;

// ! type aliases
using int128 = __int128_t;
using uint128 = __uint128_t;
using ll = long long;
using uint = unsigned int;
using ull  = unsigned long long;

template <typename T> using vec  = std::vector<T>;
template <typename T> using vec2 = vec<vec<T>>;
template <typename T> using vec3 = vec<vec2<T>>;
template <typename T> using vec4 = vec<vec3<T>>;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = std::unordered_map<T, U>;

// ! macros
#define _overload4(_1,_2,_3,_4,name,...) name

#define _rep4(i, l, r, s)  for (std::remove_const_t<decltype(r)> i = (l); i < (r); i += (s))
#define _rep3(i, l, r)     _rep4(i, l, r, 1)
#define _rep2(i, n)        _rep4(i, 0, n, 1)
#define _rrep4(i, l, r, s) for (std::remove_const_t<decltype(r)> i = (l) + fld((r) - (l) - 1, s) * (s); i >= (l); i -= (s))
#define _rrep3(i, l, r)    _rrep4(i, l, r, 1)
#define _rrep2(i, n)       _rrep4(i, 0, n, 1)

#define rep(...)  _overload4(__VA_ARGS__, _rep4 , _rep3 , _rep2, )(__VA_ARGS__)
#define rrep(...) _overload4(__VA_ARGS__, _rrep4, _rrep3, _rrep2,)(__VA_ARGS__)

#define loop(n) for (std::remove_const_t<decltype(n)> loop_variable = n; loop_variable --> 0;)

#define all(iterable) (iterable).begin(), (iterable).end()
#define size_int(iterable) int((iterable).size())
#define input(type, ...) type __VA_ARGS__; read(__VA_ARGS__)

// ! constants
constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

constexpr int IINF = (1 << 30) - 1;
constexpr ll LINF = (1LL << 62) - 1; 

// ! I/O utilities
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &a) {
    int n = a.size();
    rep(i, n) {
        out << a[i];
        if (i < n - 1) out << ' ';
    }
    return out;
}
inline void print() { cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head& head, const Tail&... tails) {
    cout << head;
    if (sizeof...(tails)) cout << ' ';
    print(tails...);
}
template <typename _Iterable>
void print_iterable(const _Iterable& v, const string sep = " ", const string end = "\n") {
    int n = v.size();
    rep(i, n) {
        cout << v[i];
        if (i < n - 1) cout << sep;
    }
    cout << end;
}

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T> &a) {
    for (T& v : a) in >> v;
    return in;
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
constexpr void read() {}
template <typename Head, typename... Tail>
inline void read(Head& head, Tail& ...tails) {
    cin >> head;
    read(tails...);
}

// ! utility functions
template <typename T>
bool chmin(T &x, const T &y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmin(T &x, const T &&y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, const T &&y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}

template <typename T>
constexpr T fld(const T x, const T y) {
    return y < 0 ? fld(-x, -y) : (x >= 0 ? x / y : -((-x + y - 1) / y));
}
template <typename T>
constexpr T cld(const T x, const T y) {
    return y < 0 ? cld(-x, -y) : (x >= 0 ? (x + y - 1) / y : -(-x / y));
}

template <typename _Iterable>
void unique_erase(_Iterable &iterable) {
    iterable.erase(unique(iterable.begin(), iterable.end()), iterable.end());
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
    input(int, n, m);
    vec<vec<int>> g(n);
    rep(i, n - 1) {
        input(int, u, v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto graph = [&](int u, auto f) {
        for (int v : g[u]) f(v);
    };
    euler_tour<decltype(graph)> et(n, 0, graph);
    loop(m) {
        input(int, k);
        vec<int> vs(k);
        read(vs);
        for (int &v : vs) {
            if (--v) v = et.parent(v);
        }
        sort(all(vs), [&](int u, int v) {
            int du = et.depth(u);
            int dv = et.depth(v);
            return du > dv;
        });
        bool ok = true;
        rep(i, k - 1) {
            int u = vs[i], v = vs[i + 1];
            ok &= et.lca(u, v) == v;
        }
        print(ok ? "YES" : "NO");
    }
    return 0;
}