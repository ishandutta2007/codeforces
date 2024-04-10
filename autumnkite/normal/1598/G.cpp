#include <bits/stdc++.h>

template<unsigned id>
class dynamic_modint {
    using mint = dynamic_modint<id>;

protected:
    static unsigned P;

    unsigned v;

public:
    dynamic_modint() : v() {}

    template<typename T, 
             typename std::enable_if<
                      std::is_signed<T>::value
                      && std::is_integral<T>::value,
                      bool>::type = true>
    dynamic_modint(T _v) {
        long long tmp = _v % static_cast<long long>(P);
        if (tmp < 0) {
            tmp += P;
        }
        v = tmp;
    }

    template<typename T, 
             typename std::enable_if<
                      std::is_unsigned<T>::value
                      && std::is_integral<T>::value,
                      bool>::type = true>
    dynamic_modint(T _v) {
        v = _v % P;
    }

    unsigned val() const {
        return v;
    }

    static unsigned mod() {
        return P;
    }

    static void set_mod(unsigned nP) {
        P = nP;
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
        mint res;
        res.v = v == 0 ? 0 : P - v;
        return res;
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

template<unsigned id>
unsigned dynamic_modint<id>::P;

std::random_device real_rand;

std::mt19937 rnd(std::chrono::system_clock::
                 now().time_since_epoch().count() ^ real_rand());

bool check_prime(unsigned x) {
    if (x < 2) {
        return false;
    }
    for (unsigned i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

unsigned gen_prime(unsigned L = std::numeric_limits<unsigned>::min(), 
                   unsigned R = std::numeric_limits<unsigned>::max()) {
    unsigned x;
    do {
        x = std::uniform_int_distribution<unsigned>(L)(rnd);
    } while (!check_prime(x));
    return x;
}

template<typename T>
class string_hash {
public:
    typedef std::size_t size_type;

protected:
    const T base;
    const char c;

    std::vector<T> power;
    std::vector<T> hash;

public:
    string_hash(const T &_base, const std::string &s, char _c = 0)
    : base(_base), c(_c), power(s.size() + 1), hash(s.size() + 1) {
        power[0] = 1;
        for (size_type i = 0; i < s.size(); ++i) {
            power[i + 1] = power[i] * base;
        }
        hash[0] = 0;
        for (size_type i = 0; i < s.size(); ++i) {
            hash[i + 1] = hash[i] * base + T(s[i] - c);
        }
    }

    T substr(size_type l, size_type r) const {
        return hash[r] - hash[l] * power[r - l];
    }

    T get_hash(const std::string &s) {
        T res = 0;
        for (char x : s) {
            res = res * base + T(x - c);
        }
        return res;
    }
};

using mint0 = dynamic_modint<0>;
using mint1 = dynamic_modint<1>;

std::vector<int> z_fun(const std::string &s) {
    int n = s.size();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        z[i] = std::min(z[i - l], std::max(r - i, 0));
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }
    return z;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    std::string x;
    std::cin >> x;

    int n = s.size(), m = x.size();

    mint0::set_mod(gen_prime(5e8));
    mint1::set_mod(gen_prime(1e9));

    string_hash<mint0> S0(10, s, '0');
    string_hash<mint1> S1(10, s, '0');

    auto xh0 = S0.get_hash(x);
    auto xh1 = S1.get_hash(x);

    auto z = z_fun(x + '#' + s);
    z.erase(z.begin(), z.begin() + m + 1);

    auto check = [&](int x, int y, int z) {
        if (0 <= x && x < y && y < z && z <= n
            && S0.substr(x, y) + S0.substr(y, z) == xh0
            && S1.substr(x, y) + S1.substr(y, z) == xh1) {
            std::cout << x + 1 << " " << y << "\n";
            std::cout << y + 1 << " " << z << "\n";
            exit(0);
        }
    };

    for (int i = 0; i < n; ++i) {
        int len = m - z[i];
        check(i - len, i, i + m);
        check(i - len + 1, i, i + m);
        check(i, i + m, i + m + len);
        check(i, i + m, i + m + len - 1);
        check(i - m + 1, i, i + m - 1);
    }
}