#define PROBLEM "https://atcoder.jp/contests/arc115/tasks/arc115_e"

#include <algorithm>
#include <iostream>

#include <cassert>
#include <numeric>
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif

#include <utility>

#ifdef _MSC_VER
#endif

namespace atcoder {

namespace internal {

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
// NOTE: reconsider after Ice Lake
struct barrett {
    unsigned int _m;
    unsigned long long im;

    // @param m `1 <= m < 2^31`
    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    // @return m
    unsigned int umod() const { return _m; }

    // @param a `0 <= a < m`
    // @param b `0 <= b < m`
    // @return `a * b % m`
    unsigned int mul(unsigned int a, unsigned int b) const {
        // [1] m = 1
        // a = b = im = 0, so okay

        // [2] m >= 2
        // im = ceil(2^64 / m)
        // -> im * m = 2^64 + r (0 <= r < m)
        // let z = a*b = c*m + d (0 <= c, d < m)
        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im
        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2
        // ((ab * im) >> 64) == c or c + 1
        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

// @param n `n < 2^32`
// @param m `1 <= m < 2^32`
// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)
unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        // y_max < m * (n + 1)
        // floor(y_max / m) <= n
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
    using mint = dynamic_modint;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt(998244353);

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

}  // namespace atcoder

using mint = atcoder::modint998244353;

std::istream& operator>>(std::istream& in, mint &a) {
    long long e; in >> e; a = e;
    return in;
}

std::ostream& operator<<(std::ostream& out, const mint &a) {
    out << a.val();
    return out;
}

#include <cassert>
#include <vector>

#include <limits>
#include <type_traits>

namespace suisen {

template <typename T, typename UpdateFunc>
struct UpdateProxyObject {
    public:
        UpdateProxyObject(T &v, UpdateFunc update) : v(v), update(update) {}
        operator T() const { return v; }
        auto& operator++() && { ++v, update(); return *this; }
        auto& operator--() && { --v, update(); return *this; }
        auto& operator+=(const T &val) && { v += val, update(); return *this; }
        auto& operator-=(const T &val) && { v -= val, update(); return *this; }
        auto& operator*=(const T &val) && { v *= val, update(); return *this; }
        auto& operator/=(const T &val) && { v /= val, update(); return *this; }
        auto& operator%=(const T &val) && { v %= val, update(); return *this; }
        auto& operator =(const T &val) && { v  = val, update(); return *this; }
        auto& operator<<=(const T &val) && { v <<= val, update(); return *this; }
        auto& operator>>=(const T &val) && { v >>= val, update(); return *this; }
        template <typename F>
        auto& apply(F f) && { v = f(v), update(); return *this; }
    private:
        T &v;
        UpdateFunc update;
};

} // namespace suisen

namespace suisen {
template <
    typename index_t,               // type of index (integral: int, long long, etc.)
    typename T,                     // type of element
    typename OpTT,                  // type of binary operator on T
    typename F,                     // type of operator which acts on T
    typename OpFT,                  // type of action F on T
    typename OpFF,                  // type of binary operator on F
    typename ProductInitializer     // type of function which initializes product of segment [l, r)
>
class SparseLazySegmentTree {
    using unsigned_index_t = typename std::make_unsigned_t<index_t>;

    struct Node {
        Node *par;
        Node *ch[2] { nullptr, nullptr };
        unsigned_index_t l, r;
        T dat;
        F laz;
        Node(Node *par, unsigned_index_t l, unsigned_index_t r, const T &dat, const F &laz) : par(par), l(l), r(r), dat(dat), laz(laz) {}
        ~Node() {
            delete ch[0];
            delete ch[1];
        }
    };

    public:
        SparseLazySegmentTree() : SparseLazySegmentTree(0, T{}, OpTT{}, F{}, OpFT{}, OpFF{}, ProductInitializer{}) {}
        /**
         * 1. number of element
         * 2. id of . x:T, xe=ex=x .
         * 3. (x,y) -> xy
         * 4. id of . f:F, fid=idf=f, x:T, id(x)=x.
         * 5. (f,x) -> f(x). x,y:T, f,g:F, f(x)g(y)=(fg)(xy).
         * 6. (f,g) -> fg
         * 7. (l,r) -> initial product of segment [l,r).
         */
        SparseLazySegmentTree(index_t n, T e, OpTT op, F id, OpFT mapping, OpFF composition, ProductInitializer init) : n(n), e(e), op(op), id(id), mapping(mapping), composition(composition), init(init), root(new Node(nullptr, 0, n, init(0, n), id)) {}

