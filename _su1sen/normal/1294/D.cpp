#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder


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

#define _rep4(i, l, r, s)  for (std::remove_reference_t<std::remove_const_t<decltype(r)>> i = (l); i < (r); i += (s))
#define _rep3(i, l, r)     _rep4(i, l, r, 1)
#define _rep2(i, n)        _rep3(i, 0, n)
#define _rrep4(i, l, r, s) for (std::remove_reference_t<std::remove_const_t<decltype(r)>> i = (l) + fld((r) - (l) - 1, s) * (s); i >= (l); i -= (s))
#define _rrep3(i, l, r)    _rrep4(i, l, r, 1)
#define _rrep2(i, n)       _rrep3(i, 0, n)

#define rep(...)  _overload4(__VA_ARGS__, _rep4 , _rep3 , _rep2, )(__VA_ARGS__)
#define rrep(...) _overload4(__VA_ARGS__, _rrep4, _rrep3, _rrep2,)(__VA_ARGS__)

#define _repinf3(i, l, s) for (std::remove_reference_t<std::remove_const_t<decltype(l)>> i = (l);; i += (s))
#define _repinf2(i, l)    _repinf3(i, l, 1)
#define _repinf1(i)       _repinf2(i, 0)

#define repinf(...) _overload3(__VA_ARGS__, _repinf3, _repinf2, _repinf1)(__VA_ARGS__)
#define loop(n) for (std::remove_reference_t<std::remove_const_t<decltype(n)>> loop_variable = n; loop_variable --> 0;)

