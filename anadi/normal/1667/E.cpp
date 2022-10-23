#include <bits/stdc++.h>

using namespace std;

namespace NTT {
    #define SZ(x) (x).size()
    #define rep(i,a,b) for (int i = (a); i < (b); ++i)

    typedef unsigned long long ull;
    typedef unsigned T;
    //ma byc unsigned int albo ll albo ull
    //jak sie przekrecimy przez inta to zly wynik!
    const T P = 998244353;
    const T ROOT = 570984967;
    const int MN=21;
    T omega[1<<MN];
    T pw (T x, T n) {
        T res = 1;
        while(n) {
                if (n&1) res = (ull)res*x%P;
                x = (ull)x*x%P;
                n>>=1;
        }
        return res;
    }
    void fft(vector<T> &a, int n, bool inverse=false) {
        int N = 1<<n;
        a.insert(a.end(), N-SZ(a), 0);
        T root = pw(ROOT, (1<<23)/N*(inverse?(N-1):1));
        omega[0] = 1;
        rep(i, 1, N) omega[i] = (ull)omega[i-1]*root%P;
        rep(i, 0, n) {
                rep(j, 0, 1<<i) {
                        rep(k, 0, 1<<(n-i-1)) {
                                int s = (j<<(n-i))+k;
                                int t = s + (1<<(n-i-1));
                                T w = omega[k<<i];
                                T temp = a[s] + a[t];
                                if (temp >= P) temp -= P;
                                T t2 = a[s] - a[t] + P;
                                a[t] = (ull) w * t2 % P;
                                a[s] = temp;
                        }
                }
        }
        rep(i, 0, N) {
                int x=i,y=0;
                rep(j, 0, n)  y=(y<<1)+(x&1), x>>=1;
                if (i<y) swap(a[i],a[y]);
        }
        if (inverse) {
                T inv = pw(N, P-2);
                rep(i, 0, N) a[i] = (ull)a[i]*inv%P;
        }
    }
    vector<T> conv(vector<T> A, vector<T> B) {
        int n = 31-__builtin_clz(2*(SZ(A)+SZ(B))-1);
        fft(A, n);
        fft(B, n);
        rep(i, 0, (1<<n)) A[i] = (ull) A[i] * B[i] % P;
        fft(A, n, true);
        return A;
    }
    vector<T> square(vector<T> A) {
        int n = 32-__builtin_clz(2*SZ(A)-1);
        fft(A, n);
        rep(i, 0, (1<<n)) A[i] = (ull) A[i] * A[i] % P;
        fft(A, n, true);
        return A;
    }
}

const int N = 200'007;
const int MOD = 998'244'353;

int fast(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = 1LL * ret * a % MOD;
        }

        b >>= 1;
        a = 1LL * a * a % MOD;
    }

    return ret;
}

int n;
int sil[N], rev_sil[N];

int balanced[N];
int rev_sum[N];

int newton(int a, int b) {
    if (b < 0 || a < b) {
        return 0;
    }

    return 1LL * sil[a] * rev_sil[a - b] % MOD * rev_sil[b] % MOD;
}

int main()
{
    scanf("%d", &n);
    sil[0] = 1;
    for (int i = 1; i <= n; ++i) {
        sil[i] = 1LL * i * sil[i - 1] % MOD;
    }

    rev_sil[n] = fast(sil[n], MOD - 2);
    for (int i = n; i; --i) {
        rev_sil[i - 1] = 1LL * rev_sil[i] * i % MOD;
    }
    
    for (int i = (n + 1) / 2; i <= n; ++i) {
        rev_sum[i] = (rev_sum[i - 1] + 1LL * rev_sil[i] * sil[i - 1]) % MOD;
        balanced[i] = 1LL * sil[i - 1] * (MOD + 1 - rev_sum[i - 1]) % MOD;
        // printf("balanced[%d] = %d\n", i, balanced[i]);
    }

    vector <unsigned> a(n + 1), b(n + 2);
    for (int k = (n + 1) / 2; k < n; ++k) {
        a[n - k] = 1LL * balanced[k] * sil[n - 1 - k] % MOD * rev_sil[k - 1] % MOD;
    }

    for (int i = 0; i <= n + 1; ++i) {
        b[i] = rev_sil[n + 1 - i];
    }

    auto c = NTT::conv(a, b);
    printf("%d", balanced[n]);
    for (int i = 2; i <= n; ++i) {
        int ans = 1LL * c[n + i] * sil[n - i] % MOD * (i - 1) % MOD;
        printf(" %d", ans);
        // int ans = 0;
        // for (int k = (n + 1) / 2; k <= n - i + 1; ++k) {
        //     int tmp = 1LL * newton(n - i, k - 1) * balanced[k] % MOD;
        //     tmp = 1LL * tmp * (i - 1) % MOD * sil[n - k - 1] % MOD;
        //     ans = (ans + tmp) % MOD;
        // }

        // printf(" %d", ans);
    }

    puts("");
    return 0;
}