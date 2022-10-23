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
void chmin(T &x, T &&y) { if (y < x) x = y; }
template <typename T>
void chmax(T &x, T &&y) { if (y > x) x = y; }

#pragma endregion

// ! code from here

inline ll d(ll x1, ll x2, ll y1, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int n;
    read(n);
    vec<pair<int, int>> p(n);
    rep(i, n) {
        read(p[i].first, p[i].second);
    }
    sort(all(p), [](pair<int, int> p1, pair<int, int> p2){
        auto &[x1, y1] = p1;
        auto &[x2, y2] = p2;
        int m1 = max(x1, y1);
        int m2 = max(x2, y2);
        if (m1 == m2) {
            if (x1 == x2) {
                return y1 > y2;
            } else {
                return x1 < x2;
            }
        } else {
            return m1 < m2;
        }
    });
    int pm = 0;
    vec<vec<pair<int, int>>> level_points;
    level_points.push_back({{0, 0}});
    rep(i, n) {
        int cm = max(p[i].first, p[i].second);
        if (pm != cm) level_points.emplace_back();
        int sz = level_points.size();
        if (level_points[sz - 1].size() >= 2) {
            level_points[sz - 1].pop_back();
        } 
        level_points[sz - 1].push_back(p[i]);
        pm = cm;
    }
    for (auto &v : level_points) {
        if (v.size() == 1) {
            v.reserve(2);
            v.push_back(v[0]);
        }
    }
    int m = level_points.size();
    vec<vec<ll>> dp = {vec<ll>(m, LINF), vec<ll>(m, LINF)};
    dp[0][0] = dp[1][0] = 0;
    rep(i, m - 1) {
        rep(j, 2) rep(k, 2) {
            auto [cx, cy] = level_points[i][j];
            auto [mx, my] = level_points[i + 1][k ^ 1];
            auto [nx, ny] = level_points[i + 1][k];
            ll cost = d(cx, mx, cy, my) + d(mx, nx, my, ny);
            chmin(dp[k][i + 1], dp[j][i] + cost);
        }
    }
    print(min(dp[0][m - 1], dp[1][m - 1]));
    return 0;
}