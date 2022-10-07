#include <bits/stdc++.h>

template<unsigned P>
class modint {
    static_assert(1 <= P);

    using mint = modint<P>;

protected:
    unsigned v;

public:
    modint() : v() {}

    template<typename T, typename std::enable_if<std::__and_<
      std::is_signed<T>, std::is_integral<T>>::value, bool>::type = true>
    modint(T _v) {
        long long tmp = _v % static_cast<long long>(P);
        if (tmp < 0) {
            tmp += P;
        }
        v = tmp;
    }

    template<typename T, typename std::enable_if<std::__and_<
      std::is_unsigned<T>, std::is_integral<T>>::value, bool>::type = true>
    modint(T _v) {
        v = _v % P;
    }

    unsigned val() const {
        return v;
    }

    static constexpr unsigned mod() {
        return P;
    }

    mint &operator+=(const mint &rhs) {
        v < P - rhs.v ? v += rhs.v : v -= P - rhs.v;
        return *this;
    }

    mint &operator++() {
        v + 1 < P ? ++v : v = 0;
        return *this;
    }

    mint operator++(int) {
        mint tmp = *this;
        v + 1 < P ? ++v : v = 0;
        return tmp;
    }

    mint &operator-=(const mint &rhs) {
        v < rhs.v ? v += P - rhs.v : v -= rhs.v;
        return *this;
    }

    mint &operator--() {
        v == 0 ? v = P - 1 : --v;
        return *this;
    }

    mint operator--(int) {
        mint tmp = *this;
        v == 0 ? v = P - 1 : --v;
        return tmp;
    }

    mint operator-() const {
        return mint(0) -= *this;
    }

    mint &operator*=(const mint &rhs) {
        v = static_cast<unsigned long long>(v) * rhs.v % P;
        return *this;
    }

    mint pow(unsigned long long b) const {
        mint a(*this), s(1);
        for (; b; b >>= 1) {
            if (b & 1) {
                s *= a;
            }
            a *= a;
        }
        return s;
    }

    mint inv() const {
        return pow(P - 2);
    }

    friend mint operator+(const mint &lhs, const mint &rhs) {
        return mint(lhs) += rhs;
    }

    friend mint operator-(const mint &lhs, const mint &rhs) {
        return mint(lhs) -= rhs;
    }

    friend mint operator*(const mint &lhs, const mint &rhs) {
        return mint(lhs) *= rhs;
    }

    friend bool operator==(const mint &lhs, const mint &rhs) {
        return lhs.v == rhs.v;
    }

    friend bool operator!=(const mint &lhs, const mint &rhs) {
        return lhs.v != rhs.v;
    }

    friend std::istream &operator>>(std::istream &in, mint &x) {
        return in >> x.v;
    }

    friend std::ostream &operator<<(std::ostream &out, const mint &x) {
        return out << x.v;
    }
};

template<typename T>
T get_e(T a, T b) {
    if (a < b) {
        std::swap(a, b);
    }
    if (b == 1) {
        return a;
    }
    if (a % b != 0) {
        return -1;
    }
    return get_e(a / b, b);
};

template<typename T>
T exgcd(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    T g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

std::ostream &operator<<(std::ostream &out, __int128_t x) {
    if (x == 0) {
        out << '0';
        return out;
    }
    if (x < 0) {
        out << '-';
        x = -x;
    }
    std::string a;
    while (x) {
        a += x % 10 + '0';
        x /= 10;
    }
    std::reverse(a.begin(), a.end());
    out << a;
    return out;
}

template<typename T>
std::tuple<T, T, bool> excrt(std::vector<T> a, std::vector<T> p) {
    typedef typename std::vector<T>::size_type size_type;
    size_type n = a.size();
    for (size_type i = 0; i < n; ++i) {
        a[i] %= p[i];
    }
    T prod = p[0], now = a[0];
    for (size_type i = 1; i < n; ++i) {
        T x, y;
        T c = (a[i] - now) % p[i];
        auto g = exgcd(prod, p[i], x, y);
        if (c % g != 0) {
            return std::tuple<T, T, bool>(0, 0, false);
        }
        x *= c / g, y *= c / g;
        now += prod * x;
        prod *= p[i] / g;
        now %= prod;
        if (now < 0) {
            now += prod;
        }
        bool ok = true;
        for (size_type j = 0; j <= i; ++j) {
            ok &= now % p[j] == a[j];
        }
    }
    return std::tuple<T, T, bool>(now, prod, true);
}

using mint = modint<1000000007>;
using bint = __int128_t;

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n), b(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];
    }

    bool flag = true;
    for (int i = 0; i < n; ++i) {
        flag &= b[i] > 1;
    }
    int id = -1;
    long long e = 1;
    for (int i = 0; i < n; ++i) {
        e = get_e(e, b[i]);
        if (e == -1) {
            id = i;
            break;
        }
    }

    if (id == -1 && flag) {
        std::vector<bint> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            A[i] = B[i] = 0;
            while (b[i] > 1) {
                ++B[i];
                b[i] /= e;
            }
            while (a[i] % e == 0) {
                ++A[i];
                a[i] /= e;
            }
            if (a[i] != a[0]) {
                std::cout << -1 << "\n";
                return 0;
            }
        }
        auto [x, M, va] = excrt(A, B);
        if (!va) {
            std::cout << -1 << "\n";
            return 0;
        }
        bint mx = *std::max_element(A.begin(), A.end());
        if (x < mx) {
            x += (mx - x + M - 1) / M * M;
        }
        std::cout << mint(a[0]) * mint(e).pow(x % (mint::mod() - 1)) << "\n";
    } else {
        auto check = [&](int p, int w, mint tx, int i) {
            long long t = (log(1.0 * a[p] / a[i]) + w * log(b[p])) / log(b[i]);
            t = std::max(t - 2, 0ll);
            for (int d = 0; d < 5; ++d) {
                if (mint(a[i]) * mint(b[i]).pow(t + d) == tx) {
                    return true;
                }
            }
            return false;
        };

        int pos = -1, w = 0;
        mint t;
        if (flag) {
            pos = id;
            t = a[pos];
            while (1) {
                if (check(pos, w, t, 0)) {
                    break;
                }
                ++w;
                t *= b[id];
                if (w > 3600) {
                    std::cout << -1 << "\n";
                    return 0;
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (b[i] == 1) {
                    if (pos == -1) {
                        pos = i;
                        t = a[pos];
                    } else {
                        if (a[pos] != a[i]) {
                            std::cout << -1 << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!check(pos, w, t, i)) {
                std::cout << -1 << "\n";
                return 0;
            }
        }
        std::cout << t << "\n";
    }
}