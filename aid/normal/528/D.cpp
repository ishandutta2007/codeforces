#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Complex {
    double re, im;

    Complex(): re(0), im(0) {}
    
    Complex(double re, double im): re(re), im(im) {}

    Complex(double re): re(re), im(0) {}

    Complex conjugate() const {
        return Complex(re, -im);
    }

    Complex mod() const{
        return re * re + im * im;
    }
    
    Complex operator+(const Complex &z) const {
        return Complex(re + z.re, im + z.im);
    }

    Complex operator-(const Complex &z) const {
        return Complex(re - z.re, im - z.im);
    }

    Complex operator*(const Complex &z) const {
        return Complex(re * z.re - im * z.im, re * z.im + im * z.re);
    }

    Complex operator/(double x) const {
        return Complex(re / x, im / x);
    }

    Complex operator/(const Complex &z) const {
        return *this * z.conjugate() / z.mod();
    }
};

const int MAXN = 200 * 1000, SIGMA = 4, INF = 1000 * 1000 * 1000 + 5;
Complex wp[8 * MAXN];
int a[SIGMA][MAXN], b[SIGMA][MAXN], ans[SIGMA][MAXN],
    lp[MAXN], rp[MAXN], cnt[SIGMA];

int f(char c) {
    return (c == 'A'? 0 : (c == 'T'? 1 : (c == 'G'? 2 : 3)));
}

void fft(vector<Complex> &a, bool inv) {
    int n = a.size();
    for(int i = 1, j = 0; i < n; i++) {
        int p = n >> 1;
        for(; j & p; p >>= 1)
            j ^= p;
        j ^= p;
        if(i < j)
            swap(a[i], a[j]);
    }
    for(int k = 1; k < n; k <<= 1) {
        for(int i = 0; i < k; i++)
            wp[i] = Complex(cos(M_PI * i / k), sin(M_PI * i / k));
        if(inv)
            for(int i = 0; i < k; i++)
                wp[i] = wp[i].conjugate();
        for(int i = 0; i < n; i += 2 * k)
            for(int j = 0; j < k; j++) {
                Complex v = a[i + j], u = wp[j] * a[i + j + k];
                a[i + j] = v + u;
                a[i + j + k] = v - u;
            }
    }
    if(inv)
        for(int i = 0; i < n; i++)
            a[i] = a[i] / n;
}

void getAns(int c, int n) {
    vector<Complex> fa(2 * n), fb(2 * n);
    for(int i = 0; i < n; i++)
        fa[i] = Complex(a[c][n - i - 1]);
    for(int i = 0; i < 2 * n; i++)
        fb[i] = Complex(b[c][i % n]);
    int nn = 1;
    while(nn < (int)fa.size())
        nn <<= 1;
    nn <<= 1;
    fa.resize(nn);
    fb.resize(nn);
    fft(fa, false);
    fft(fb, false);
    for(int i = 0; i < nn; i++)
        fa[i] = fa[i] * fb[i];
    fft(fa, true);
    for(int i = 0; i < n; i++)
        ans[c][i] = ((int)(fa[n - 1 + i].re + 0.5) == cnt[c]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    string s, t;
    cin >> n >> m >> k >> s >> t;
    for(int i = 0; i < m; i++) {
        cnt[f(t[i])]++;
        a[f(t[i])][i]++;
    }
    for(int i = 0; i < SIGMA; i++) {
        lp[0] = (f(s[0]) == i? 0 : -INF);
        for(int j = 1; j < n; j++)
            lp[j] = (f(s[j]) == i? j : lp[j - 1]);
        rp[n - 1] = (f(s[n - 1]) == i? n - 1 : INF);
        for(int j = n - 2; j >= 0; j--)
            rp[j] = (f(s[j]) == i? j : rp[j + 1]);
        for(int j = 0; j < n; j++)
            if(j - lp[j] <= k || rp[j] - j <= k)
                b[i][j]++;
    }
    for(int i = 0; i < SIGMA; i++)
        getAns(i, n);
    int anscnt = 0;
    for(int i = 0; i < n - m + 1; i++) {
        bool ok = true;
        for(int j = 0; j < SIGMA; j++)
            if(!ans[j][i])
                ok = false;
        anscnt += ok;
    }
    cout << anscnt << '\n';
    return 0;
}