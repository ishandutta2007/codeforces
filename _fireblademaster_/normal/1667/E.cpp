#include <bits/stdc++.h>
using namespace std;
const int D = 20, mod = 998244353, G = 3;
typedef unsigned long long ull;
typedef unsigned long long ll;

inline int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
inline int Mod(int x) {return x >= mod ? x - mod : x;}
struct mint {
    int x;
    mint() {x = 0;}
    mint(int y) {x = y;}
    inline mint inv() const { return mint{power(x, mod - 2)}; }
    explicit inline operator int() { return x; }
    friend inline mint operator + (const mint &a, const mint& b) { return mint(Mod(a.x + b.x)); }
    friend inline mint operator - (const mint &a, const mint& b) { return mint(Mod(a.x - b.x + mod)); }
    friend inline mint operator * (const mint &a, const mint& b) { return mint(1ll * a.x * b.x % mod); }
    friend inline mint operator - (const mint &a) { return mint(Mod(mod - a.x)); }
    friend inline mint& operator += (mint &a, const mint& b) { return a = a + b; }
    friend inline mint& operator -= (mint &a, const mint& b) { return a = a - b; }
    friend inline mint& operator *= (mint &a, const mint& b) { return a = a * b; }
    inline int operator == (const mint &b) { return x == b.x; }
    inline int operator != (const mint &b) { return x != b.x; }
    inline int operator < (const mint &a) { return x < a.x; }
    inline int operator <= (const mint &a) { return x <= a.x; }
    inline int operator > (const mint &a) { return x > a.x; }
    inline int operator >= (const mint &a) { return x >= a.x; }
};
inline mint power(mint a, int b) {
    mint ans = 1;
    for (; b; b >>= 1, a = a * a) if (b & 1) ans = ans * b;
    return ans;
}
inline mint msqrt(mint x) {
    if (power(x, (mod - 1) / 2) != 1) return -1;
    while (1) {
        mint cur = rand() % mod;
        if (power(cur * cur - x, (mod - 1) / 2) == 1) continue;
        pair < mint, mint > res(cur, 1), ans(1, 0);
        cur = cur * cur - x;
        auto mult = [&](const pair < mint, mint > &a, const pair < mint, mint > &b) {
            return make_pair(a.first * b.first + a.second * b.second * cur, a.second * b.first + a.first * b.second);
        };
        for (int b = (mod + 1) / 2; b; b >>= 1, res = mult(res, res)) if (b & 1) ans = mult(ans, res);
        return min(ans.first.x, mod - ans.first.x);
    }
}

