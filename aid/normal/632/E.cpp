#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Complex {
    double re, im;

    Complex(): re(0), im(0) {}

    Complex(double _re): re(_re), im(0) {}

    Complex(double _re, double _im): re(_re), im(_im) {}

    Complex conj() const {
        return Complex(re, -im);
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

    Complex operator/(double k) const {
        return Complex(re / k, im / k);
    }

    Complex operator/(const Complex &z) const {
        return *this * z.conj() / (z.re * z.re + z.im * z.im);
    }
};

const int MAXN = 1000 * 1000 + 5;
Complex wp[8 * MAXN];

void fft(vector<Complex> &a, bool inv) {
    int n = a.size();
    for(int i = 1, j = 0; i < n; i++) {
        int bit = (n >> 1);
        while(j & bit) {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if(i < j)
            swap(a[i], a[j]);
    }
    for(int k = 1; k < n; k <<= 1) {
        wp[0] = Complex(1);
        wp[1] = Complex(cos(M_PI / k), sin(M_PI / k));
        if(inv)
            wp[1] = wp[1].conj();
        for(int i = 2; i < k; i++)
            wp[i] = wp[i >> 1] * wp[(i + 1) >> 1];
        for(int i = 0; i < n; i += 2 * k)
            for(int j = 0; j < k; j++) {
                Complex v = a[i + j], u = a[i + j + k] * wp[j];
                a[i + j] = v + u;
                a[i + j + k] = v - u;
            }
    }
    if(inv)
        for(int i = 0; i < n; i++)
            a[i] = a[i] / n;
}

void mul(vector<int> &a, const vector<int> &b) {
    int n = (int)a.size() + (int)b.size() - 1;
    int nn = 1;
    while(nn < n)
        nn <<= 1;
    n = nn;
    vector<Complex> fa(n), fb(n);
    for(size_t i = 0; i < a.size(); i++)
        fa[i] = Complex(a[i]);
    for(size_t i = 0; i < b.size(); i++)
        fb[i] = Complex(b[i]);
    fft(fa, false);
    fft(fb, false);
    for(int i = 0; i < n; i++)
        fa[i] = fa[i] * fb[i];
    fft(fa, true);
    a.clear();
    for(int i = 0; i < n; i++) {
        int val = int(fa[i].re + 0.5);
        if(val) {
            while((int)a.size() <= i)
                a.push_back(0);
            a[i] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while((int)a.size() <= x)
            a.push_back(0);
        a[x] = 1;
    }
    vector<int> res;
    res.push_back(1);
    while(k) {
        if(k & 1)
            mul(res, a);
        k >>= 1;
        if(!k)
            break;
        vector<int> b = a;
        mul(a, b);
    }
    for(size_t i = 0; i < res.size(); i++)
        if(res[i])
            cout << i << ' ';
    cout << '\n';
    return 0;
}