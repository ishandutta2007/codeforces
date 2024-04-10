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
#define size_as_int(iterable) int((iterable).size())
#define input(type, ...) type __VA_ARGS__; read(__VA_ARGS__)

#define choose1(n, a) rep(a, n)
#define choose2(n, a, b) choose1((n) - 1, a) replr(b, a + 1, (n))
#define choose3(n, a, b, c) choose2((n) - 1, a, b) replr(c, b + 1, (n))
#define choose4(n, a, b, c, d) choose3((n) - 1, a, b, c) replr(d, c + 1, (n))
#define choose5(n, a, b, c, d, e) choose4((n) - 1, a, b, c, d) replr(e, d + 1, (n))

#define product1(n, a) rep(a, n)
#define product2(n, a, b) product1(n, a) product1(n, b)
#define product3(n, a, b, c) product2(n, a, b) product1(n, c)
#define product4(n, a, b, c, d) product3(n, a, b, c) product1(n, d)
#define product5(n, a, b, c, d, e) product4(n, a, b, c, d) product1(n, e)

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
template <typename _Iterable>
void unique_erase(_Iterable &iterable) {
    iterable.erase(unique(iterable.begin(), iterable.end()), iterable.end());
}


#pragma endregion
// ! code from here

constexpr ll f(const int l, const int w) {
    return (ll(l) << 32) | w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input(int, t);
    while (t --> 0) {
        input(int, n);
        auto comp = [](ll x, ll y) -> bool {
            int lx = x >> 32, wx = int(x);
            int ly = y >> 32, wy = int(y);
            return wx == wy ? lx > ly : wx < wy;
        };
        priority_queue<ll, vec<ll>, decltype(comp)> pq(comp);
        pq.push(f(0, n));
        vec<int> ans(n);
        int i = 1;
        while (pq.size()) {
            ll lw = pq.top(); pq.pop();
            int l = lw >> 32, w = int(lw);
            int r = l + w;
            int m = (l + r - 1) >> 1;
            ans[m] = i++;
            if (l < m) {
                pq.push(f(l, m - l));
            }
            ++m;
            if (m < r) {
                pq.push(f(m, r - m));
            }
        }
        print(ans);
    }
    return 0;
}