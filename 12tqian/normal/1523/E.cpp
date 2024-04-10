#include <bits/stdc++.h>

using namespace std;

// 5 is a root of both mods
template <int MOD, int RT> struct Mint {
    static const int mod = MOD;
    static constexpr Mint rt() { return RT; } // primitive root for FFT
    int v; 
    explicit operator int() const { return v; } // explicit -> don't silently convert to int
    Mint() { v = 0; }
    Mint(long long _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }
    friend bool operator == (const Mint& a, const Mint& b) { return a.v == b.v; }
    friend bool operator != (const Mint& a, const Mint& b) { return !(a == b); }
    friend bool operator < (const Mint& a, const Mint& b) { return a.v < b.v; }
    friend bool operator > (const Mint& a, const Mint& b) { return a.v > b.v; }
    friend bool operator <= (const Mint& a, const Mint& b) { return a.v <= b.v; }
    friend bool operator >= (const Mint& a, const Mint& b) { return a.v >= b.v; }
    friend std::istream& operator >> (std::istream& in, Mint& a) { 
        long long x; std::cin >> x; a = Mint(x); return in; }
    friend std::ostream& operator << (std::ostream& os, const Mint& a) { return os << a.v; }
    Mint& operator += (const Mint& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    Mint& operator -= (const Mint& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    Mint& operator *= (const Mint& m) { 
        v = (long long) v * m.v % MOD; return *this; }
    Mint& operator /= (const Mint& m) { return (*this) *= inv(m); }
    friend Mint pow(Mint a, long long p) {
        Mint ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; 
    }
    friend Mint inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD - 2); }
    Mint operator - () const { return Mint(-v); }
    Mint& operator ++ () { return *this += 1; }
    Mint& operator -- () { return *this -= 1; }
    friend Mint operator + (Mint a, const Mint& b) { return a += b; }
    friend Mint operator - (Mint a, const Mint& b) { return a -= b; }
    friend Mint operator * (Mint a, const Mint& b) { return a *= b; }
    friend Mint operator / (Mint a, const Mint& b) { return a /= b; }
};

using mi = Mint<1000000007, 5>;

const int N = 1e5 + 5;

mi fact[N], ifact[N];

mi C(long long x, long long y) {
    if (x < y) {
        return 0;
    }
    return fact[x] * ifact[y] * ifact[x - y];
}

void solve_case(int tc = 0) {
    long long n, k; 
    cin >> n >> k;
    mi ans = 0;
    for (int i = 2; i <= n; ++i) { // n / k
        // pick i lights
        mi c0 = C(n - (i - 1) * (k - 1) - i + i, i);
        mi c1 = C(n - (i - 2) * (k - 1) - i + i, i);
        mi c2 = C(n - (i - 3) * (k - 1) - i + i, i);
        if (c0 == 0 && c1 == 0 && c2 == 0) {
            break;
        }
        mi n1 = (i - 1) * (c1 - c0); 
        mi n2 = (i - 2) * (c2 - 2 * c1 + c0);
        mi sub = 0;
        for (int j = 1; j <= k - 2; ++j) {
            n2 -= (i - 2) * j * C(n - (i - 3) * (k - 1) - (j - 1) - i + i - 2, i - 2);
        }
        mi den = ifact[n] * fact[n - i];
        ans += n1 * den * 2 * fact[i - 1] * i;
        if (i >= 3) {
            ans += n2 * den * fact[i - 1] * i;
        }   
    }
    cout << ans << '\n';
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    ifact[N - 1] = 1 / fact[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        ifact[i] = ifact[i + 1] * (i + 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    precompute();
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; ++tc) {
        solve_case(tc);
    }
    return 0;
}