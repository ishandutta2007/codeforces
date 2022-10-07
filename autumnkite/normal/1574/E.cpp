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

    static mint raw(unsigned v) {
        mint res;
        res.v = v;
        return res;
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::map<std::pair<int, int>, int> mp;

    std::vector<std::array<int, 2>> a(n), b(m);
    std::array<int, 2> c = {};

    std::array<int, 3> ca = {n}, cb = {m}, cc = {1};

    auto update = [&](std::array<int, 2> &a, std::array<int, 3> &ca, 
                      int y, int d) {
        --ca[bool(a[0]) + bool(a[1])];
        a[y] += d;
        ++ca[bool(a[0]) + bool(a[1])];
    };

    auto get_ans = [&](const std::array<int, 3> &c) -> mint {
        if (c[2]) {
            return 0;
        }
        return mint(2).pow(c[0]);
    };

    while (q--) {
        int x, y, t;
        std::cin >> x >> y >> t;
        --x, --y;
        std::pair<int, int> tmp(x, y);
        int o = mp.count(tmp) ? mp[tmp] : -1;
        if (o != -1) {
            update(a[x], ca, (y & 1) ^ o, -1);
            update(b[y], cb, (x & 1) ^ o, -1);
            update(c, cc, (x & 1) ^ (y & 1) ^ o, -1);
            mp.erase(tmp);
        }
        if (t != -1) {
            update(a[x], ca, (y & 1) ^ t, 1);
            update(b[y], cb, (x & 1) ^ t, 1);
            update(c, cc, (x & 1) ^ (y & 1) ^ t, 1);
            mp.emplace(tmp, t);
        }
        std::cout << get_ans(ca) + get_ans(cb) - get_ans(cc) << "\n";
    }
}