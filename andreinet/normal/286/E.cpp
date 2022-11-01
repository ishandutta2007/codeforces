#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

namespace FastFourierTransform {
    const double PI = acos(-1);

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

    void fft(vector<Complex>& a, bool invert) {
        int n = a.size();
        for (int i = 1, j = 0; i < n; ++i) {
            int bit = n >> 1;
            for (; j >= bit; bit >>= 1) {
                j -= bit;
            }
            j += bit;
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
}

namespace Normal {
    const int MAXSIZE = 120005;
    int64_t c[MAXSIZE];
    void multiply(int64_t a[], int64_t b[], int n) {
        memset(c, 0, sizeof c);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                c[i] += a[j] * b[i - j];
            }
        }
        for (int i = 0; i < n; ++i)
            a[i] = c[i];
    }
}

const int NMAX = 1000005;

bitset<NMAX> used;
int values[NMAX];
int fans[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int64_t> A(m + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
        A[values[i]] = 1;
        used[values[i]] = true;
    }

    for (int i = 1; i <= m; ++i) {
        if (!used[i]) continue;
        for (int j = i; j <= m; j += i) {
            if (!used[j]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    A = FastFourierTransform::multiply(A, A);
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        if (!A[i]) {
            if (used[i]) {
                fans[cnt++] = i;
            }
        } else {
            if (!used[i]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n" << cnt << '\n';
    for (int i = 0; i < cnt; ++i)
        cout << fans[i] << ' ';
}