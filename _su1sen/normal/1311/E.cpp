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
#define _overload2(_1,_2,name,...) name
#define _overload3(_1,_2,_3,name,...) name
#define _overload4(_1,_2,_3,_4,name,...) name

#define _rep4(i, l, r, s)  for (std::remove_const_t<decltype(r)> i = (l); i < (r); i += (s))
#define _rep3(i, l, r)     _rep4(i, l, r, 1)
#define _rep2(i, n)        _rep4(i, 0, n, 1)
#define _rrep4(i, l, r, s) for (std::remove_const_t<decltype(r)> i = (l) + fld((r) - (l) - 1, s) * (s); i >= (l); i -= (s))
#define _rrep3(i, l, r)    _rrep4(i, l, r, 1)
#define _rrep2(i, n)       _rrep4(i, 0, n, 1)

#define rep(...)  _overload4(__VA_ARGS__, _rep4 , _rep3 , _rep2, )(__VA_ARGS__)
#define rrep(...) _overload4(__VA_ARGS__, _rrep4, _rrep3, _rrep2,)(__VA_ARGS__)

#define _repinf3(i, l, s) for (std::remove_const_t<decltype(l)> i = (l);; i += (s))
#define _repinf2(i, l)    _repinf3(i, l, 1)
#define _repinf1(i)       _repinf2(i, 0)

#define repinf(...) _overload3(__VA_ARGS__, _repinf3, _repinf2, _repinf1)(__VA_ARGS__)

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

constexpr int M = 5010;

vec<pair<int, int>> valid_range(M);

void precalc_valid_ranges() {
    valid_range[0] = {0, 0};
    int l = 0;
    for (int i = 0, n = 0; n < M; ++i) {
        rep(j, 1 << i) {
            l += i;
            if (++n >= M) break;
            valid_range[n] = {l, n * (n - 1) / 2};
        }
    }
}

bool exists_valid_tree(int n, int d) {
    auto [l, r] = valid_range[n];
    return l <= d and d <= r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc_valid_ranges();
    input(int, t);
    loop(t) {
        input(int, n, d);
        vec<int> ans(n - 1);
        int id = 0;
        auto rec = [&id, &ans](auto self, int n, int d) -> int {
            if (n == 0) return -1;
            int node_id = id++;
            d -= n - 1;
            repinf(n1) {
                int n2 = n - 1 - n1;
                auto [l1, r1] = valid_range[n1];
                auto [l2, r2] = valid_range[n2];
                if (d < l1 + l2 or r1 + r2 < d) continue;
                int d1 = max(l1, d - r2), d2 = d - d1;
                int id1 = self(self, n1, d1);
                int id2 = self(self, n2, d2);
                if (id1 >= 0) ans[id1 - 1] = node_id + 1;
                if (id2 >= 0) ans[id2 - 1] = node_id + 1;
                return node_id;
            }
        };
        if (exists_valid_tree(n, d)) {
            rec(rec, n, d);
            print("YES");
            print(ans);
        } else {
            print("NO");
        }
    }
    return 0;
}