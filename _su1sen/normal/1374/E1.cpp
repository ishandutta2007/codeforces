#include <bits/stdc++.h>

#pragma region

using namespace std;

// ! type aliases
using int128 = __int128_t;
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

// ! operator overload (pair)
template <typename T, typename U>
std::pair<T, U>& operator+=(std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    p1.first += p2.first, p1.second += p2.second;
    return p1;
}
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}
template <typename T, typename U>
std::pair<T, U>& operator-=(std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    p1.first -= p2.first, p1.second -= p2.second;
    return p1;
}
template <typename T, typename U>
std::pair<T, U> operator-(const std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}
template <typename T, typename U, typename V>
std::pair<T, U>& operator*=(std::pair<T, U> &p, const V m) {
    p.first *= m, p.second *= m;
    return p;
}
template <typename T, typename U, typename V>
std::pair<T, U> operator*(std::pair<T, U> &p, const V m) {
    return {p.first * m, p.second * m};
}
// ! operator overload (vector)
template <typename T>
std::vector<T>& operator+=(std::vector<T> &a, const std::vector<T> &b) {
    int n = a.size();
    a.resize(n + b.size());
    std::copy(b.begin(), b.end(), a.begin() + n);
    return a;
}
template <typename T>
std::vector<T> operator+(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> c = a; return c += b;
}
template <typename T>
std::vector<T>& operator+=(std::vector<T> &a, const T &b) {
    a.push_back(b); return a;
}
template <typename T>
std::vector<T> operator+(const std::vector<T> &a, const T &b) {
    std::vector<T> c = a; return c += b;
}
template <typename T>
std::vector<T>& operator*=(std::vector<T> &a, const int repeat) {
    int n = a.size();
    a.resize(n * repeat);
    for (int i = 1; i < repeat; ++i) std::copy(a.begin(), a.end(), a.begin() + i * n);
    return a;
}
template <typename T>
std::vector<T> operator*(std::vector<T> &a, const int repeat) {
    std::vector<T> c = a; return c *= repeat;
}

#pragma endregion

// ! code from here

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    read(n, k);
    vec<int> a {0}, b {0}, c {0};
    rep(i, n) {
        int t, pa, pb;
        read(t, pa, pb);
        if (pa == 1 and pb == 1) {
            c.push_back(t);
        } else if (pa == 1) {
            a.push_back(t);
        } else if (pb == 1) {
            b.push_back(t);
        }
    }
    sort(all(a)), sort(all(b)), sort(all(c));
    int x = a.size(), y = b.size(), z = c.size();
    rep(i, x - 1) a[i + 1] += a[i];
    rep(i, y - 1) b[i + 1] += b[i];
    rep(i, z - 1) c[i + 1] += c[i];
    ll ans = LINF;
    rep(i, k + 1) {
        if (i >= z) break;
        int j = k - i;
        if (j < a.size() and j < b.size()) {
            chmin(ans, ll(a[j] + b[j] + c[i]));
        }
    }
    print(ans == LINF ? -1 : ans);
    return 0;
}