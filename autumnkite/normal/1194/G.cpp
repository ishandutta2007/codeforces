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

using mint = modint<998244353>;

struct state {
    bool op;
    int d;
    int S;

    state() : op(0), d(0), S(0) {}

    state(bool _op, int _d, int _S) : op(_op), d(_d), S(_S) {}

    state(int val) : op(val % 2), d(val / 2 % 9), S(val / 2 / 9) {}

    operator int() const {
        return S * 9 * 2 + d * 2 + op;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string a;
    std::cin >> a;
    mint tmp = 0;
    for (char c : a) {
        tmp = tmp * 10 + (c - '0');
    }
    std::reverse(a.begin(), a.end());
    int n = a.size();

    mint ans = 0;
    for (int x = 1; x <= 9; ++x) {
        for (int y = x + 1; y <= 9; ++y) {
            if (std::__gcd(x, y) == 1) {
                int c = std::min(9 / x, 9 / y), tot = (1 << c) * 9 * 2;
                std::vector<std::vector<mint>> f(tot, std::vector<mint>(tot));
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        f[i][j] = 1;
                    }
                }
                for (int k = 0; k < n; ++k) {
                    auto trans = [&](state &s, int x, int v) {
                        int tmp = v * x + s.d;
                        int now = tmp % 10, nd = tmp / 10;
                        s.d = nd;
                        if (now > 0 && now % x == 0 && now / x <= c) {
                            s.S |= 1 << (now / x - 1);
                        }
                        if (s.op == 1) {
                            return now == a[k] - '0' ? 2 : 0;
                        } else {
                            return now < a[k] - '0' ? 3 : 1;
                        }
                    };
                    std::vector<std::vector<mint>> g(tot, std::vector<mint>(tot));
                    for (int i = 0; i < tot; ++i) {
                        for (int j = 0; j < tot; ++j) {
                            if (f[i][j] != 0) {
                                for (int v = 0; v <= 9; ++v) {
                                    state sx(i), sy(j);
                                    int tx = trans(sx, x, v), ty = trans(sy, y, v);
                                    for (int ox = 0; ox < 2; ++ox) {
                                        if (tx >> ox & 1) {
                                            for (int oy = 0; oy < 2; ++oy) {
                                                if (ty >> oy & 1) {
                                                    sx.op = ox, sy.op = oy;
                                                    g[sx][sy] += f[i][j];
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    f.swap(g);
                }
                for (int i = 0; i < tot; ++i) {
                    for (int j = 0; j < tot; ++j) {
                        if (f[i][j] != 0) {
                            state sx(i), sy(j);
                            if (sx.op && sy.op && !sx.d && !sy.d && sx.S & sy.S) {
                                ans += f[i][j];
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << ans * 2 + tmp << "\n";
}