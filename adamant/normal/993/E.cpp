#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#include <bits/stdc++.h>

#define int int64_t
using namespace std;

#define int int64_t
const int logn = 21;
const int maxn = 1 << logn;

typedef complex<double> ftype;
const double pi = acos(-1);
ftype w[maxn];

template<typename T>
void fft(T *in, T *out, int n, int k) {
    if(n == 1) {
        *out = *in;
        return;
    }
    n /= 2;
    fft(in, out, n, 2 * k);
    fft(in + k, out + n, n, 2 * k);
    for(int i = 0; i < n; i++) {
        ftype t = w[i + n] * out[i + n];
        out[i + n] = out[i] - t;
        out[i] = out[i] + t;
    }
}

const int mod = 1e4, len = 4;

void normalize(vector<int> &ans) {
    return;
    // Garbage for this problem
    int carry = 0;
    for(int i = 0; i < (int)ans.size(); i++) {
        ans[i] += carry;
        carry = ans[i] / mod;
        ans[i] -= carry * mod;
    }
    if(carry) {
        ans.push_back(carry);
    }
    while(ans.back() == 0 && ans.size() > 1) {
        ans.pop_back();
    }
}

ftype sqr(ftype x) {
    return x * x;
}

vector<int> mul(vector<int> a, vector<int> b) {
    int n = a.size() + b.size();
    if(n <= 1000) {
        vector<int> c(n - 1);
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b.size(); j++) {
                c[i + j] += a[i] * b[j];
            }
        }
        normalize(c);
        return c;
    }
    while(__builtin_popcount(n) != 1)
        n++;
    while((int)a.size() < n)
        a.push_back(0);
    while((int)b.size() < n)
        b.push_back(0);

    vector<ftype> A(n);
    for(int i = 0; i < n; i++) {
        A[i] = ftype(a[i], b[i]);
    }
    vector<ftype> nA(n);
    fft(A.data(), nA.data(), n, 1);
    for(int i = 0; i < n; i++) {
        A[i] = (sqr(nA[i]) - sqr(conj(nA[(n - i) % n]))) / ftype(0, 4);
    }
    fft(A.data(), nA.data(), n, 1);
    reverse(begin(nA) + 1, end(nA));
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = llround(real(nA[i]) / n);
    }
    normalize(ans);
    return ans;
}

signed main() {
    for(int z = 1; z < maxn; z *= 2) {
        for(int i = 0; i < z; i++) {
            w[z + i] = polar(1., pi * i / z);
            assert(z + i < maxn);
        }
    }
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int a[n];
    int psum[n + 1];
    psum[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] < x;
        psum[i + 1] = psum[i] + a[i];
    }
    // How many l < r : psum[r] - psum[l] = k?
    vector<int> A(n + 1);
    for(int i = 0; i <= n; i++) {
        A[psum[i]]++;
    }
    vector<int> B(A.rbegin(), A.rend());
    // B[j] = A[n - j]
    // C[i + j] <- A[i] * B[j] = A[i] * A[n - j]
    // C[k + n] = sum for i - j = k
    auto lol = mul(A, B);
    int cnt = 0;
    int t = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            t = i;
        }
        cnt += i - t;
    }
    for(int i = 0; i <= n; i++) {
        if(i == 0) {
            lol[i + n] = cnt;
        }
        cout << lol[i + n] << ' ';
    }
}