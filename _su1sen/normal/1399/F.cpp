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

bool comparator(pair<int, int> &s1, pair<int, int> &s2) {
    auto &[l1, r1] = s1;
    auto &[l2, r2] = s2;
    return r1 == r2 ? l1 > l2 : r1 < r2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    read(t);
    while (t --> 0) {
        int n;
        read(n);
        vec<pair<int, int>> segs(n);
        vec<int> xs(2 * n);
        rep(i, n) {
            int l, r;
            read(l, r);
            --l;
            segs[i] = {l, r};
            xs[2 * i] = l, xs[2 * i + 1] = r;
        }
        sort(all(segs), comparator);
        sort(all(xs));
        xs.erase(unique(all(xs)), xs.end());
        int m = xs.size();
        map<int, int> cmp;
        rep(i, m) cmp[xs[i]] = i;
        vec<int> contain_num(n, 0);
        rep(i, n) {
            auto &[l, r] = segs[i];
            l = cmp[l], r = cmp[r];
            vec<int> dp(r + 1, 0);
            int pr = 0;
            rep(j, i) {
                auto [lj, rj] = segs[j];
                if (l <= lj) {
                    replr(k, pr, rj) chmax(dp[k + 1], dp[k]);
                    chmax(dp[rj], dp[lj] + contain_num[j]);
                    pr = rj;
                }
            }
            contain_num[i] = dp[pr] + 1;
        }
        vec<int> dp(m, 0);
        int pr = 0;
        rep(i, n) {
            auto [l, r] = segs[i];
            replr(k, pr, r) chmax(dp[k + 1], dp[k]);
            chmax(dp[r], dp[l] + contain_num[i]);
            pr = r;
        }
        print(dp[pr]);
    }
    return 0;
}