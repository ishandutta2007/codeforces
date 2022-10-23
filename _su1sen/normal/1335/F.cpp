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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input(int, t);
    loop(t) {
        input(int, n, m);
        string c, d;
        c.reserve(n * m);
        d.reserve(n * m);
        rep(i, n) {
            input(string, row);
            for (char ch : row) c += ch;
        }
        rep(i, n) {
            input(string, row);
            for (char ch : row) d += ch;
        }
        auto trans = [&](int ij) -> int {
            if (d[ij] == 'L') {
                return ij - 1;
            } else if (d[ij] == 'R') {
                return ij + 1;
            } else if (d[ij] == 'U') {
                return ij - m;
            } else {
                return ij + m;
            }
        };
        int sum_cycle_size = 0;
        int sum_black = 0;
        vec<char> blk;
        blk.reserve(n * m);
        vec<int> beg;
        int cycle_id = 0;
        vec<int> last(n * m, -1);
        const ll init = numeric_limits<ll>::max();
        vec<ll> cycle(n * m, init);
        auto dfs = [&](auto self, int ij, int time) -> ll {
            if (cycle[ij] != init) return cycle[ij];
            if (last[ij] >= 0) {
                int loop_length = time - last[ij];
                sum_cycle_size += loop_length;
                beg.push_back(blk.size());
                int cij = ij;
                rep(i, loop_length) {
                    if (c[cij] == '0') {
                        blk.push_back(true);
                        ++sum_black;
                    } else {
                        blk.push_back(false);
                    }
                    cycle[cij] = (ll(cycle_id) << 42) | ll(i) << 21 | loop_length;
                    cij = trans(cij);
                }
                cycle_id++;
            } else {
                last[ij] = time;
                int nij = trans(ij);
                ll id_mod_len = self(self, nij, time + 1);
                int id = id_mod_len >> 42;
                int mod = (id_mod_len >> 21) & ((1 << 21) - 1);
                int len = id_mod_len & ((1 << 21) - 1);
                if (mod == 0) {
                    mod = len - 1;
                } else {
                    mod = mod - 1;
                }
                cycle[ij] = (ll(id) << 42) | ll(mod) << 21 | len;
                if (not blk[beg[id] + mod] and c[ij] == '0') {
                    blk[beg[id] + mod] = true;
                    ++sum_black;
                }
                last[ij] = -1;
            }
            return cycle[ij];
        };
        rep(ij, n * m) {
            dfs(dfs, ij, 0);
        }
        print(sum_cycle_size, sum_black);
    }
    return 0;
}