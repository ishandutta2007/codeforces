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


template<typename cost_t, typename transition_t>
class dijkstra {
    public:
        dijkstra(unsigned int n, transition_t transition, unsigned int src) : _src(src) {
            _par.resize(n);
            _dist.assign(n, UNREACHABLE);
            _dist[src] = 0;
            using state = std::pair<cost_t, unsigned int>;
            std::priority_queue<state, std::vector<state>, std::greater<state>> pq;
            pq.emplace(0, src);
            auto g = [&](unsigned int u) {
                return [&, u](unsigned int v, cost_t new_cost) {
                    if (new_cost < _dist[v]) pq.emplace(_dist[v] = new_cost, v), _par[v] = u;
                };
            };
            while (pq.size()) {
                auto [du, u] = pq.top(); pq.pop();
                if (du == _dist[u]) transition(u, du, g(u));
            }
        }
        std::vector<unsigned int> path_to(unsigned int t) const {
            assert(is_reachale(t));
            std::vector<unsigned int> path = {t};
            while (t != _src) path.push_back(t = _par[t]);
            std::reverse(path.begin(), path.end());
            return path;
        }
        cost_t operator[](unsigned int t) const { return _dist[t]; }
        bool is_reachale   (unsigned int t) const { return _dist[t] != UNREACHABLE; }
        bool is_unreachable(unsigned int t) const { return _dist[t] == UNREACHABLE; }
    private:
        const cost_t UNREACHABLE = std::numeric_limits<cost_t>::max();
        const unsigned int _src;
        std::vector<cost_t> _dist;
        std::vector<unsigned int> _par;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    read(n, m, k);
    vec<vec<pair<int, int>>> g(n);
    rep(i, m) {
        int u, v, w;
        read(u, v, w);
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vec<pair<int, int>> st(k);
    rep(i, k) {
        int u, v;
        read(u, v);
        st[i] = {u - 1, v - 1};
    }
    vec<vec<int>> d(n, vec<int>(n));
    rep(i, n) {
        auto graph = [&](int u, int du, auto f) {
            for (auto &[v, w] : g[u]) f(v, du + w);
        };
        dijkstra<int, decltype(graph)> dij(n, graph, i);
        rep(j, n) d[i][j] = dij[j];
    }
    int ans = IINF;
    rep(i, n) {
        for (auto &[j, w] : g[i]) {
            if (j > i) continue;
            int sum = 0;
            for (auto &[s, t] : st) {
                sum += min({d[s][t], d[s][i] + d[j][t], d[s][j] + d[i][t]});
            }
            chmin(ans, sum);
        }
    }
    print(ans);
    return 0;
}