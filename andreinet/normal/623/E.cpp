#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

#define double long double
namespace FastFourierTransform {
    const double PI = acos(-1L);

    struct Complex {
        double real, imag;
        Complex(const double _real = 0, const double _imag = 0):
            real(_real), imag(_imag) {}
        Complex operator*(const Complex& other) const {
            return Complex(real * other.real - imag * other.imag,
                           real * other.imag + imag * other.real);
        }
        void operator*=(const Complex& other) {
            double aux = real * other.real - imag * other.imag;
            imag = real * other.imag + imag * other.real;
            real = aux;
        }
        Complex operator+(const Complex& other) const {
            return Complex(real + other.real, imag + other.imag);
        }
        void operator+=(const Complex& other) {
            real += other.real;
            imag += other.imag;
        }
        Complex operator-(const Complex& other) const {
            return Complex(real - other.real, imag - other.imag);
        }
        void operator-=(const Complex& other) {
            real -= other.real;
            imag -= other.imag;
        }
        void operator/=(const double other) {
            real /= other;
            imag /= other;
        }
    };

    int bit_inv(int n, int k) {
        int res = 0;
        for (int i = 0; i < k; ++ i)
            if (n & (1 << i))
                res |= (1 << (k - i - 1));

        return res;
    }

    void fft(vector<Complex>& a, bool invert) {
        int n = a.size();
        int k = 0;
        while ((1 << (k + 1)) <= n) k++;
        for (int i = 1, j = 0; i < n; ++i) {
            //int bit = n >> 1;
            //for (; j >= bit; bit >>= 1) {
            //    j -= bit;
            //}
            //j += bit;
            j = bit_inv(i, k);
            if (i < j) {
                swap(a[i], a[j]);
            }
        }
        for (int len = 2; len <= n; len <<= 1) {
            int halfLen = len >> 1;
            double angle = 2 * PI / len * (invert ? -1: 1);
            Complex wl(cos(angle), sin(angle));
            for (int i = 0; i < n; i += len) {
                Complex w(1);
                for (int j = 0; j < halfLen; ++j) {
                    Complex u = a[i + j], v = w * a[i + j + halfLen];
                    a[i + j] = u + v;
                    a[i + j + halfLen] = u - v;
                    w *= wl;
                }
            }
        }
        if (invert) {
            for (int i = 0; i < n; ++i) {
                a[i] /= n;
            }
        }
    }

    vector<int64_t> multiply(const vector<int64_t>& a, const vector<int64_t>& b) {
        int n1 = a.size(), n2 = b.size();
        int m = 1;
        while (m < n1 || m < n2) m <<= 1;
        m <<= 1;

        vector<Complex> fa(m, 0), fb(m, 0);
        for (int i = 0; i < n1; ++i) {
            fa[i] = a[i];
        }
        for (int i = 0; i < n2; ++i) {
            fb[i] = b[i];
        }
        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < m; ++i) {
            fa[i] *= fb[i];
        }
        fft(fa, true);
        vector<int64_t> res(m);
        for (int i = 0; i < m; ++i) {
            res[i] = (int64_t) (fa[i].real + 0.5);
        }
        return res;
    }

    vector<int64_t> modMultiply(const vector<int64_t>& a,
                                const vector<int64_t>& b,
                                const int MOD) {
        int n = SZ(a);
        int SQ = sqrt(MOD);
        vector<int64_t> s1(n), s2(n), s3(n), s4(n);
        for (int i = 0; i < n; ++i) {
            s1[i] = a[i] % SQ;
            s2[i] = a[i] / SQ;
            s3[i] = b[i] % SQ;
            s4[i] = b[i] / SQ;
        }
        vector<int64_t> r1 = multiply(s1, s3);
        vector<int64_t> r2 = multiply(s1, s4);
        vector<int64_t> r3 = multiply(s2, s3);
        vector<int64_t> r4 = multiply(s2, s4);
        r1.resize(n);
        for (int i = 0; i < n; ++i) {
            r1[i] += (r2[i] + r3[i]) % MOD * SQ % MOD;
            r1[i] += r4[i] % MOD * SQ % MOD * SQ % MOD;
            r1[i] %= MOD;
        }
        return r1;

    }
}
#undef double

