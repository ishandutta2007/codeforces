#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif

    
// const int MOD = 1000000007;
const int MOD = 998244353;
struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};

#define NCR
const int NC = 1000005;
Mint fac[NC], fac_inv[NC], inv[NC];
void initncr() {
    fac[0] = fac_inv[0] = inv[1] = 1;
    for(int i=2;i<NC;++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i];
    }
    for(int i=1;i<NC;++i) {
        fac[i] = fac[i-1] * i;
        fac_inv[i] = fac_inv[i-1] * inv[i];
    }
}
Mint ncr(int n, int r) {
    if(n < r) {
        return 0;
    }
    return fac[n] * fac_inv[r] * fac_inv[n - r];
}


int _runtimeTerror_()
{
    int n;
    cin >> n;
    int lb = 0, lw = 0, rb = 0, rw = 0, lx = 0, rx = 0;
    Mint cnt = 1;
    Mint ff = 1, gg = 1;
    for(int i=1;i<=n;++i) {
        string s;
        cin >> s;
        lx += s[0] == '?';
        lb += s[0] == 'B';
        lw += s[0] == 'W';
        rx += s[1] == '?';
        rb += s[1] == 'B';
        rw += s[1] == 'W';
        Mint f = 0, g = 0, h = 0;
        for(auto j:{"BW", "WB"}) {
            int match = 0;
            for(int k=0;k<2;++k) {
                match += s[k] == '?' || s[k] == j[k];
            }
            if(match == 2) {
                ++f;
                if(j == "BW") {
                    ++g;
                }
                if(j == "WB") {
                    ++h;
                }
            }
        }
        cnt *= f;
        ff *= g;
        gg *= h;
    }
    cnt -= ff + gg;
    Mint ans = 0;
    for(int i=0;i<=n;++i) {
        // i is white in left
        if(lw > i) {
            continue;
        }
        if(lw + lx < i) {
            continue;
        }
        if(rb > i) {
            continue;
        }
        if(rb + rx < i) {
            continue;
        }
        Mint val = ncr(lx, i - lw);
        val *= ncr(rx, i - rb);
        ans += val;
    }
    cout << ans - cnt << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}