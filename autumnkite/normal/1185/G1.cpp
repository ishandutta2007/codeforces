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

using mint = modint<1000000007>;

const int M = 3;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, T;
    std::cin >> n >> T;
    std::vector<std::vector<int>> a(M);
    for (int i = 0; i < n; ++i) {
        int t, b;
        std::cin >> t >> b;
        --b;
        a[b].push_back(t);
    }

    std::vector<int> cnt(M);
    for (int i = 0; i < M; ++i) {
        cnt[i] = a[i].size();
    }

    auto solve = [](const std::vector<std::vector<int>> &a, int &lim) {
        int m = a.size();
        std::vector<int> prod(m + 1);
        prod[0] = 1;
        for (int i = 0; i < m; ++i) {
            prod[i + 1] = prod[i] * (a[i].size() + 1);
        }
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += std::accumulate(a[i].begin(), a[i].end(), 0);
        }
        lim = std::min(lim, sum);
        std::vector<std::vector<mint>> f(prod[m], std::vector<mint>(lim + 1));
        f[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int x : a[i]) {
                for (int S = prod[m]; S >= 0; --S) {
                    if (S / prod[i] % (a[i].size() + 1)) {
                        int T = S - prod[i];
                        for (int w = lim; w >= x; --w) {
                            f[S][w] += f[T][w - x];
                        }
                    }
                }
            }
        }
        return f;
    };

    int B = M / 2;
    int flim = T;
    auto f = solve(std::vector<std::vector<int>>(
                    a.begin(), a.begin() + B), flim);
    int glim = T;
    auto g = solve(std::vector<std::vector<int>>(
                    a.begin() + B, a.end()), glim);

    auto merge = [](const std::vector<int> &len, int B,
                    const std::vector<std::vector<mint>> &f, int flim,
                    const std::vector<std::vector<mint>> &g, int glim,
                    int T) {
        int m = len.size();
        int mf = B, mg = m - B;
        std::vector<int> pf(mf + 1), pg(mg + 1);
        pf[0] = 1;
        for (int i = 0; i < mf; ++i) {
            pf[i + 1] = pf[i] * (len[i] + 1);
        }
        pg[0] = 1;
        for (int i = 0; i < mg; ++i) {
            pg[i + 1] = pg[i] * (len[i + B] + 1);
        }

        int n = std::accumulate(len.begin(), len.end(), 0);
        std::vector<mint> fac(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * i;
        }
        std::vector<int> prod(m + 1);
        prod[0] = 1;
        for (int i = 0; i < m; ++i) {
            prod[i + 1] = prod[i] * (len[i] + 1);
        }
        std::vector<std::vector<mint>> ht(prod[m], std::vector<mint>(m));
        for (int S = 1; S < prod[m]; ++S) {
            for (int i = 0; i < m; ++i) {
                if (S / prod[i] % (len[i] + 1)) {
                    int T = S - prod[i];
                    if (T == 0) {
                        ht[S][i] = 1;
                    } else {
                        for (int j = 0; j < m; ++j) {
                            if (i != j) {
                                ht[S][i] += ht[T][j];
                            }
                        }
                    }
                }
            }
        }
        std::vector<mint> h(prod[m]);
        for (int S = 1; S < prod[m]; ++S) {
            for (int i = 0; i < m; ++i) {
                h[S] += ht[S][i];
            }
            for (int i = 0; i < m; ++i) {
                h[S] *= fac[S / prod[i] % (len[i] + 1)];
            }
        }

        mint ans = 0;
        for (int Sf = 0; Sf < pf[mf]; ++Sf) {
            for (int Sg = 0; Sg < pg[mg]; ++Sg) {
                for (int i = std::max(0, T - glim); i <= T && i <= flim; ++i) {
                    int j = T - i;
                    ans += f[Sf][i] * g[Sg][j] * h[Sg * pf[mf] + Sf];
                }
            }
        }
        return ans;
    };

    std::cout << merge(cnt, B, f, flim, g, glim, T) << "\n";
}