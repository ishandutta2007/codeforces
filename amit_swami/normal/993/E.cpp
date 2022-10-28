#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;
#define pw(x) (1ll << (x))
typedef double dbl;

namespace fft
{
    const int maxBase = 19;
    const int maxN = 1 << maxBase;

    struct num
    {
        dbl x, y;
        num(){}
        num(dbl xx, dbl yy): x(xx), y(yy) {}
        num(dbl alp): x(cos(alp)), y(sin(alp)) {}
    };

    inline num operator + (num a, num b) { return num(a.x + b.x, a.y + b.y); }
    inline num operator - (num a, num b) { return num(a.x - b.x, a.y - b.y); }
    inline num operator * (num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline num conj(num a) { return num(a.x, -a.y); }

    const dbl PI = acos(-1);

    num root[maxN];
    int rev[maxN];
    bool rootsPrepared = false;

    void prepRoots()
    {
        if (rootsPrepared) return;
        rootsPrepared = true;
        root[1] = num(1, 0);
        for (int k = 1; k < maxBase; ++k)
        {
            num x(2 * PI / pw(k + 1));
            for (int i = pw(k - 1); i < pw(k); ++i)
            {
                root[2 * i] = root[i];
                root[2 * i + 1] = root[i] * x;
            }
        } 
    }    

    int base, N;

    int lastRevN = -1;
    void prepRev()
    {
        if (lastRevN == N) return;
        lastRevN = N;
        forn(i, N) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (base - 1));
    }

    void fft(num *a, num *f)
    {
        forn(i, N) f[i] = a[rev[i]];
        for (int k = 1; k < N; k <<= 1) for (int i = 0; i < N; i += 2 * k) forn(j, k)
        {
            num z = f[i + j + k] * root[j + k];
            f[i + j + k] = f[i + j] - z;
            f[i + j] = f[i + j] + z;
        }
    }

    num a[maxN], f[maxN];
    ll A[maxN], B[maxN], C[maxN];

    void prepAB(int n1, int n2)
    {
        base = 1;
        N = 2;
        while (N < n1 + n2) base++, N <<= 1;

        for (int i = n1; i < N; ++i) A[i] = 0;
        for (int i = n2; i < N; ++i) B[i] = 0;

        prepRoots();
        prepRev();
    }

    void mult(int n1, int n2)
    {
        prepAB(n1, n2);
        forn(i, N) a[i] = num(A[i], B[i]);
        fft(a, f);
        forn(i, N)
        {
            int j = (N - i)  & (N - 1);
            a[i] = (f[j] * f[j] - conj(f[i] * f[i])) * num(0, -0.25 / N);
        }
        fft(a, f);
        forn(i, N) C[i] = (ll)round(f[i].x);
    }
}

const int N = 2.1e5;

int a[N];
int b[N];
int c[N];
long long r[N];

int main() {
#ifdef amit_swami
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int n, x;
    scanf("%d%d", &n, &x);    
    forn(i, n) scanf("%d", &a[i]);
    forn(i, n) b[i] = a[i] < x ? 1 : 0;
    forn(i, n) c[i + 1] = c[i] + b[i];

    forn(i, n) fft::A[N - c[i]]++;
    for (int i = 1; i <= n; i++) fft::B[c[i]]++;

    fft::mult(N+1, N+1);

    forn(i, n + 1) r[i] = fft::C[N + i];
    ll total = n * (ll)(n + 1) / 2;
    r[0] = total;
    forn(i, n) r[0] -= r[i + 1];

    forn(i, n + 1) printf("%lld%c", r[i], " \n"[i == n]); 

    return 0;
}