namespace Normal {
    const int MAXSIZE = 120005;
    int64_t c[MAXSIZE];
    void multiply(int64_t a[], int64_t b[], int n) {
        memset(c, 0, sizeof c);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                c[i] += a[j] * b[i - j];
            }
        }
        for (int i = 0; i <= n; ++i)
            a[i] = c[i];
    }
}

typedef long long i64;
const int KMAX = 120005, MOD = 1e9 + 7;

vector<int64_t> dp1, dp2;
vector<int64_t> dpAdd;

int fact[KMAX], invFact[KMAX];

int Pow(int x, int y) {
    int ret = 1;
    for (; y > 0; y >>= 1) {
        if (y & 1) ret = (int64_t) ret * x % MOD;
        x = (int64_t) x * x % MOD;
    }
    return ret;
}

int invmod(int x) {
    return Pow(x, MOD - 2);
}

void solve(int n, int k) {
    if (n == 1) {
        dp1.resize(k + 1, 1);
        dp1[0] = 0;
    } else if (n % 2 == 1) {
        solve(n - 1, k);
        int pw2 = 1;
        for (int i = 0; i <= k; ++i) {
            dp1[i] *= invFact[i];
            dp1[i] %= MOD;
            dp1[i] *= pw2;
            dp1[i] %= MOD;
            if (dp1[i] < 0) dp1[i] += MOD;

            pw2 = pw2 * 2 % MOD;
        }
        dp1 = FastFourierTransform::modMultiply(dp1, dpAdd, MOD);
        for (int i = 0; i <= k; ++i) {
            dp1[i] %= MOD;
            dp1[i] *= fact[i];
            dp1[i] %= MOD;
        }
    } else {
        solve(n / 2, k);
        dp2 = dp1;
        int pw2 = 1, ml = Pow(2, n / 2);
        for (int i = 0; i <= k; ++i) {
            dp1[i] *= invFact[i];
            dp1[i] %= MOD;
            dp1[i] *= pw2;
            dp1[i] %= MOD;
            if (dp1[i] < 0) dp1[i] += MOD;

            pw2 = (int64_t) pw2 * ml % MOD;
        }
        for (int i = 0; i <= k; ++i) {
            dp2[i] *= invFact[i];
            dp2[i] %= MOD;
            if (dp2[i] < 0) dp1[i] += MOD;
        }
        dp1 = FastFourierTransform::modMultiply(dp1, dp2, MOD);
        for (int i = 0; i <= k; ++i) {
            dp1[i] %= MOD;
            dp1[i] *= fact[i];
            dp1[i] %= MOD;
        }
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int64_t n;
    int k;
    cin >> n >> k;

    if (n > k) {
        cout << "0\n";
        return 0;
    }

    fact[0] = 1;
    for (int i = 1; i <= k; ++i) {
        fact[i] = (int64_t) fact[i - 1] * i % MOD;
    }
    invFact[k] = invmod(fact[k]);
    for (int i = k - 1; i >= 0; --i) {
        invFact[i] = (int64_t) invFact[i + 1] * (i + 1) % MOD;
    }

    dpAdd.resize(k + 1, 0);
    for (int i = 1; i <= k; ++i) {
        dpAdd[i] = invFact[i];
    }
    solve(n, k);

    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        int64_t add = dp1[i] * fact[k] % MOD;
        add = add * invFact[i] % MOD;
        add = add * invFact[k - i] % MOD;
        ans = (ans + add) % MOD;
    }
    if (ans < 0) ans += MOD;

    cout << ans << '\n';
}