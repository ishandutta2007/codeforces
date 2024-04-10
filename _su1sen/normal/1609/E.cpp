#include <iostream>
#include <limits>

#include <algorithm>
#include <cassert>
#include <vector>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
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

#include <array>
#include <optional>

namespace suisen {
    namespace default_operator {
        template <typename T>
        auto zero() -> decltype(T { 0 }) { return T { 0 }; }
        template <typename T>
        auto one()  -> decltype(T { 1 }) { return T { 1 }; }
        template <typename T>
        auto add(const T &x, const T &y) -> decltype(x + y) { return x + y; }
        template <typename T>
        auto sub(const T &x, const T &y) -> decltype(x - y) { return x - y; }
        template <typename T>
        auto mul(const T &x, const T &y) -> decltype(x * y) { return x * y; }
        template <typename T>
        auto div(const T &x, const T &y) -> decltype(x / y) { return x / y; }
        template <typename T>
        auto mod(const T &x, const T &y) -> decltype(x % y) { return x % y; }
        template <typename T>
        auto neg(const T &x) -> decltype(-x) { return -x; }
        template <typename T>
        auto inv(const T &x) -> decltype(one<T>() / x)  { return one<T>() / x; }
    } // default_operator
    namespace default_operator_noref {
        template <typename T>
        auto zero() -> decltype(T { 0 }) { return T { 0 }; }
        template <typename T>
        auto one()  -> decltype(T { 1 }) { return T { 1 }; }
        template <typename T>
        auto add(T x, T y) -> decltype(x + y) { return x + y; }
        template <typename T>
        auto sub(T x, T y) -> decltype(x - y) { return x - y; }
        template <typename T>
        auto mul(T x, T y) -> decltype(x * y) { return x * y; }
        template <typename T>
        auto div(T x, T y) -> decltype(x / y) { return x / y; }
        template <typename T>
        auto mod(T x, T y) -> decltype(x % y) { return x % y; }
        template <typename T>
        auto neg(T x) -> decltype(-x) { return -x; }
        template <typename T>
        auto inv(T x) -> decltype(one<T>() / x)  { return one<T>() / x; }
    } // default_operator
} // namespace suisen

namespace suisen {
    template <
        typename T, size_t N, size_t M,
        T(*_add)(T, T) = default_operator_noref::add<T>, T(*_neg)(T) = default_operator_noref::neg<T>, T(*_zero)() = default_operator_noref::zero<T>,
        T(*_mul)(T, T) = default_operator_noref::mul<T>, T(*_inv)(T) = default_operator_noref::inv<T>, T(*_one)()  = default_operator_noref::one<T>
    >
    struct ArrayMatrix : public std::array<std::array<T, M>, N> {
    private:
        enum Operator { Add, Mul };
        template <typename DummyType = void>
        static constexpr bool is_square_v = N == M;
    public:
#define MatrixType(N, M) ArrayMatrix<T, N, M, _add, _neg, _zero, _mul, _inv, _one>
        using base_type = std::array<std::array<T, M>, N>;
        using container_type = base_type;
        using row_type = std::array<T, M>;

        using base_type::base_type;
        constexpr ArrayMatrix() : ArrayMatrix(_zero()) {}
        constexpr ArrayMatrix(T fill_value) : base_type{} {
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) (*this)[i][j] = fill_value;
        }
        constexpr ArrayMatrix(const container_type &c) : base_type{c} {}
        constexpr ArrayMatrix(const std::initializer_list<row_type> &c) : base_type{} {
            assert(c.size() == N);
            size_t i = 0;
            for (const auto &row : c) {
                for (size_t j = 0; j < M; ++j) (*this)[i][j] = row[j];
                ++i;
            }
        }

        static constexpr ArrayMatrix e0() { return ArrayMatrix(Operator::Add); }
        static constexpr MatrixType(M, M) e1() { return MatrixType(M, M)(Operator::Mul); }

        constexpr int size() const {
            static_assert(is_square_v<>);
            return N;
        }
        constexpr std::pair<int, int> shape() const { return { N, M }; }
        constexpr int row_size() const { return N; }
        constexpr int col_size() const { return M; }

