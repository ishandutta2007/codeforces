#include <bits/stdc++.h>

#pragma region

using namespace std;

// ! type aliases
using int128 = __int128_t;
using ll = long long;

template <typename T>
using vec = vector<T>;
using vi = vec<int>;
using vii = vec<vi>;
using vl = vec<ll>;
using vll = vec<vl>;

// ! macros
#define rep(i, n)          for (int i = 0; i < n; ++i)
#define reps(i, n, s)      for (int i = 0; i < n; i += s)
#define repl(i, l, r)      for (int i = l; i < r; ++i)
#define repls(i, l, r, s)  for (int i = l; i < r; i += s)
#define rrep(i, n)         for (int i = (n) - 1; i >= 0; --i)
#define rreps(i, n, s)     for (int i = (n) - 1; i >= 0; i -= s)
#define rrepl(i, l, r)     for (int i = (r) - 1; i >= l; --i)
#define rrepls(i, l, r, s) for (int i = (r) - 1; i >= l; i -= s)

#define all(iterable) (iterable).begin(), (iterable).end()

// ! constants
constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

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
template <typename T>
void read(vec<vec<T>>& a, size_t beg_i, size_t len_i, size_t beg_j, size_t len_j) {
    a.resize(beg_i + len_i);
    repl(i, beg_i, beg_i + len_i) read(a[i], beg_j, len_j);
}
template <typename T>
void read(vec<vec<T>>& a) {
    if (a.size()) read(a, 0, a.size(), 0, a[0].size());
}
template <typename T>
void read_graph(vec<vec<T>>& g, size_t n, size_t m, bool one_indexed_input = true) {
    g.resize(n);
    rep(i, m) {
        T u, v; cin >> u >> v;
        u -= one_indexed_input, v -= one_indexed_input;
        g[u].push_back(v), g[v].push_back(u);
    }
}
template <typename T, typename cost_t>
void read_graph(vec<vec<pair<T, cost_t>>>& g, size_t n, size_t m, bool one_indexed_input = true) {
    g.resize(n);
    rep(i, m) {
        T u, v; cost_t w; cin >> u >> v >> w;
        u -= one_indexed_input, v -= one_indexed_input;
        g[u].push_back({v, w}), g[v].push_back({u, w});
    }
}
template <typename T>
void read_digraph(vec<vec<T>>& g, size_t n, size_t m, bool one_indexed_input = true) {
    g.resize(n);
    rep(i, m) {
        T u, v; cin >> u >> v;
        u -= one_indexed_input, v -= one_indexed_input;
        g[u].push_back(v);
    }
}
template <typename T, typename cost_t>
void read_digraph(vec<vec<pair<T, cost_t>>>& g, size_t n, size_t m, bool one_indexed_input = true) {
    g.resize(n);
    rep(i, m) {
        T u, v; cost_t w; cin >> u >> v >> w;
        u -= one_indexed_input, v -= one_indexed_input;
        g[u].push_back({v, w});
    }
}

#pragma endregion

// ! code from here

template <unsigned int M>
class sieve_of_eratosthenes {
    using uint = unsigned int;
    using ull = unsigned long long;
    public:
        sieve_of_eratosthenes() {
            pf.resize(M + 1);
            build();
        }
        bool is_prime(uint v) {
            return pf[v] == v;
        }
        uint prime_factor(uint v) {
            return pf[v];
        }
        std::vector<std::pair<uint, uint>> factorize(uint v) {
            std::vector<std::pair<uint, uint>> pfs;
            while (v != 1) {
                uint p = pf[v], c = 0;
                do {
                    v /= p;
                    ++c;
                } while (v % p == 0);
                pfs.push_back({p, c});
            }
            return pfs;
        }
    private:
        std::vector<size_t> pf;
        constexpr void build() {
            pf[0] = 0;
            for (uint i = 1; i <= M; ++i) {
                if (i & 1) {
                    if (i % 3) pf[i] = i;
                    else pf[i] = 3;
                }
                else pf[i] = 2;
            }
            // for (uint i = 3; i * i <= M; i += 2) {
            //     if (pf[i] != i) continue;
            //     for (uint v = i * i; v <= M; v += 2 * i) {
            //         pf[v] = i;
            //     }
            // }
            // for (uint i = 3; i <= M; i += 6) {
            //     pf[i] = 3;
            // }
            for (uint i = 5; i * i <= M; i += 6) {
                uint p1 = i, p2 = i + 2;
                if (pf[p1] == p1) {
                    for (uint v = p1 * p1; v <= M; v += 2 * p1) {
                        pf[v] = p1;
                    }
                }
                if (pf[p2] == p2) {
                    for (uint v = p2 * p2; v <= M; v += 2 * p2) {
                        pf[v] = p2;
                    }
                }
            }
        }
};

constexpr size_t inf = 1 << 30;
constexpr size_t M = 10000001;

int main() {
    sieve_of_eratosthenes<M> sieve;
    vector<size_t> d(M), ans(M, inf);
    d[1] = ans[1] = 1;
    for (size_t i = 2; i < M; ++i) {
        size_t v = i;
        size_t p = sieve.prime_factor(v);
        size_t c = 1;
        do {
            v /= p;
            c = c * p + 1;
        } while (v % p == 0);
        size_t sum = d[i] = c * d[v];
        if (sum < M and ans[sum] == inf) ans[sum] = i;
    }
    size_t t;
    read(t);
    while (t --> 0) {
        size_t c;
        read(c);
        if (ans[c] == inf) {
            print(-1);
        } else {
            print(ans[c]);
        }
    }
    return 0;
}