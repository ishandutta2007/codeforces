#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>

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

#include <optional>
#include <vector>

namespace suisen {
    template <typename T>
    struct Matrix {
        std::vector<std::vector<T>> data;

        Matrix() {}
        Matrix(int n, int m, T fill_value = T(0)) : data(n, std::vector<T>(m, fill_value)) {}
        Matrix(const std::vector<std::vector<T>>& data) noexcept : data(data) {}
        Matrix(std::vector<std::vector<T>>&& data) noexcept : data(std::move(data)) {}
        Matrix(const Matrix<T>& other) noexcept : data(other.data) {}
        Matrix(Matrix<T>&& other) noexcept : data(std::move(other.data)) {}

        Matrix<T>& operator=(const Matrix<T>& other) noexcept {
            data = other.data;
            return *this;
        }
        Matrix<T>& operator=(Matrix<T>&& other) noexcept {
            data = std::move(other.data);
            return *this;
        }

        const std::vector<T>& operator[](int i) const { return data[i]; }
        std::vector<T>& operator[](int i) { return data[i]; }

        std::pair<int, int> size() const {
            if (data.empty()) {
                return { 0, 0 };
            } else {
                return { data.size(), data[0].size() };
            }
        }
        int row_size() const {
            return data.size();
        }
        int col_size() const {
            return data.empty() ? 0 : data[0].size();
        }

