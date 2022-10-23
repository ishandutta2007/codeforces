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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    read(t);
    while (t --> 0) {
        int n;
        ll s;
        read(n, s);
        vec<vec<tuple<int, ll, int>>> g(n);
        rep(i, n - 1) {
            int u, v, w, c;
            read(u, v, w, c);
            --u, --v;
            g[u].emplace_back(v, w, c);
            g[v].emplace_back(u, w, c);
        }
        auto dec = [](ll w, int leaves) {
            return (w - w / 2) * leaves;
        };
        vec<ll> c1, c2;
        c1.reserve(n);
        c2.reserve(n);
        ll cur_sum = 0;
        auto dfs = [&](auto self, int u, int p) -> int {
            if (p >= 0 and g[u].size() == 1) {
                return 1;
            }
            int leaves = 0;
            for (auto &[v, w, c] : g[u]) {
                if (v != p) {
                    int lv = self(self, v, u);
                    leaves += lv;
                    cur_sum += w * lv;
                    for (ll x = w; x > 0; x >>= 1) {
                        (c == 1 ? c1 : c2).push_back(dec(x, lv));
                    }
                }
            }
            return leaves;
        };
        dfs(dfs, 0, -1);
        sort(all(c1), greater<ll>());
        sort(all(c2), greater<ll>());
        int m = c1.size(), k = c2.size();
        c1.insert(c1.begin(), 0LL);
        c2.insert(c2.begin(), 0LL);
        rep(i, m) {
            c1[i + 1] += c1[i];
        }
        rep(i, k) {
            c2[i + 1] += c2[i];
        }
        int ans = numeric_limits<int>::max();
        rep(i, m + 1) {
            int j = lower_bound(all(c2), cur_sum - c1[i] - s) - c2.begin();
            if (j <= k) chmin(ans, i + 2 * j);
        }
        print(ans);
    }
    return 0;
}