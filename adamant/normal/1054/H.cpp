#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

const int logn = 21;
const int maxn = 1 << logn;
const int mod = 2 * 491 * 499 + 1;
const int shift = 16;
const int mask = (1 << shift) - 1;

typedef complex<double> ftype;
const double pi = acos(-1);
ftype w[maxn];

template<typename T>
void fft(T *in, ftype *out, int n, int k = 1) {
    if(n == 1) {
        *out = *in;
        return;
    }
    n /= 2;
    fft(in, out, n, 2 * k);
    fft(in + k, out + n, n, 2 * k);
    for(int i = 0; i < n; i++) {
        ftype t = out[i + n] * w[i + n];
        out[i + n] = out[i] - t;
        out[i] += t;
    }
}

vector<int> nrm(vector<int> x) {
    while(x.size() && x.back() == 0) {
        x.pop_back();
    }
    return x;
}

vector<int> mul(vector<int> a, vector<int> b) {
    int n = a.size() + b.size() - 1;
    while(__builtin_popcount(n) != 1) {
        n++;
    }
    while((int)a.size() < n) {
        a.push_back(0);
    }
    while((int)b.size() < n) {
        b.push_back(0);
    }
    static ftype A[maxn], B[maxn];
    static ftype C[maxn], D[maxn];
    for(int i = 0; i < n; i++) {
        A[i] = {a[i] & mask, a[i] >> shift};
        B[i] = {b[i] & mask, b[i] >> shift};
    }
    fft(A, C, n);
    fft(B, D, n);
    for(int i = 0; i < n; i++) {
        ftype c0 = (C[i] + conj(C[(n - i) % n])) / ftype(2, 0);
        ftype c1 = (C[i] - conj(C[(n - i) % n])) / ftype(0, 2);
        ftype d0 = (D[i] + conj(D[(n - i) % n])) / ftype(2, 0);
        ftype d1 = (D[i] - conj(D[(n - i) % n])) / ftype(0, 2);
        A[i] = c0 * d0 + ftype(0, 1) * c1 * d1;
        B[i] = c0 * d1 + d0 * c1;
    }
    fft(A, C, n);
    fft(B, D, n);
    reverse(C + 1, C + n);
    reverse(D + 1, D + n);
    for(int i = 0; i < n; i++) {
        int64_t A0 = llround(real(C[i]) / n);
        int64_t A1 = llround(real(D[i]) / n);
        int64_t A2 = llround(imag(C[i]) / n);
        a[i] = (A0 + (A1 % mod << shift) + (A2 % mod << 2 * shift)) % mod;
    }
    return a;
}

template<typename T>
inline T sqr(T x) {
    return x * x;
}

inline int normalize(int x, int m) {
    return x < 0 ? x + m : x >= m ? x - m : x;
}
inline int mul(int a, int b, int m) {
    return int64_t(a) * b % m;
}
inline int add(int a, int b, int m) {
    return normalize(a + b, m);
}
inline int sub(int a, int b, int m) {
    return normalize(a - b, m);
}
inline int bpow(int x, int n, int m) {
    return n ? (n & 1) ? mul(x, bpow(x, n - 1, m), m) : bpow(mul(x, x, m), n >> 1, m) : 1;
}
inline int inv(int x, int m) {
    return bpow(x, m - 2, m);
}


int PW[mod], IPW[mod];

    vector<int> u(mod);
    vector<int> v(2 * mod - 1);
vector<int> chirpz(vector<int> p, int root, int m, bool rev = 0) {
    for(auto &it: p) {
        it = normalize(it, m);
    }
    int n = p.size();
    if(rev) {
        for(int i = 0; i < n; i++) {
            u[i] = u[i] * PW[i] % mod;
        }
    } else {
        for(int i = 0; i < n; i++) {
            int t = PW[1LL * i * i % (m - 1)];
            u[i] = 1LL * p[i] * t % m;
            v[(n - 1) - i] = v[(n - 1) + i] = IPW[1LL * i * i % (m - 1)];
        }
    }
    auto w = mul(u, v);
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = mul(bpow(root, mul(i, i, m - 1), m), w[(n - 1) + i], m);
    }
    return ans;
}

const int phi = mod - 1;

void fail() {
    cout << "NO" << endl;
    exit(0);
}

bool check(int g) {
    return !(bpow(g, 2 * 491, phi) == 1 || bpow(g, 2 * 499, phi) == 1 || bpow(g, 491 * 499, phi) == 1);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < maxn; i *= 2) {
        for(int j = 0; j < i; j++) {
            w[i + j] = polar(1., pi * j / i);
        }
    }
    int i2 = inv(2, mod);
    PW[0] = IPW[0] = 1;
    for(int i = 1; i < mod; i++) {
        PW[i] = 1LL * PW[i - 1] * 2 % mod;
        IPW[i] = 1LL * IPW[i - 1] * i2 % mod;
    }
    
    int n, m, c;
    cin >> n >> m >> c;
    int a[n], b[m];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> p(mod - 1);
    for(int j = 0; j < m; j++) {
        cin >> b[j];
        p[1LL * j * j * j % phi] += b[j];
        p[1LL * j * j * j % phi] %= mod;
    }
    auto np = p;
    for(int j = phi / 2; j < phi; j++) {
        p[j - phi / 2] += p[j];
        p[j - phi / 2] %= mod;
    }
    p.resize(phi / 2);
    int root = 2;
    vector<int> eval[2];
    eval[0] = chirpz(p, root, mod);
    p = np;
    for(int i = 0; i < phi; i++) {
        p[i] = 1LL * p[i] * PW[i] % mod;
    }
    for(int j = phi / 2; j < phi; j++) {
        p[j - phi / 2] += p[j];
        p[j - phi / 2] %= mod;
    }
    p.resize(phi / 2);
    eval[1] = chirpz(p, root, mod);
    int rv[mod];
    for(int i = 0; i < phi; i++) {
        rv[PW[i]] = i;
    }
    for(int i = 0; i < 0; i++) {
        int x = bpow(2, i, mod);
        int cur = 0;
        for(int j = 0; j < mod; j++) {
            cur += 1LL * np[j] * bpow(x, j, mod) % mod;
            cur %= mod;
        }
        assert(cur == eval[i % 2][i / 2]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = bpow(c, 1LL * i * i % phi, mod);
        int t = rv[x];
        ans += 1LL * a[i] * eval[t % 2][t / 2] % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}