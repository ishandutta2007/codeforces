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
bool chmin(T &x, T y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, T y) {
    if (y > x) {
        x = y;
        return true;
    } else return false;
}

#pragma endregion

// ! code from here

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    read(n);
    string s;
    read(s);
    string ord = "RGB"s;
    vec<int> mp(256);
    rep(i, 3) {
        mp[ord[i]] = i;
    }
    vec<int> t(n);
    rep(i, n) t[i] = mp[s[i]];
    vec<vec<int>> dp(n, vec<int>(3, n));
    vec<vec<int>> prev(n, vec<int>(3, -1));
    dp[0].assign(3, 1);
    dp[0][t[0]] = 0;
    replr(i, 1, n) {
        rep(j, 3) {
            rep(k, 3) {
                if (j == k) continue;
                if (chmin(dp[i][k], dp[i - 1][j] + 1)) {
                    prev[i][k] = j;
                }
            }
            if (j != t[i]) {
                if (chmin(dp[i][t[i]], dp[i - 1][j])) {
                    prev[i][t[i]] = j;
                }
            }
        }
    }
    int amin = min_element(all(dp[n - 1])) - dp[n - 1].begin();
    int ans = dp[n - 1][amin];
    vec<char> ans_str;
    int i = n - 1, j = amin;
    do {
        ans_str.push_back(ord[j]);
        j = prev[i--][j];
    } while (i >= 0);
    print(ans);
    rrep(i, n) cout << ans_str[i];
    cout << '\n';
    return 0;
}