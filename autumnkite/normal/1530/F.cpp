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

using mint = modint<31607>;

const mint inv10000 = mint(10000).inv();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<std::vector<mint>> a(n, std::vector<mint>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
            a[i][j] *= inv10000;
        }
    }

    std::vector<std::vector<mint>> pro(n, std::vector<mint>(1 << n));
    int all = (1 << n) - 1;
    for (int i = 0; i < n; ++i) {
        std::vector<mint> tmp(1 << n);
        tmp[0] = 1;
        for (int j = 0; j < n; ++j) {
            tmp[1 << j] = a[i][j];
        }
        for (int S = 1; S < (1 << n); ++S) {
            tmp[S] = tmp[S & (S - 1)] * tmp[S & -S];
        }
        for (int S = 0; S < (1 << n); ++S) {
            pro[i][S] = tmp[S] * (1 - tmp[all ^ S]);
        }
    }

    std::vector<int> bitcnt(1 << n);
    for (int S = 1; S < (1 << n); ++S) {
        bitcnt[S] = bitcnt[S >> 1] + (S & 1);
    }

    mint ans = 0;
    for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {
            for (int S = 0; S < (1 << n); ++S) {
                mint w = 1;
                for (int i = 0; i < n; ++i) {
                    w *= pro[i][x << i | y << (n - i - 1) | S];
                }
                if ((bitcnt[S] + x + y) & 1) {
                    ans -= w;
                } else {
                    ans += w;
                }
            }
        }
    }
    std::cout << 1 - ans << "\n";
}