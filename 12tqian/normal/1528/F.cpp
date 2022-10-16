#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

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

namespace FFT {

template <class T> void fft(std::vector<T>& A, bool inv = 0) {
    int n = (int)A.size();
    assert((T::mod - 1) % n == 0);
    std::vector<T> B(n);
    for (int b = n / 2; b; b /= 2, A.swap(B)) {
        T w = pow(T::rt(), (T::mod - 1) / n * b);
        T m = 1;
        for (int i = 0; i < n; i += b * 2, m *= w)
            for (int j = 0; j < b; j++) {
                T u = A[i + j];
                T v = A[i + j + b] * m;
                B[i / 2 + j] = u + v;
                B[i / 2 + j + n / 2] = u - v;
            }
    }
    if (inv) {
        std::reverse(1 + A.begin(), A.end());
        T z = T(1) / T(n);
        for (auto & t : A) 
            t *= z;
    }
}

template <class T> std::vector<T> multiply(std::vector<T> A, std::vector<T> B) {
    int sa = (int)A.size();
    int sb = (int)B.size();
    if (!std::min(sa, sb))
        return {};
    int s = sa + sb - 1;
    int n = 1;
    for (; n < s; n *= 2);
    bool eq = A == B;
    A.resize(n);
    fft(A);
    if (eq) 
        B = A;
    else 
        B.resize(n), fft(B);
    for (int i = 0; i < n; i++)
        A[i] *= B[i];
    fft(A, 1);
    A.resize(s);
    return A;
}

template <class M, class T> std::vector<M> multiply_mod(std::vector<T> x, std::vector<T> y) {
    auto convert = [](const std::vector<T>& v) {
        std::vector<M> w((int)v.size());
        for (int i =  0; i < (int)v.size(); i++)
            w[i] = (int) v[i];
        return w;
    };
    return multiply(convert(x), convert(y));
}

template <class T> std::vector<T> general_multiply(const std::vector<T>& A, const std::vector<T>& B) { 
    // arbitrary modulus
    using m0 = Mint<(119 << 23) + 1, 62>; 
    using m1 = Mint<(5 << 25) + 1, 62>;
    using m2 = Mint<(7 << 26) + 1, 62>;
    auto c0 = multiply_mod<m0>(A, B);
    auto c1 = multiply_mod<m1>(A, B);
    auto c2 = multiply_mod<m2>(A, B);
    int n = (int)c0.size();
    std::vector<T> res(n);
    m1 r01 = 1 / m1(m0::mod);
    m2 r02 = 1 / m2(m0::mod);
    m2 r12 = 1 / m2(m1::mod);
    for (int i = 0; i < n; i++) {
        int a = c0[i].v;
        int b = ((c1[i] - a) * r01).v;
        int c = (((c2[i] - a) * r02 - b) * r12).v;
        res[i] = (T(c) * m1::mod + b) * m0::mod + a;
    }
    return res;
}

} // namespace FFT

using namespace FFT;

using mi = Mint<998244353, 5>;

const int K = 1e5 + 5;

mi fact[K], ifact[K], over[K];

mi mult[K]; // n choose i 
mi stirling[K];

mi C(int x, int y) {
    if (x < y) return 0;
    return fact[x] * ifact[y] * ifact[x - y];
}

void compute_stirling(int n) {
    vector<mi> t1(n + 1);
    vector<mi> t2(n + 1);
    f0r(i, n + 1) {
        t1[i] = ifact[i];
        if (i % 2) t1[i] *= -1;
        t2[i] = pow(mi(i), n) * ifact[i];
    }
    vector<mi> res = multiply(t1, t2);
    f0r(i, n + 1) stirling[i] = res[i];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fact[0] = 1;
    f1r(i, 1, K) fact[i] = fact[i - 1] * i;
    ifact[K - 1] = 1 / fact[K - 1];
    for (int i = K - 2; i >= 0; --i) ifact[i] = ifact[i + 1] * (i + 1);
    f1r(i, 1, K) over[i] = ifact[i] * fact[i - 1];
    
    int n, k; cin >> n >> k;
    
    mult[0] = 1;
    
    f1r(i, 1, k + 1) {
        mult[i] = mult[i - 1] * over[i] * (n + 1 - i);
    }

    mi run = pow(mi(n + 1), n);
    mi times = 1 / mi(n + 1);

    f0r(i, k + 1) {
        mult[i] *= fact[i];
        mult[i] *= run;
        run *= times;
    }

    compute_stirling(k);
    
    mi ans = 0;
    
    f0r(i, k + 1) {
        ans += mult[i] * stirling[i];
    }
    
    cout << ans << '\n';
    return 0;
}

/**
 * parking function more like biking function
 * let a[i] extend to the circle argument
 * we divide by (n + 1) at the very end
 * a[i] in [0, n]
 * so basically given a sequence of length n with n + 1 possible elements
 * c[0], c[1], ..., c[n] be number of each element
 * then we want to sum up c[0]^k
 * just consider exactly one element, number of 0's
 * then we don't have to divide by (n + 1)
 */