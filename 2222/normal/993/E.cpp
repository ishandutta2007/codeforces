#include <bits/stdc++.h>

using namespace std;

#define sz(a)           int((a).size())
#define all(a)          (a).begin(), (a).end()
#define FOR(i,a,b)      for (int i = 0, _n(b); i < _n; ++i)
#define REP(i,n)        FOR(i, 0, n)

using cd = complex<double>;

const double PI = acos(-1.0);
constexpr int N = 1 << 20;

cd W[N];

template <bool Inv>
void fft(cd* p, int n) {
    n /= 2;
    for (int i = 0, j = n; i < n; ++i, ++j) {
        cd x = p[i], y = p[j];
        p[i] = (x + y);
        p[j] = (x - y) * (Inv ? W[j] : conj(W[j]));
    }
    if (n > 1) {
        fft<Inv>(p, n);
        fft<Inv>(p + n, n);
    }
}

template <class X>
void bitrev(X* a, int n) {
    for (int i = 0, j = 0, k; i < n; ++i) {
        if (i < j) swap(a[i], a[j]);
        for (k = n; j & (k /= 2); );
        j += 3 * k - n;
    }
}

vector<int64_t> mul(const vector<int64_t>& a, const vector<int64_t>& b) {
    int n = sz(a) + sz(b);
    for (; n & n - 1; n = (n | n - 1) + 1);
    vector<cd> af(n), bf(n);
    REP (i, sz(a)) af[i] = a[i];
    REP (i, sz(b)) bf[i] = b[i];
    fft<0>(af.data(), n);
    bitrev(af.data(), n);
    fft<0>(bf.data(), n);
    bitrev(bf.data(), n);
    REP (i, n) af[i] *= bf[i];
    fft<1>(af.data(), n);
    bitrev(af.data(), n);
    const double invN = 1.0 / n;
    vector<int64_t> c(n);
    REP (i, n) {
        c[i] = (int64_t)(af[i].real() * invN + 0.5);
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    REP (i, N / 2) W[i + N / 2] = polar(1.0, (2 * PI / N) * i);
    for (int i = N / 2; i --> 0; W[i] = W[2 * i]);
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    REP (i, n) {
        cin >> a[i + 1];
        a[i + 1] = a[i] + (a[i + 1] < x);
    }
    vector<int64_t> p(n + 2), q(n + 2);
    REP (i, n + 1) {
        p[a[i]]++;
        q[n - a[i]]++;
    }
    int64_t z = 0;
    REP (i, sz(p)) {
        z += p[i] * (p[i] - 1) / 2;
    }
    cout << z;
    p = mul(p, q);
    REP (i, n) {
        cout << ' ' << p[i + n + 1];
    }
    cout << endl;
    return 0;
}