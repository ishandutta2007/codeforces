#include <iostream>
#include <algorithm>
#include <vector>

#define lint long long int
#define double long double
using namespace std;

class c_double {
public:
    double real;
    double imag;

    c_double(double r = 0, double i = 0): real(r), imag(i) {}

    c_double operator+(const c_double &b) const {
        return c_double(real + b.real, imag + b.imag);
    }

    c_double operator-(const c_double &b) const {
        return c_double(real - b.real, imag - b.imag);
    }

    c_double operator*(const c_double &b) const {
        return c_double(real * b.real - imag * b.imag, real * b.imag + b.real * imag);
    }

    c_double operator*=(const c_double &b) {
        (*this) = (*this) * b;
    }

    c_double operator/=(const int &b) {
        (*this).real /= b;
        (*this).imag /= b;
    }
};

const int mod = 1000000007;
const int sqrt_mod = 31623;
const double TAU = 2 * acos(-1.0l);

int binv[67000];
bool computed;

int bit_inv(int n, int k) {
    for (int i = 0; i < k; ++ i)
        if (n & (1 << i))
            binv[n] |= (1 << (k - i - 1));
    return binv[n];
}

void fft(int n, int k, vector <c_double> &v, bool inv = false) {
    if (n == 1)
        return ;

    for (int i = 0; i < n; ++ i)
        if (i < binv[i])
            swap(v[i], v[binv[i]]);

    c_double wk;
    c_double w;

    c_double a, b;

    int i, j;
    for (int step = 2; step <= n; step *= 2) {
        w = {cos(TAU / step), (1 - 2 * inv) * sin(TAU / step)};

        for (i = 0; i < n; i += step) {
            wk = 1;

            for (j = 0; j < step / 2; ++ j) {
                a = v[i + j];
                b = wk * v[i + j + step / 2];

                v[i + j] = a + b;
                v[i + j + step / 2] = a - b;

                wk *= w;
            }
        }
    }

    if (inv)
        for (i = 0; i < n; ++ i)
            v[i] /= n;
}

void product(vector <int> &ans, int val, const vector <int> &a, const vector <int> &b) {
    int n = 1, k = 0;
    while (n < 2 * a.size() || n < 2 * b.size())
        n <<= 1, ++ k;

    if (!computed) {
        for (int i = 0; i < n; ++ i)
            bit_inv(i, k);
        computed = true;
    }

    vector <c_double> ca(n);
    vector <c_double> cb(n);

    for (int i = 0; i < a.size(); ++ i)
        ca[i] = a[i];
    for (int i = 0; i < b.size(); ++ i)
        cb[i] = b[i];

    fft(n, k, ca);
    fft(n, k, cb);

    vector <c_double> cans(n);
    for (int i = 0; i < n; ++ i)
        cans[i] = ca[i] * cb[i];

    fft(n, k, cans, true);

    if (!ans.size())
        ans.resize(n);

    for (int i = 0; i < n; ++ i)
        ans[i] = (ans[i] + 1ll * val * (lint)(floor(cans[i].real + 0.5))) % mod;
}

void convolution(vector <int> &ans, const vector <int> &a, const vector <int> &b) {
    vector <int> a0(a.size());
    vector <int> a1(a.size());

    vector <int> b0(b.size());
    vector <int> b1(b.size());

    for (int i = 0; i < a.size(); ++ i)
        a1[i] = a[i] / sqrt_mod;
    for (int i = 0; i < a.size(); ++ i)
        a0[i] = a[i] % sqrt_mod;

    for (int i = 0; i < a.size(); ++ i)
        b1[i] = b[i] / sqrt_mod;
    for (int i = 0; i < a.size(); ++ i)
        b0[i] = b[i] % sqrt_mod;

    product(ans, 1, a0, b0);
    product(ans, sqrt_mod, a1, b0);
    product(ans, sqrt_mod, a0, b1);
    product(ans, (1ll * sqrt_mod * sqrt_mod) % mod, a1, b1);
}

const int NMAX = 30005;
int put2[NMAX];

int inv[NMAX];
int fact[NMAX];
int inv_fact[NMAX];

void precalcs() {
    put2[0] = 1;
    for (int i = 1; i < NMAX; ++ i) {
        put2[i] = 2 * put2[i - 1];
        if (put2[i] >= mod)
            put2[i] -= mod;
    }

    fact[0] = inv_fact[0] = 1;
    inv[1] = fact[1] = inv_fact[1] = 1;
    for (int i = 2; i < NMAX; ++ i) {
        inv[i] = mod - (1ll * (mod / i) * inv[mod % i]) % mod;
        fact[i] = (1ll * i * fact[i - 1]) % mod;
        inv_fact[i] = (1ll * inv[i] * inv_fact[i - 1]) % mod;
    }
}

int comb(int n, int k) {
    return ((1ll * fact[n] * inv_fact[n - k]) % mod * inv_fact[k]) % mod;
}

void unite(vector <int> &ans, vector <int> a, vector <int> b, int nb) {
    int val = 1;
    for (int i = 0; i < a.size(); ++ i) {
        a[i] = (1ll * a[i] * inv_fact[i]) % mod;
        a[i] = (1ll * a[i] * val) % mod;

        val = (1ll * val * put2[nb]) % mod;
    }

    for (int i = 0; i < b.size(); ++ i)
        b[i] = (1ll * b[i] * inv_fact[i]) % mod;


    ans.clear();
    convolution(ans, a, b);

    for (int i = 0; i < ans.size(); ++ i)
        ans[i] = (1ll * ans[i] * fact[i]) % mod;
    ans.resize(a.size());
}

vector <int> put[15];

int main()
{
    precalcs();

    lint n;
    int k;

    cin >> n >> k;

    if (n > k) {
        cout << "0\n";
        return 0;
    }

    put[0].resize(k + 1);
    for (int i = 1; i <= k; ++ i)
        put[0][i] = 1;

    for (int i = 1; i < 15; ++ i)
        unite(put[i], put[i - 1], put[i - 1], (1 << (i - 1)));

    vector <int> ans(k + 1);
    ans[0] = 1;

    for (int i = 0; i < 15; ++ i)
        if (n & (1 << i))
            unite(ans, ans, put[i], (1 << i));

    int res = 0;
    for (int i = 1; i <= k; ++ i)
        res = (res + 1ll * ans[i] * comb(k, i)) % mod;

    cout << res << '\n';
    return 0;
}