mint fac[1 << D | 10], ifac[1 << D | 10], inv[1 << D | 10];
namespace Poly {
    typedef vector < mint > poly;
    vector < int > gpower[D];
    ull nttf[1 << D | 10];
    int rev[1 << D | 10];
    inline int len(const poly &x) {return x.size();}
    inline void init() {
        for (int i = 0; i < D; i++) {
            gpower[i].resize(2 << i);
            int wn = power(G, (mod - 1) >> i + 1);
            for (int j = 0, w = 1; j < 2 << i; j++, w = 1ll * w * wn % mod) gpower[i][j] = w;
        }
        inv[1] = 1;
        for (int i = 2; i <= 1 << D; i++) inv[i] = (mod - mod / i) * inv[mod % i];
        fac[0] = ifac[0] = 1;
        for (int i = 1; i <= 1 << D; i++) fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * inv[i];
    }
    inline void get_rev(int l) {
        for (int i = 1; i < 1 << l; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << l - 1);
    }
    inline void NTT(ull *a, int n, int type) {
        for (int i = 0; i < n; i++) if (rev[i] < i) swap(a[i], a[rev[i]]);
        for (ull *i = a, *end = a + n; i < end; i += 2) {
            ull tmp = *(i + 1);
            *(i + 1) = *i + mod - tmp;
            *i += tmp;
        }
        for (int p = 2, d = 1; p < n; p <<= 1, d++) {
            for (int s = 0; s < n; s += p << 1) {
                ull *l = a + s, *r = l + p, *end = r;
                for (int *w = gpower[d].data(); l < end; l += 2, r += 2) {
                    int h1 = *w++ * *r % mod;
                    *r = *l + mod - h1;
                    *l += h1;
                    int h2 = *w++ * *(r + 1) % mod;
                    *(r + 1) = *(l + 1) + mod - h2;
                    *(l + 1) += h2;
                }
            }
        }
        if (type == -1) {
            int inv = power(n, mod - 2);
            for (ull *i = a; i < a + n; i++) *i = *i * inv % mod;
            reverse(a + 1, a + n);
        }
        else for (ull *i = a; i < a + n; i++) *i %= mod;
    }
    inline void DIF(ull *a, int l) {
        for (int d = l; d --> 1; )
            for (int s = 0; s < 1 << l; s += 2 << d) {
                ull *i = a + s, *j = i + (1 << d), *_end = j;
                for (int *w = gpower[d].data(); i < _end; i += 2, j += 2, w += 2) {
                    ull tmp1 = *j;
                    *j = (*i - tmp1 + mod) * *w % mod;
                    *i = ::Mod(*i + tmp1);
                    ull tmp2 = *(j + 1);
                    *(j + 1) = (*(i + 1) - tmp2 + mod) * *(w + 1) % mod;
                    *(i + 1) = ::Mod(*(i + 1) + tmp2);
                }
            }
        for (ull *i = a, *_end = a + (1 << l); i < _end; i += 2) {
            ull tmp = *(i + 1);
            *(i + 1) = ::Mod(*i - tmp + mod);
            *i = ::Mod(*i + tmp);
        }
    }
    inline void DIT(ull *a, int l) {
        for (ull *i = a, *_end = a + (1 << l); i < _end; i += 2) {
            ull tmp = *(i + 1);
            *(i + 1) = *i - tmp + mod;
            *i = *i + tmp;
        }
        for (int d = 1; d < l; d++)
            for (int s = 0; s < 1 << l; s += 2 << d) {
                ull *i = a + s, *j = i + (1 << d), *_end = j;
                for (int *w = gpower[d].data(); i < _end; i += 2, j += 2, w += 2) {
                    ull tmp1 = *j * *w % mod;
                    *j = *i - tmp1 + mod;
                    *i += tmp1;
                    ull tmp2 = *(j + 1) * *(w + 1) % mod;
                    *(j + 1) = *(i + 1) - tmp2 + mod;
                    *(i + 1) += tmp2;
                }
            }
        reverse(a + 1, a + (1 << l));
        int inv = power(1 << l, mod - 2);
        for (ull *i = a; i < a + (1 << l); i++) *i = *i * inv % mod;
    }
    inline void NTT(poly &a, int l, int type) {
        if (l == 0) return;
        for (int i = 0; i < 1 << l; i++) nttf[i] = a[i].x;
        (type == 1 ? DIF : DIT)(nttf, l);
        for (int i = 0; i < 1 << l; i++) a[i].x = nttf[i];
    }
    inline poly operator * (poly a, poly b) {
        int n = len(a), m = len(b);
        int l = 0;
        for (; 1 << l < n + m - 1; l++);
        a.resize(1 << l), b.resize(1 << l);
        NTT(a, l, 1), NTT(b, l, 1);
        for (int i = 0; i < 1 << l; i++) a[i] *= b[i];
        NTT(a, l, -1);
        a.resize(n + m - 1);
        return a;
    }
    inline poly operator * (poly a, mint b) {
        for (auto &i : a) i = i * b;
        return a;
    }
    inline poly xToax(poly p, mint a) {
        mint cur = 1;
        for (auto &i : p) i *= cur, cur *= a;
        return p;
    }
    inline poly Inv(const poly &a, int size) {
        poly ans;
        ans.push_back(a[0].inv());
        const mint I = gpower[1][1];
        for (int l = 0; 1 << l < size; l++) {
            poly ansc = ans;
            poly A(a.begin(), min(a.end(), a.begin() + (2 << l)));
            ansc.resize(2 << l);
            A.resize(2 << l);
            NTT(A, l + 1, 1), NTT(ansc, l + 1, 1);
            for (int i = 0; i < 2 << l; i++) A[i] = (A[i] * ansc[i] - 1) * ansc[i];
            NTT(A, l + 1, -1);
            ansc = ans;
            poly B(a.begin(), min(a.end(), a.begin() + (2 << l)));
            B.resize(2 << l);
            ansc = xToax(ansc, gpower[l + 1][1]);
            B = xToax(B, gpower[l + 1][1]);
            for (int i = 0; i < 1 << l; i++) B[i] += B[1 << l | i];
            B.resize(1 << l);
            NTT(B, l, 1), NTT(ansc, l, 1);
            for (int i = 0; i < 1 << l; i++) B[i] = (B[i] * ansc[i] - 1) * ansc[i];
            NTT(B, l, -1);
            B = xToax(B, gpower[l + 1][(4 << l) - 1]);
            ans.resize(2 << l);
            for (int i = 0; i < 1 << l; i++) ans[1 << l | i] = inv[2] * (I * (A[i] + B[i]) - A[1 << l | i]);
        }
        ans.resize(size);
        return ans;
    }
    inline poly Der(poly a) {
        for (int i = 1; i < len(a); i++) a[i - 1] = i * a[i];
        a.pop_back();
        return a;
    }
    inline poly Int(poly a) {
        a.push_back(0);
        for (int i = len(a); i --> 1; ) a[i] = a[i - 1] * inv[i];
        a[0] = 0;
        return a;
    }
    inline poly Ln(const poly &a, int size) {
        poly ans = Int(Inv(a, size) * Der(a));
        ans.resize(size);
        return ans;
    }
    inline poly operator + (poly a, const poly &b) {
        a.resize(max(len(a), len(b)));
        for (int i = 0; i < len(b); i++) a[i] += b[i];
        return a;
    }
    inline poly operator - (poly a, const poly &b) {
        a.resize(max(len(a), len(b)));
        for (int i = 0; i < len(b); i++) a[i] -= b[i];
        return a;
    }
    inline poly Exp(const poly &a, int size) {
        poly ans;
        ans.push_back(1);
        for (int l = 0; 1 << l < size; l++) {
            poly b = ans, tmp(a.begin(), min(a.end(), a.begin() + (2 << l)));
            b.resize(2 << l), tmp.resize(2 << l);
            tmp = tmp - Ln(ans, 2 << l);
            NTT(b, l + 1, 1), NTT(tmp, l + 1, 1);
            for (int i = 0; i < 2 << l; i++) tmp[i] *= b[i];
            NTT(tmp, l + 1, -1);
            ans.resize(2 << l);
            for (int i = 1 << l; i < 2 << l; i++) ans[i] = tmp[i];
        }
        ans.resize(size);
        return ans;
    }
    inline poly T(poly a) {
        reverse(a.begin(), a.end());
        return a;
    }
    inline poly Div(const poly &a, const poly &b) {
        if (len(a) < len(b)) return poly();
        int l = len(a) - len(b) + 1;
        poly ans = T(a) * Inv(T(b), l);
        ans.resize(l);
        return T(ans);
    }
    inline poly Mod(const poly &a, const poly &b) {
        poly ans = a - Div(a, b) * b;
        ans.resize(len(b) - 1);
        return ans;
    }
    inline mint calcVal(const poly &a, mint b) {
        mint ans = 0;
        for (int i = len(a); i --> 0; ) ans = ans * b + a[i];
        return ans;
    }
    inline poly Pow(poly a, mint b, int size) {
        int n = len(a);
        return Exp(Ln(a, size) * b, size);
    }
    inline poly Sqrt(poly a, int size) {
        mint st = msqrt(a[0]), sti = a[0].inv();
        for (auto &i : a) i = i * sti;
        a = Pow(a, inv[2], size);
        for (auto &i : a) i = i * st;
        return a;
    }
    namespace QuickCalc {
        mint *x, *y;
        poly *p;
        void build(int cur, int l, int r) {
            if (l == r) return void(p[cur] = poly{1, -x[l]});
            int mid = l + r >> 1;
            build(cur << 1, l, mid);
            build(cur << 1 | 1, mid + 1, r);
            p[cur] = p[cur << 1] * p[cur << 1 | 1];
        }
        inline poly Tmult(poly a, poly b) {
            b = T(b);
            int l = 0, n = len(a), m = len(b);
            for (; 1 << l < n; l++);
            a.resize(1 << l), b.resize(1 << l);
            NTT(a, l, 1), NTT(b, l, 1);
            for (int i = 0; i < 1 << l; i++) a[i] *= b[i];
            NTT(a, l, -1);
            int ansl = n - m + 1;
            poly ans(ansl);
            for (int i = 0; i < ansl; i++) ans[i] = a[m - 1 + i];
            return ans;
        }
        void calc(const poly &cur, int x, int l, int r) {
            if (l == r) return void(y[l] = cur[0]);
            int mid = l + r >> 1;
            calc(Tmult(cur, p[x << 1 | 1]), x << 1, l, mid);
            calc(Tmult(cur, p[x << 1]), x << 1 | 1, mid + 1, r);
        }
        inline void quickeva(poly f, int m, mint *X, mint *Y) {
            if (m == 0) return;
            int l = 0, n = len(f);
            for (; 1 << l < m; l++);
            p = new poly[(2 << l) + 1];
            x = X, y = Y;
            build(1, 0, m - 1);
            f.resize(n + m - 1);
            calc(Tmult(f, Inv(p[1], n)), 1, 0, m - 1);
            delete[] p;
            x = y = nullptr;
        }
        poly calc2(int x, int l, int r) {
            if (l == r) return poly({y[l]});
            int mid = l + r >> 1;
            return calc2(x << 1, l, mid) * p[x << 1 | 1] + calc2(x << 1 | 1, mid + 1, r) * p[x << 1];
        }
        inline poly quickint(int n, mint *X, mint *Y) {
            if (n == 0) return poly();
            int l = 0;
            for (; 1 << l < n; l++);
            p = new poly[(2 << l) + 1];
            x = X;
            y = new mint[n];
            build(1, 0, n - 1);
            poly f = Der(T(p[1]));
            f.resize(n + n - 1);
            calc(Tmult(f, Inv(p[1], n)), 1, 0, n - 1);
            for (int i = 0; i < n; i++) y[i] = Y[i] * y[i].inv();
            poly ans = calc2(1, 0, n - 1);
            delete[] p;
            delete[] y;
            x = y = nullptr;
            return T(ans);
        }
    }
    using QuickCalc :: quickeva;
    using QuickCalc :: quickint;
}
using Poly :: operator *;
using Poly :: operator +;
using Poly :: operator -;

const int N = 500005;
int n, m;
mint a[N], c[N];

int main() {
    scanf("%d", &n), m = (n - 1) / 2;
    Poly :: init();
    Poly :: poly F;
    F.resize(n + 1);
    for (int i = 1; i <= m; ++i) F[i] = inv[i];
    F = Poly :: Exp(F, n + 1);
    for (int i = 0; i <= m + 1; ++i) {
        a[i] = F[n - i]; 
        if (i >= 2) a[i] *= fac[i - 2];
    }
    Poly :: poly A, B;
    A.resize(n + 1), B.resize(n + 1);
    for (int i = 0; i <= n; ++i) A[i] = a[i], B[i] = ifac[n - i];
    A = A * B;
    for (int i = 2; i <= n; ++i) {
        c[i] = A[i + n];
        c[i] *= ifac[i - 2];
        c[i] *= fac[n - i];
        c[i] *= fac[i - 1];
    }
    c[1] = c[2];
    for (int i = 1; i <= n; ++i) printf("%d ", c[i].x);
    printf("\n");
    return 0;
}