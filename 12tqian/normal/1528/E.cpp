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

using mi = Mint<998244353, 5>;

const int N = 1e6 + 5;

mi i2 = mi(1) / 2;
mi i6 = mi(1) / 6;

mi c2(mi x) { return x * (x - 1) * i2; }
mi c3(mi x) { return x * (x - 1) * (x - 2) * i6; }

mi f[N];
mi g[N]; 
mi p[N];
mi q[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    
    g[0] = 1;
    p[0] = 1;
    q[0] = 0;
    
    for (int i = 1; i < N; ++i) {
        g[i] += g[i - 1]; // 1, 1 max

        g[i] += g[i - 1] * (i >= 2 ? p[i - 2] : 0); // 2, 1 max
        g[i] += c2(g[i - 1]) + g[i - 1]; // 2, 2, max

        q[i] = q[i - 1]+ c2(g[i - 1]) + g[i - 1] + g[i - 1] * (i >= 2 ? p[i - 2] : 0);
        p[i] = p[i - 1] + g[i]; 
    }
    
    mi b = (n >= 2 ? p[n - 2] : 0);
    
    mi ans = 0;
    
    ans += g[n - 1]; // 1, 1 max
    
    ans += g[n - 1] * b; // 2, 1 max
    ans += c2(g[n - 1]) + g[n - 1]; // 2, 2 max

    ans += g[n - 1] * (c2(b) + b); // 3, 1 max
    ans += (c2(g[n - 1]) + g[n - 1]) * b; // 3, 2 max
    ans += c3(g[n - 1]) + c2(g[n - 1]) * 2 + g[n - 1]; // 3, 3 max

    ans *= 2;
    ans -= 1;

    for (int i = 1; i <= n - 2; ++i) {
        auto get = [&](int sz) -> mi {
            return c2(g[sz - 1]) + g[sz - 1] + g[sz - 1] * (sz >= 2 ? p[sz - 2] : 0);
        };
        ans += get(i) * q[n - 1 - i];
 
    }
    cout << ans << '\n';

    return 0;
}

/**
 * DAG
 * There has to be a "root"
 * rooting of the tree matters
 * it's not divisible by 2 cause orientation is annoying 
 * The root is unique with a set of edges
 * let's say f(n) is number of trees
 * is multiplying by 2 bad for each root?
 * i think only case is line
 * to prove, say there are at least 3 leaves, then we count the number of distinct rooting 
 * positions for isomorphism, then one way yields leaf sinks, 1 source, or 1 sink, leaf sources
 * in both positions there must be onlhy onne sink and one source
 * therefore two leaves
 * so just multiply by 2 and subtract 1 at the end, that takes care of that i hope
 * max depth is exactly n 
 * N = g(n - 1) 
 * (N choose 3) + (N choose 2) * 2 + (N choose 1)
 * g(n) is number of labeled "at most binary trees" of maximum depth n
 * case work on number at max depth
 * g(n) = g(n-1) + g(n-1)
 */