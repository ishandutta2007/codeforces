#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <bits/stdc++.h>

#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (decltype(a) i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first

using namespace std;

using cd = complex<double>;
using vi = vector<int>;

const double PI = acos(-1.0);

const int RADIX_DIGITS = 4;
const int RADIX = (int)pow(10, RADIX_DIGITS);
const int N = 1 << 19;

const double LOG_RADIX = log(RADIX);
const double LOG_3 = log(3.0);

istream& operator >> (istream& in, vi& r) {
    string s;
    in >> s;
    reverse(all(s));
    while (sz(s) % RADIX_DIGITS) s += '0';
    r.resize(sz(s) / RADIX_DIGITS);
    REP (i, sz(r)) REP (j, RADIX_DIGITS) r[i] = r[i] * 10 + s[(i + 1) * RADIX_DIGITS - 1 - j] - '0';
    return in;
}

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

void sqr(vi& a) {
    int n = 2 * sz(a) - 1;
    for (; n & n - 1; n = (n | n - 1) + 1);
    vector<cd> af(n);
    REP (i, sz(a)) af[i] = a[i];
    fft<0>(af.data(), n);
    bitrev(af.data(), n);
    REP (i, n) af[i] *= af[i];
    fft<1>(af.data(), n);
    bitrev(af.data(), n);
    const double invN = 1.0 / n;
    a.resize(n);
    ll carry = 0;
    REP (i, n) {
        carry += (ll)(af[i].real() * invN + 0.5);
        a[i] = carry % RADIX;
        carry /= RADIX;
    }
    if (carry) a.pb((int)carry);
    while (sz(a) && a.back() == 0) a.pop_back();
}

void mul(vi& a, int b) {
    int carry = 0;
    for (int &x : a) {
        carry += x * b;
        x = carry % RADIX;
        carry /= RADIX;
    }
    if (carry) a.pb(carry);
}

void div(vi& a, int b) {
    int x = 0;
    for (int i = sz(a); i --> 0; ) {
        x = x * RADIX + a[i];
        a[i] = x / b;
        x %= b;
    }
    if (x) ++a[0];
    while (sz(a) && a.back() == 0) a.pop_back();
}

int cmp(const vi& a, const vi& b) {
    if (sz(a) != sz(b)) return sz(a) - sz(b);
    for (int i = sz(a); i --> 0; )
        if (a[i] != b[i])
            return a[i] - b[i];
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    REP (i, N / 2) W[i + N / 2] = polar(1.0, (2 * PI / N) * i);
    for (int i = N / 2; i --> 0; W[i] = W[2 * i]);
    vi a;
    cin >> a;
    int n = sz(a);
    if (n == 1 && a[0] < 4) {
        cout << a[0] << endl;
        return 0;
    }
    double logA = n > 1 ? log(a[n - 1] * (double)RADIX + a[n - 2]) + LOG_RADIX * (n - 2) : log(a[n - 1]);
    int powerOf3 = max((int)(logA / LOG_3 - 1e-12) - 1, 0);
    int res = -1u/2;
    vi x[3];
    x[0] = {1};
    for (int i = 30; i >= 0; --i) {
        sqr(x[0]);
        if (powerOf3 & 1 << i) mul(x[0], 3);
    }
    x[1] = x[0];
    mul(x[1], 4);
    mul(x[0], 3);
    x[2] = x[0];
    mul(x[2], 2);
    for (int j = 0; j < 2; ++j) {
        ++powerOf3;
        if (j) div(a, 3);
        REP (i, 3) {
            if (cmp(x[i], a) >= 0) {
                res = min(res, 3 * powerOf3 + i);
            }
        }
    }
    cout << res << endl;
    return 0;
}