        Matrix<T>& operator+=(const Matrix<T>& other) {
            assert(size() == other.size());
            auto [n, m] = size();
            for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
                data[i][j] += other[i][j];
            }
            return *this;
        }
        Matrix<T>& operator-=(const Matrix<T>& other) {
            assert(size() == other.size());
            auto [n, m] = size();
            for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
                data[i][j] -= other[i][j];
            }
            return *this;
        }
        Matrix<T>& operator*=(const Matrix<T>& other) {
            return *this = *this * other;
        }
        Matrix<T>& operator*=(const T& val) {
            auto [n, m] = size();
            for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
                data[i][j] *= val;
            }
            return *this;
        }
        Matrix<T>& operator/=(const T& val) {
            return *this *= T(1) / val;
        }
        Matrix<T> operator+(const Matrix<T>& other) const {
            return Matrix<T>(*this) += other;
        }
        Matrix<T> operator-(const Matrix<T>& other) const {
            return Matrix<T>(*this) -= other;
        }
        Matrix<T> operator*(const Matrix<T>& other) const {
            auto [n, m] = size();
            auto [m2, l] = other.size();
            assert(m == m2);
            std::vector res(n, std::vector(l, T(0)));
            for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < l; ++k) {
                res[i][k] += (*this)[i][j] * other[j][k];
            }
            return res;
        }
        Matrix<T> operator*(const T& val) const {
            return Matrix<T>(*this) *= val;
        }
        Matrix<T> operator/(const T& val) const {
            return Matrix<T>(*this) /= val;
        }

        std::vector<T> operator*(const std::vector<T>& x) const {
            auto [n, m] = size();
            assert(m == int(x.size()));
            std::vector<T> b(n, T(0));
            for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
                b[i] += data[i][j] * x[j];
            }
            return b;
        }
    };

    template <typename T>
    class SquareMatrix : public Matrix<T> {
    public:
        SquareMatrix() {}
        SquareMatrix(int n, T fill_value = T(0)) : Matrix<T>::Matrix(n, n, fill_value) {}
        SquareMatrix(const std::vector<std::vector<T>>& data) : Matrix<T>::Matrix(data) {
            auto [n, m] = this->size();
            assert(n == m);
        }
        SquareMatrix(std::vector<std::vector<T>>&& data) : Matrix<T>::Matrix(std::move(data)) {
            auto [n, m] = this->size();
            assert(n == m);
        }
        SquareMatrix(const SquareMatrix<T>& other) : SquareMatrix(other.data) {}
        SquareMatrix(SquareMatrix<T>&& other) : SquareMatrix(std::move(other.data)) {}
        SquareMatrix(const Matrix<T>& other) : Matrix<T>::Matrix(other.data) {}
        SquareMatrix(Matrix<T>&& other) : Matrix<T>::Matrix(std::move(other.data)) {}

        SquareMatrix<T>& operator=(const SquareMatrix<T>& other) noexcept {
            this->data = other.data;
            return *this;
        }
        SquareMatrix<T>& operator=(SquareMatrix<T>&& other) noexcept {
            this->data = std::move(other.data);
            return *this;
        }

        bool operator==(const SquareMatrix<T>& other) noexcept {
            return this->data == other.data;
        }
        bool operator!=(const SquareMatrix<T>& other) noexcept {
            return this->data != other.data;
        }

        static SquareMatrix<T> e0(int n) { return SquareMatrix<T>(n, false); }
        static SquareMatrix<T> e1(int n) { return SquareMatrix<T>(n, true); }

        static std::optional<SquareMatrix<T>> inv(SquareMatrix<T>&& A) {
            auto& data = A.data;
            int n = data.size();
            for (int i = 0; i < n; ++i) {
                data[i].resize(2 * n, T{ 0 });
                data[i][n + i] = T{ 1 };
            }
            for (int i = 0; i < n; ++i) {
                int pivot = -1;
                for (int k = i; k < n; ++k) {
                    if (data[k][i] != T{ 0 }) {
                        pivot = k;
                        break;
                    }
                }
                if (pivot < 0) return std::nullopt;
                data[i].swap(data[pivot]);
                T coef = T{ 1 } / data[i][i];
                for (int j = i; j < 2 * n; ++j) data[i][j] *= coef;
                for (int k = 0; k < n; ++k) {
                    if (k == i or data[k][i] == T{ 0 }) continue;
                    T c = data[k][i];
                    for (int j = i; j < 2 * n; ++j) data[k][j] -= c * data[i][j];
                }
            }
            for (auto& row : data) row.erase(row.begin(), row.begin() + n);
            return std::make_optional(std::move(A));
        }
        static std::optional<SquareMatrix<T>> inv(const SquareMatrix<T>& A) {
            return SquareMatrix<T>::inv(SquareMatrix<T>(A));
        }
        static T det(SquareMatrix<T>&& A) {
            auto& data = A.data;
            T det_inv = T{ 1 };
            int n = data.size();
            for (int i = 0; i < n; ++i) {
                int pivot = -1;
                for (int k = i; k < n; ++k) {
                    if (data[k][i] != T{ 0 }) {
                        pivot = k;
                        break;
                    }
                }
                if (pivot < 0) return T{ 0 };
                data[i].swap(data[pivot]);
                if (pivot != i) det_inv *= T{ -1 };
                T coef = T{ 1 } / data[i][i];
                for (int j = i; j < n; ++j) data[i][j] *= coef;
                det_inv *= coef;
                for (int k = i + 1; k < n; ++k) {
                    if (data[k][i] == T(0)) continue;
                    T c = data[k][i];
                    for (int j = i; j < n; ++j) data[k][j] -= c * data[i][j];
                }
            }
            return T{ 1 } / det_inv;
        }
        static T det(const SquareMatrix<T>& A) {
            return SquareMatrix<T>::det(SquareMatrix<T>(A));
        }
        SquareMatrix<T>& inv_inplace() {
            return *this = *SquareMatrix<T>::inv(std::move(*this));
        }
        SquareMatrix<T> inv() const {
            return *SquareMatrix<T>::inv(*this);
        }
        T det() const {
            return SquareMatrix<T>::det(SquareMatrix<T>(*this));
        }

        SquareMatrix<T>& operator/=(const SquareMatrix<T>& other) { return *this *= other.inv(); }
        SquareMatrix<T>& operator/=(SquareMatrix<T>&& other) { return *this *= other.inv_inplace(); }
        SquareMatrix<T>  operator/ (const SquareMatrix<T>& other) const { return SquareMatrix<T>(*this) *= other.inv(); }
        SquareMatrix<T>  operator/ (SquareMatrix<T>&& other) const { return SquareMatrix<T>(*this) *= other.inv_inplace(); }

        SquareMatrix<T> pow(long long b) {
            assert(b >= 0);
            SquareMatrix<T> res(SquareMatrix<T>::e1(this->data.size())), p(*this);
            for (; b; b >>= 1) {
                if (b & 1) res *= p;
                p *= p;
            }
            return res;
        }
    private:
        SquareMatrix(int n, bool mult_identity) : Matrix<T>::Matrix(n, n) {
            if (mult_identity) for (int i = 0; i < n; ++i) this->data[i][i] = 1;
        }
    };
} // namespace suisen

