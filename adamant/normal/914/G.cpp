#include <bits/stdc++.h> 

using namespace std;

#define int int64_t

const int maxn = 1 << 17, mod = 1e9 + 7;
int A[maxn], B[maxn], C[maxn], F[maxn];

void xor_fft(int *in, int *out, int n) {
    if(n == 1) {
        *out = *in;
        return;
    }
    n /= 2;
    xor_fft(in, out, n);
    xor_fft(in + n, out + n, n);
    for(int i = 0; i < n; i++) {
        out[i] = out[i] + out[i + n];
        out[i + n] = out[i] - 2 * out[i + n] + 2 * mod;
        out[i] %= mod;
        out[i + n] %= mod; 
    }
}

int AA[maxn];

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

void xor_multiply(int *a, int *c) {
    xor_fft(a, AA, maxn);
    for(int i = 0; i < maxn; i++) {
        AA[i] *= AA[i];
        AA[i] %= mod;
    }
    xor_fft(AA, c, maxn);
    int inv = bpow(maxn, mod - 2);
    for(int i = 0; i < maxn; i++) {
        c[i] *= inv;
        c[i] %= mod;
    }
}

void transform(int *from, int *to) { 
    if(to - from == 1) 
        return; 
    int *mid = from + (to - from) / 2; 
    transform(from, mid); 
    transform(mid, to); 
    for(int i = 0; i < mid - from; i++) {
        *(from + i) += *(mid + i);
        *(from + i) %= mod; 
    }
} 

void inverse(int *from, int *to) { 
    if(to - from == 1) 
        return; 
    int *mid = from + (to - from) / 2; 
    inverse(from, mid); 
    inverse(mid, to); 
    for(int i = 0; i < mid - from; i++) {
        *(from + i) -= *(mid + i) - mod;
        *(from + i) %= mod; 
    }
}

void and_multiply(int *A, int *B, int *C) {
    transform(A, A + maxn);
    transform(B, B + maxn);
    transform(C, C + maxn);
    for(int i = 0; i < maxn; i++) {
        A[i] = A[i] * B[i] % mod * C[i] % mod;
    }
    inverse(A, A + maxn);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i < maxn; i++) {
        F[i] = F[i - 1] + F[i - 2];
        F[i] %= mod;
    }
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        B[a[i]]++;
    }
    for(int mask = 0; mask < maxn; mask++) {
        for(int i = mask; ; i = (i - 1) & mask) {
            A[mask] += B[i] * B[mask ^ i];
            A[mask] %= mod;
            if(i == 0) {
                break;
            }
        }
    }
    xor_multiply(B, C);
    for(int i = 0; i < maxn; i++) {
        A[i] *= F[i];
        B[i] *= F[i];
        C[i] *= F[i];
        A[i] %= mod;
        B[i] %= mod;
        C[i] %= mod;
    }
    and_multiply(A, B, C);
    int ans = 0;
    for(int i = 0; i < 17; i++) {
        ans += A[1 << i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}