        constexpr ArrayMatrix operator+() const { return *this; }
        constexpr ArrayMatrix operator-() const {
            ArrayMatrix res;
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) res[i][j] = _neg((*this)[i][j]);
            return res;
        }
        constexpr ArrayMatrix& operator+=(const ArrayMatrix& other) {
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) (*this)[i][j] = _add((*this)[i][j], other[i][j]);
            return *this;
        }
        constexpr ArrayMatrix& operator-=(const ArrayMatrix& other) {
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) (*this)[i][j] = _add((*this)[i][j], _neg(other[i][j]));
            return *this;
        }
        template <size_t K>
        constexpr MatrixType(N, K)& operator*=(const MatrixType(M, K)& other) { return *this = *this * other; }
        constexpr ArrayMatrix& operator*=(const T& val) {
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) (*this)[i][j] = _mul((*this)[i][j], val);
            return *this;
        }
        constexpr ArrayMatrix& operator/=(const T& val) { return *this *= _inv(val); }
        constexpr friend ArrayMatrix operator+(ArrayMatrix lhs, const ArrayMatrix& rhs) { lhs += rhs; return lhs; }
        constexpr friend ArrayMatrix operator-(ArrayMatrix lhs, const ArrayMatrix& rhs) { lhs -= rhs; return lhs; }
        template <size_t K>
        constexpr friend MatrixType(N, K) operator*(const ArrayMatrix& lhs, const MatrixType(M, K)& rhs) {
            MatrixType(N, K) res;
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) for (size_t k = 0; k < K; ++k) {
                res[i][k] = _add(res[i][k], _mul(lhs[i][j], rhs[j][k]));
            }
            return res;
        }
        constexpr friend ArrayMatrix operator*(ArrayMatrix A, const T& val) { A *= val; return A; }
        constexpr friend ArrayMatrix operator*(const T& val, ArrayMatrix A) { A *= val; return A; }
        constexpr friend ArrayMatrix operator/(ArrayMatrix A, const T& val) { A /= val; return A; }

        constexpr std::array<T, N> operator*(const std::array<T, M>& x) const {
            std::array<T, N> b;
            b.fill(_zero());
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) b[i] = _add(b[i], _mul((*this)[i][j], x[j]));
            return b;
        }

        static constexpr std::optional<ArrayMatrix> inv(const ArrayMatrix& A) {
            static_assert(is_square_v<>);
            std::array<std::array<T, 2 * N>, N> data;
            for (size_t i = 0; i < N; ++i) {
                for (size_t j = 0; j < N; ++j) {
                    data[i][j] = A[i][j];
                    data[i][N + j] = i == j ? _one() : _zero();
                }
            }
            for (size_t i = 0; i < N; ++i) {
                int pivot = -1;
                for (size_t k = i; k < N; ++k) if (data[k][i] != _zero()) {
                    pivot = k;
                    break;
                }
                if (pivot < 0) return std::nullopt;
                data[i].swap(data[pivot]);
                T coef = _inv(data[i][i]);
                for (size_t j = i; j < 2 * N; ++j) data[i][j] = _mul(data[i][j], coef);
                for (size_t k = 0; k < N; ++k) if (k != i and data[k][i] != _zero()) {
                    T c = data[k][i];
                    for (size_t j = i; j < 2 * N; ++j) data[k][j] = _add(data[k][j], _neg(_mul(c, data[i][j])));
                }
            }
            ArrayMatrix res;
            for (size_t i = 0; i < N; ++i) std::copy(data[i].begin(), data[i].begin() + N, res[i].begin());
            return res;
        }
        static constexpr T det(ArrayMatrix A) {
            static_assert(is_square_v<>);
            bool sgn = false;
            for (size_t j = 0; j < N; ++j) for (size_t i = j + 1; i < N; ++i) if (A[i][j] != _zero()) {
                std::swap(A[j], A[i]);
                T q = _mul(A[i][j], _inv(A[j][j]));
                for (size_t k = j; k < N; ++k) A[i][k] = _add(A[i][k], _neg(_mul(A[j][k], q)));
                sgn = not sgn;
            }
            T res = sgn ? _neg(_one()) : _one();
            for (size_t i = 0; i < N; ++i) res = _mul(res, A[i][i]);
            return res;
        }
        constexpr std::optional<ArrayMatrix> inv() const { static_assert(is_square_v<>); return inv(*this); }
        constexpr T det() const { static_assert(is_square_v<>); return det(*this); }

        constexpr ArrayMatrix& operator/=(const ArrayMatrix& other) { static_assert(is_square_v<>); return *this *= other.inv(); }
        constexpr ArrayMatrix  operator/ (const ArrayMatrix& other) const { static_assert(is_square_v<>); return ArrayMatrix(*this) *= *other.inv(); }

        constexpr ArrayMatrix pow(long long b) const {
            static_assert(is_square_v<>);
            assert(b >= 0);
            ArrayMatrix res(e1()), p(*this);
            for (; b; b >>= 1) {
                if (b & 1) res *= p;
                p *= p;
            }
            return res;
        }
    private:
        constexpr ArrayMatrix(Operator op) : ArrayMatrix(_zero()) {
            if (op == Operator::Mul) for (size_t i = 0; i < N; ++i) (*this)[i][i] = _one();
        }
#undef MatrixType
    };
    template <
        typename T, size_t N,
        T(*_add)(T, T) = default_operator_noref::add<T>, T(*_neg)(T) = default_operator_noref::neg<T>, T(*_zero)() = default_operator_noref::zero<T>,
        T(*_mul)(T, T) = default_operator_noref::mul<T>, T(*_inv)(T) = default_operator_noref::inv<T>, T(*_one)()  = default_operator_noref::one<T>
    >
    using SquareArrayMatrix = ArrayMatrix<T, N, N, _add, _neg, _zero, _mul, _inv, _one>;
} // namespace suisen

using suisen::SquareArrayMatrix;

constexpr int I = std::numeric_limits<int>::max() / 2;

constexpr int add(int x, int y) {
    return std::min(x, y);
}
int neg(int) {
    assert(false);
}
constexpr int zero() {
    return I;
}
constexpr int mul(int x, int y) {
    return x + y;
}
constexpr int inv(int x) {
    return -x;
}
constexpr int one() {
    return 0;
}

using matrix = SquareArrayMatrix<int, 3, add, neg, zero, mul, inv, one>;

constexpr std::array<matrix, 3> T {
    matrix {
        { 1, I, I },
        { 0, 0, I },
        { 0, 0, 0 },
    },
    matrix {
        { 0, I, I },
        { 0, 1, I },
        { 0, 0, 0 },
    },
    matrix {
        { 0, I, I },
        { 0, 0, I },
        { 0, 0, 1 },
    }
};
 
constexpr matrix op(matrix L, matrix R) {
    return R * L;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::string s;
    std::cin >> n >> q >> s;
    
    std::vector<matrix> init(n);
    for (int i = 0; i < n; ++i) {
        init[i] = T[s[i] - 'a'];
    }
    atcoder::segtree<matrix, op, matrix::e1> seg(init);
 
    while (q --> 0) {
        int i;
        char c;
        std::cin >> i >> c;
        seg.set(i - 1, T[c - 'a']);
        std::cout << seg.all_prod()[2][0] << '\n';
    }
    return 0;
}