using suisen::SquareMatrix;

using mint = atcoder::modint998244353;

std::istream& operator>>(std::istream& in, mint &a) {
    long long e; in >> e; a = e;
    return in;
}

std::ostream& operator<<(std::ostream& out, const mint &a) {
    out << a.val();
    return out;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (auto &e : s) std::cin >> e;

    std::map<std::pair<int, int>, int> id;
    std::vector<std::pair<int, int>> state;
    int state_id = 0;
    for (int i = 0; i < n; ++i) {
        int l = s[i].size();
        for (int j = 1; j < l; ++j) {
            id[{ i, j }] = state_id++;
            state.emplace_back(i, j);
        }
    }
    for (int i = 0; i < n; ++i) {
        id[{ i, s[i].size() }] = state_id;
    }

    auto next_state = [&](int s1, int s2) {
        std::vector<std::pair<int, int>> res;
        if (s1 == state_id and s2 == state_id) {
            for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
                int l = std::min(int(s[i].size()), int(s[j].size()));
                if (s[i].substr(0, l) != s[j].substr(0, l)) continue;
                res.emplace_back(id[{ i, 1 }], id[{ j, 1 }]);
            }
        } else if (s1 == state_id) {
            auto [j, lj] = state[s2];
            for (int i = 0; i < n; ++i) {
                int l = std::min(int(s[i].size()), int(s[j].size()) - lj);
                if (s[i].substr(0, l) != s[j].substr(lj, l)) continue;
                res.emplace_back(id[{ i, 1 }], id[{ j, lj + 1 }]);
            }
        } else if (s2 == state_id) {
            auto [i, li] = state[s1];
            for (int j = 0; j < n; ++j) {
                int l = std::min(int(s[i].size()) - li, int(s[j].size()));
                if (s[i].substr(li, l) != s[j].substr(0, l)) continue;
                res.emplace_back(id[{ i, li + 1 }], id[{ j, 1 }]);
            }
        } else {
            auto [i, li] = state[s1];
            auto [j, lj] = state[s2];
            assert(s[i][li] == s[j][lj]);
            res.emplace_back(id[{ i, li + 1 }], id[{ j, lj + 1 }]);
        }
        return res;
    };

    std::map<std::pair<int, int>, int> id2;
    std::vector<std::pair<int, int>> state2;
    int state_id2 = 0;
    auto dfs = [&](auto dfs, int s1, int s2) -> void {
        id2[{ s1, s2 }] = state_id2++;
        state2.emplace_back(s1, s2);
        for (auto [t1, t2] : next_state(s1, s2)) {
            auto it = id2.find({ t1, t2 });
            if (it != id2.end()) continue;
            dfs(dfs, t1, t2);
        }
    };
    dfs(dfs, state_id, state_id);

    int k = state_id2;
    SquareMatrix<mint> T(k);

    for (int j = 0; j < k; ++j) {
        auto [s1, s2] = state2[j];
        for (auto [t1, t2] : next_state(s1, s2)) {
            auto it = id2.find({ t1, t2 });
            if (it == id2.end()) continue;
            int i = it->second;
            T[i][j]++;
        }
    }

    int init = id2[{ state_id, state_id }];
    std::vector<mint> x(k);
    x[init] = 1;

    std::cout << (T.pow(m) * x)[init].val() << std::endl;

    return 0;
}