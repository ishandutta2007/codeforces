#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder


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
void chmin(T &x, T &y) { if (y < x) x = y; }
template <typename T>
void chmax(T &x, T &y) { if (y > x) x = y; }

#pragma endregion

// ! code from here


int main() {
    int n, m;
    read(n, m);
    atcoder::dsu uf(n);
    vec<vec<int>> g(n);
    rep(i, m) {
        int u, v;
        read(u, v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        uf.merge(u, v);
    }
    vec<int> depth(n);
    auto dfs = [&](auto self, int u, int p) -> pair<int, int> {
        int mx = depth[u], amx = u;
        for (int v : g[u]) {
            if (p == v) continue;
            depth[v] = depth[u] + 1;
            auto [d, a] = self(self, v, u);
            if (d > mx) {
                mx = d;
                amx = a;
            }
        }
        return {mx, amx};
    };
    vec<int> par(n, -1);
    vec<pair<int, int>> ctr;
    for (auto &group : uf.groups()) {
        int root = group[0];
        auto [_, u] = dfs(dfs, root, -1);
        depth[u] = 0;
        auto [d, v] = dfs(dfs, u, -1);
       
        vec<pair<int, int>> st;
        st.emplace_back(u, 0);
        while (st.size()) {
            auto &[x, i] = st.back();
            if (x == v) break;
            if (i == g[x].size()) {
                st.pop_back();
            } else {
                int y = g[x][i++];
                if (y == par[x]) continue;
                par[y] = x;
                st.emplace_back(y, 0);
            }
        }
        int sz = st.size();
        ctr.emplace_back(sz, st[sz / 2].first);
    }
    sort(all(ctr));
    vec<pair<int, int>> ans;
    auto merge = [&ans](pair<int, int> &p1, pair<int, int> &p2) -> pair<int, int> {
        auto [d1, l1] = p1;
        auto [d2, l2] = p2;
        ans.emplace_back(l1, l2);
        if (d1 > d2) {
            int nd;
            if (d1 & 1) {
                nd = d1 + (d2 == d1 - 1);
            } else {
                nd = d1 + (d2 >= d1 - 2);
            }
            return {nd, l1};
        } else if (d1 < d2) {
            int nd;
            if (d2 & 1) {
                nd = d2 + (d1 == d2 - 1);
            } else {
                nd = d2 + (d1 >= d2 - 2);
            }
            return {nd, l2};
        } else {
            int nd = d1 + (d1 & 1 ? 1 : 2);
            return {nd, l1};
        }
    };
    pair<int, int> p = ctr.back(); ctr.pop_back();
    for (auto &q : ctr) {
        p = merge(p, q);
    }
    print(p.first - 1);
    for (auto &[x, y] : ans) {
        print(x + 1, y + 1);
    }
    return 0;
}