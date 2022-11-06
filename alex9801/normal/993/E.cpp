#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>
#include <complex>

using namespace std;

using lint = long long;

namespace fft {
    typedef complex<double> base;
    void fft(vector<base> &a, bool inv) {
        int n = a.size(), j = 0;
        vector<base> roots(n / 2);
        for(int i = 1; i<n; i++) {
            int bit = (n >> 1);
            while(j >= bit) {
                j -= bit;
                bit >>= 1;
            }
            j += bit;
            if(i < j) swap(a[i], a[j]);
        }
        double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
        for(int i = 0; i<n / 2; i++) {
            roots[i] = base(cos(ang * i), sin(ang * i));
        }
        /* In NTT, let prr = primitive root. Then,
        int ang = ipow(prr, (mod - 1) / n);
        if(inv) ang = ipow(ang, mod - 2);
        for(int i=0; i<n/2; i++){
        roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
        }
        Others are same. If there is /= n, do *= ipow(n, mod - 2).
        In XOR convolution, roots[*] = 1.
        */
        for(int i = 2; i <= n; i <<= 1) {
            int step = n / i;
            for(int j = 0; j<n; j += i) {
                for(int k = 0; k<i / 2; k++) {
                    base u = a[j + k], v = a[j + k + i / 2] * roots[step * k];
                    a[j + k] = u + v;
                    a[j + k + i / 2] = u - v;
                }
            }
        }
        if(inv) for(int i = 0; i<n; i++) a[i] /= n;
    }

    vector<lint> multiply(vector<lint> &v, vector<lint> &w) {
        vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
        int n = 2; while(n < v.size() + w.size()) n <<= 1;
        fv.resize(n); fw.resize(n);
        fft(fv, 0); fft(fw, 0);
        for(int i = 0; i<n; i++) fv[i] *= fw[i];
        fft(fv, 1);
        vector<lint> ret(n);
        for(int i = 0; i<n; i++) ret[i] = (lint)round(fv[i].real());
        return ret;
    }
    vector<lint> multiply(vector<lint> &v, vector<lint> &w, lint mod) {
        int n = 2; while(n < v.size() + w.size()) n <<= 1;
        vector<base> v1(n), v2(n), r1(n), r2(n);
        for(int i = 0; i<v.size(); i++) {
            v1[i] = base(v[i] >> 15, v[i] & 32767);
        }
        for(int i = 0; i<w.size(); i++) {
            v2[i] = base(w[i] >> 15, w[i] & 32767);
        }
        fft(v1, 0);
        fft(v2, 0);
        for(int i = 0; i<n; i++) {
            int j = (i ? (n - i) : i);
            base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
            base ans2 = (v1[i] - conj(v1[j])) * base(0, -0.5);
            base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
            base ans4 = (v2[i] - conj(v2[j])) * base(0, -0.5);
            r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
            r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
        }
        fft(r1, 1);
        fft(r2, 1);
        vector<lint> ret(n);
        for(int i = 0; i<n; i++) {
            lint av = (lint)round(r1[i].real());
            lint bv = (lint)round(r1[i].imag()) + (lint)round(r2[i].real());
            lint cv = (lint)round(r2[i].imag());
            av %= mod, bv %= mod, cv %= mod;
            ret[i] = (av << 30) + (bv << 15) + cv;
            ret[i] %= mod;
            ret[i] += mod;
            ret[i] %= mod;
        }
        return ret;
    }
}

bool arr[200010];
long long res[200010];
int n;

void f(int s, int g)
{
    if(s == g)
    {
        res[arr[s]]++;
        return;
    }

    int x = (s + g) / 2, i;

    vector<lint> v, w;
    int c = 0;
    for(i = x + 1; i <= g; i++)
    {
        if(arr[i])
        {
            w.push_back(c);
            c = 1;
        }
        else
            c++;
    }
    w.push_back(c);

    c = 0;
    for(i = x; i >= s; i--)
    {
        if(arr[i])
        {
            v.push_back(c);
            c = 1;
        }
        else
            c++;
    }
    v.push_back(c);

    vector<lint> r = fft::multiply(v, w);

    int t = min((int)r.size(), n + 1);
    for(i = 0; i < t; i++)
        res[i] += r[i];

    f(s, x);
    f(x + 1, g);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int x, i;
    scanf("%d%d", &n, &x);
    for(i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        arr[i] = t < x;
    }

    f(0, n - 1);
    for(i = 0; i <= n; i++)
        printf("%lld ", res[i]);
    return 0;
}