#define all(iterable) (iterable).begin(), (iterable).end()
#define range_iter(iterable, l, r) ((iterable).begin() + (l)), ((iterable).begin() + (r))
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
void read(vec<T>& a, int begin_index, int length) {
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

// ! primitive utilities

template <typename T>
bool chmin(T &x, const T &y) {
    if (y >= x) return false;
    x = y;
    return true;
}
template <typename T>
bool chmin(T &x, const T &&y) {
    if (y >= x) return false;
    x = y;
    return true;
}
template <typename T>
bool chmax(T &x, const T &y) {
    if (y <= x) return false;
    x = y;
    return true;
}
template <typename T>
bool chmax(T &x, const T &&y) {
    if (y <= x) return false;
    x = y;
    return true;
}

template <typename T>
constexpr T fld(const T x, const T y) {
    return y < 0 ? fld(-x, -y) : (x >= 0 ? x / y : -((-x + y - 1) / y));
}
template <typename T>
constexpr T cld(const T x, const T y) {
    return y < 0 ? cld(-x, -y) : (x >= 0 ? (x + y - 1) / y : -(-x / y));
}

template <typename T>
constexpr int parity(const T x) { return x & 1; }

// ! container utilities

template <typename T>
void unique_erase(std::vector<T> &v) {
    v.erase(std::unique(v.begin(), v.end()), v.end());
}

template <typename T>
int count_leq(const std::vector<T> &v, const T &&key) {
    return std::upper_bound(v.begin(), v.end(), key) - v.begin(); 
}
template <typename T>
int count_lt(const std::vector<T> &v, const T &&key) {
    return std::lower_bound(v.begin(), v.end(), key) - v.begin(); 
}
template <typename T>
int count_geq(const std::vector<T> &v, const T &&key) {
    return v.size() - count_lt(v, key);
}
template <typename T>
int count_gt(const std::vector<T> &v, const T &&key) {
    return v.size() - count_leq(v, key);
}

template <typename _Container, typename _Key>
auto min_geq(const _Container &container, const _Key &&key) -> decltype(std::make_optional(*container.lower_bound(key))) {
    auto it = container.lower_bound(key);
    return it == container.end() ? std::nullopt : std::make_optional(*it);
}
template <typename _Container, typename _Key>
auto min_geq(const _Container &container, const _Key &key) -> decltype(std::make_optional(*container.lower_bound(key))) {
    auto it = container.lower_bound(key);
    return it == container.end() ? std::nullopt : std::make_optional(*it);
}
template <typename _Container, typename _Key>
auto min_gt(const _Container &container, const _Key &&key) -> decltype(std::make_optional(*container.upper_bound(key))) {
    auto it = container.upper_bound(key);
    return it == container.end() ? std::nullopt : std::make_optional(*it);
}
template <typename _Container, typename _Key>
auto min_gt(const _Container &container, const _Key &key) -> decltype(std::make_optional(*container.upper_bound(key))) {
    auto it = container.upper_bound(key);
    return it == container.end() ? std::nullopt : std::make_optional(*it);
}
template <typename _Container, typename _Key>
auto max_leq(const _Container &container, const _Key &&key) -> decltype(std::make_optional(*container.upper_bound(key))) {
    auto it = container.upper_bound(key);
    return it == container.begin() ? std::nullopt : std::make_optional(*--it);
}
template <typename _Container, typename _Key>
auto max_leq(const _Container &container, const _Key &key) -> decltype(std::make_optional(*container.upper_bound(key))) {
    auto it = container.upper_bound(key);
    return it == container.begin() ? std::nullopt : std::make_optional(*--it);
}
template <typename _Container, typename _Key>
auto max_lt(const _Container &container, const _Key &&key) -> decltype(std::make_optional(*container.lower_bound(key))) {
    auto it = container.lower_bound(key);
    return it == container.begin() ? std::nullopt : std::make_optional(*--it);
}
template <typename _Container, typename _Key>
auto max_lt(const _Container &container, const _Key &key) -> decltype(std::make_optional(*container.lower_bound(key))) {
    auto it = container.lower_bound(key);
    return it == container.begin() ? std::nullopt : std::make_optional(*--it);
}

template <typename T>
std::optional<T> min_geq(const std::vector<T> &v, const T &&key) {
    auto it = std::lower_bound(v.begin(), v.end(), key);
    return it == v.end() ? std::nullopt : std::make_optional(*it);
}
template <typename T>
std::optional<T> min_geq(const std::vector<T> &v, const T &key) {
    auto it = std::lower_bound(v.begin(), v.end(), key);
    return it == v.end() ? std::nullopt : std::make_optional(*it);
}
template <typename T>
std::optional<T> min_gt(const std::vector<T> &v, const T &&key) {
    auto it = std::upper_bound(v.begin(), v.end(), key);
    return it == v.end() ? std::nullopt : std::make_optional(*it);
}
template <typename T>
std::optional<T> min_gt(const std::vector<T> &v, const T &key) {
    auto it = std::upper_bound(v.begin(), v.end(), key);
    return it == v.end() ? std::nullopt : std::make_optional(*it);
}
template <typename T>
std::optional<T> max_leq(const std::vector<T> &v, const T &&key) {
    auto it = std::upper_bound(v.begin(), v.end(), key);
    return it == v.begin() ? std::nullopt : std::make_optional(*--it);
}
template <typename T>
std::optional<T> max_leq(const std::vector<T> &v, const T &key) {
    auto it = std::upper_bound(v.begin(), v.end(), key);
    return it == v.begin() ? std::nullopt : std::make_optional(*--it);
}
template <typename T>
std::optional<T> max_lt(const std::vector<T> &v, const T &&key) {
    auto it = std::lower_bound(v.begin(), v.end(), key);
    return it == v.begin() ? std::nullopt : std::make_optional(*--it);
}
template <typename T>
std::optional<T> max_lt(const std::vector<T> &v, const T &key) {
    auto it = std::lower_bound(v.begin(), v.end(), key);
    return it == v.begin() ? std::nullopt : std::make_optional(*--it);
}

#pragma endregion
// ! code from here


constexpr int op(int x, int y) { return x < y ? x : y; }
constexpr int e() { return numeric_limits<int>::max(); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input(int, q, x);
    atcoder::segtree<int, op, e> seg(vec<int>(x, 0));
    loop(q) {
        input(int, y);
        y %= x;
        seg.set(y, seg.get(y) + 1);
        int z = seg.all_prod();
        int r = seg.max_right(0, [z](int v) { return v > z; });
        print(x * z + r);
    }
    return 0;
}