        ~SparseLazySegmentTree() {
            delete root;
        }

        auto operator[](unsigned_index_t i) {
            assert(i < n);
            Node* leaf = get_or_create_leaf(i);
            return UpdateProxyObject { leaf->dat, [this, leaf]{ update_from(leaf); } };
        }

        T get(unsigned_index_t i) {
            return (*this)[i];
        }
        void set(unsigned_index_t i, const T& val) {
            (*this)[i] = val;
        }
        void apply(unsigned_index_t i, const F &f) {
            (*this)[i].apply([this, f](const T &dat) { return mapping(f, dat); });
        }

        T operator()(unsigned_index_t l, unsigned_index_t r) {
            assert(l <= r and r <= n);
            return query(root, l, r);
        }
        T prod(unsigned_index_t l, unsigned_index_t r) {
            return (*this)(l, r);
        }
        T prod_all() {
            return root->dat;
        }

        void apply(unsigned_index_t l, unsigned_index_t r, const F &f) {
            assert(l <= r and r <= n);
            apply(root, l, r, f);
        }
        void apply_all(const F &f) {
            apply_all(root, f);
        }

    private:
        unsigned_index_t n;
        T e;
        OpTT op;
        F id;
        OpFT mapping;
        OpFF composition;
        ProductInitializer init;
        Node* root;

        Node* get_or_create_leaf(unsigned_index_t i) {
            Node *cur = root;
            while (cur->r - cur->l > 1) {
                push(cur);
                cur = cur->ch[i >= (cur->l + cur->r) >> 1];
            }
            return cur;
        }

        Node* get_or_create_child(Node* node, int index) {
            if (not node->ch[index]) {
                unsigned_index_t l = node->l, r = node->r, m = (l + r) >> 1;
                unsigned_index_t cl = index ? m : l;
                unsigned_index_t cr = index ? r : m;
                node->ch[index] = new Node(node, cl, cr, init(cl, cr), id);
            }
            return node->ch[index];
        }
    
        void apply_all(Node* node, const F &f) {
            node->dat = mapping(f, node->dat);
            node->laz = composition(f, node->laz);
        }

        void push(Node* node) {
            apply_all(get_or_create_child(node, 0), node->laz);
            apply_all(get_or_create_child(node, 1), node->laz);
            node->laz = id;
        }

        void update(Node* node) {
            node->dat = op(node->ch[0]->dat, node->ch[1]->dat);
        }
        void update_from(Node* leaf) {
            while (leaf->par) update(leaf = leaf->par);
        }

        T query(Node *node, unsigned_index_t ql, unsigned_index_t qr) {
            unsigned_index_t tl = node->l, tr = node->r;
            if (tr <= ql or qr <= tl) return e;
            if (ql <= tl and tr <= qr) return node->dat;
            push(node);
            return op(query(node->ch[0], ql, qr), query(node->ch[1], ql, qr));
        }

        void apply(Node *node, unsigned_index_t ql, unsigned_index_t qr, const F &f) {
            unsigned_index_t tl = node->l, tr = node->r;
            if (tr <= ql or qr <= tl) return;
            if (ql <= tl and tr <= qr) return apply_all(node, f);
            push(node);
            apply(node->ch[0], ql, qr, f);
            apply(node->ch[1], ql, qr, f);
            update(node);
        }
};

}

using suisen::SparseLazySegmentTree;

struct S {
    mint sum;
    int len;
};

struct F {
    mint a, b;
};

S e { 0, 0 };
S op(const S &x, const S &y) {
    return { x.sum + y.sum, x.len + y.len };
}
F id { 1, 0 };
S mapping(const F &f, const S &x) {
    return { f.a * x.sum + f.b * x.len, x.len };
}
F composition(const F &f, const F &g) {
    return { f.a * g.a, f.a * g.b + f.b };
}
S init(int l, int r) {
    return S { 0, r - l };
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &e : a) std::cin >> e;
    const int m = *std::max_element(a.begin(), a.end());
    SparseLazySegmentTree seg(m, e, op, id, mapping, composition, init);
    mint sum = 1;
    for (int v : a) {
        seg.apply_all({ -1, sum });
        seg.apply(v, m, { 0, 0 });
        sum = seg.prod_all().sum;
    }
    std::cout << seg.prod_all().sum << '\n';
    return 0;
}