#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second 

int mod = 998244353, N = 1 << 20;

long long modpow (long long a, int b) {
    long long ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

long long w = modpow(3, (mod - 1) / N);

void FFT (vector <long long> &P, bool inv = false) {
    int n = P.size(), lg = __builtin_ctz(n);
    
    // bit reverse
    for (int i = 0, j = 1; j < n - 1; ++j) {
        int k = n >> 1;
        while (k > (i ^= k)) k >>= 1;
        if (i > j) swap(P[i], P[j]);
    }
    
    vector <long long> ws = {inv ? modpow(w, mod - 2) : w};
    for (int i = 1; i < lg; ++i) ws.push_back(ws.back() * ws.back() % mod);
    reverse(ws.begin(), ws.end());
    
    for (int i = 0; i < lg; ++i) {
        for (int k = 0; k < n; k += (2 << i)) {
            long long base = 1;
            for (int j = k; j < k + (1 << i); ++j, base = base * ws[i] % mod) {
                long long t = base * P[j + (1 << i)] % mod, u = P[j];
                P[j] = u + t;
                if (P[j] >= mod) P[j] -= mod;
                P[j + (1 << i)] = u - t;
                if (P[j + (1 << i)] < 0) P[j + (1 << i)] += mod;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; ++i) {
            P[i] = P[i] * modpow(n, mod - 2) % mod;
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, tmp;
    cin >> n >> k;
    vector <long long> A(N, 0);
    fop (i,0,n) {
        cin >> tmp;
        A[tmp]++;
    }
    vector <long long> B = A;
    FFT(A);
    fop (i,0,N) A[i] = modpow(A[i], k);
    FFT(A, true);
    mod = 605028353;
    w = modpow(3, (mod - 1) / N);
    FFT(B);
    fop (i,0,N) B[i] = modpow(B[i], k);
    FFT(B, true);
    fop (i,0,N) {
        if (A[i] or B[i]) cout << i << ' ';
    }
    cout << endl;
}