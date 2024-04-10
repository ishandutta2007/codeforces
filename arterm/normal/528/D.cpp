#include <bits/stdc++.h>

/* FFT by kevinsogo */
/* from https://www.hackerrank.com/contests/infinitum-jul14/challenges/costly-graphs/editorial */
/* many thanks =^_^= */

#define alok(n,t) (t*)malloc((n)*sizeof(t))
#define ll long long
#define mod 1005060097LL
#define r1 331361765LL
#define rt 19
#define sh 19
#define i2 ((mod+1)/2)
#define SH (1<<sh)

ll ipow(ll b, ll e) {
    if (!e) return 1;
    if (e == 1) return b % mod;
    if (e & 1) return ipow(b, e - 1) * b % mod;
    return ipow(b * b % mod, e >> 1);
}

// arrays
ll *prs = alok(rt+1,ll);
ll *irs = alok(rt+1,ll);
ll *fac = alok(SH<<1,ll);
ll *ifc = alok(SH<<1,ll);
ll *A = alok(SH<<1,ll);
ll *B = alok(SH<<1,ll);
ll *C = alok(SH<<1,ll);

void fft(ll *A, int m, int ms, ll *rs) {
    if (!ms) return;
    for (int k = 0; k < m; k++) C[k] = A[k];
    int cc = 0;
    for (int k = 0; k < m; k += 2) A[cc++] = C[k];
    for (int k = 1; k < m; k += 2) A[cc++] = C[k];
    m >>= 1;
    ll r = rs[ms--];
    fft(A  ,m,ms,rs);
    fft(A+m,m,ms,rs);
    ll pr = 1;
    for (int k = 0, km = m; k < m; k++, km++) {
        ll fE = A[k], fO = A[km]*pr;
        A[k ] = (fE + fO) % mod;
        A[km] = (fE - fO) % mod;
        pr = pr * r % mod;
    }  
}

void pre() {
    prs[rt] = r1;
    irs[rt] = ipow(r1,mod-2);
    for (int i = rt; i > 0; i--) {
        prs[i-1] = prs[i] * prs[i] % mod;
        irs[i-1] = irs[i] * irs[i] % mod;
    }

    fac[0] = fac[1] = ifc[0] = ifc[1] = 1;
    for (int i = 2; i < SH<<1; i++) {
        ifc[i] = (mod - mod/i) * ifc[mod % i] % mod;
    }
    for (int i = 2; i < SH<<1; i++) {
        fac[i] =     i  * fac[i-1] % mod;
        ifc[i] = ifc[i] * ifc[i-1] % mod;
    }
}

void mul(ll *a, ll *b, ll *to) {
    int m = (1 << rt);
    int ms = rt;
    fft(a, m, ms, prs);
    fft(b, m, ms, prs);
    for (auto i = 0; i < m; ++i)
        to[i] = (a[i] * b[i]) % mod;
    fft(to, m, ms, irs);

    ll iv = ipow(m,mod-2);
    for(int i = 0; i < m; i++) {
        to[i] = to[i] * iv % mod;
        if (to[i] < 0)
            to[i] += mod;
    }
}

using namespace std;

const int M = 300300;

int n, m, k;
bool good[M];
string s, t;

void setup(char c) {
    fill(A, A + (SH << 1), 0);
    fill(B, B + (SH << 1), 0);

    int last = 0;

    for (int i = 0; i < n; ++i)
        if (s[i] == c) {
            for (int j = max(last, i - k); j <= min(n - 1, i + k); ++j)
                A[j] = 1;
            last = min(n - 1, i + k) + 1;
        }
    for (int i = 0; i < n; ++i)
        A[i] = 1 - A[i];

    for (int i = 0; i < m; ++i)
        if (t[i] == c) {
            B[m - i] = 1;
        }

    /*for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << "\n";
    for (int i = 0; i <= m; ++i)
        cout << B[i] << " ";
    cout << "\n";*/

    mul(A, B, A);

    /*for (int i = 0; i < n + m; ++i)
        cout << A[i] << " ";
    cout << "\n";*/

    for (int i = m; i < n + m; ++i)
        if (A[i] != 0) {
            int x = i - m;
            good[x] = false;
        }
}

void read() {
    cin >> n >> m >> k;
    cin >> s >> t;
    fill(good, good + n, true);
}

void kill() {
    setup('A');
    setup('T');
    setup('G');
    setup('C');
    int ans = 0;
    for (int i = 0; i + m <= n; ++i)
        if (good[i]) {
            //cerr << i << "!\n";
            ++ans;
        }
    cout << ans << "\n";
}

int main() {
    pre();
    read();
    kill();
    return 0;  
}