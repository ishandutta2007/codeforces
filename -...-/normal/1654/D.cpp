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

#define runSieve
const int N=1000005;
bool prime[N];
ll pf[N];
void sieve()
{
    int k=sqrt(N-2);
    for(int i=1;i<=N-2;++i)
        prime[i]=true;
    for(int i=2;i<=k;++i)
    {
        if(prime[i])
        {
            for(int k=i*i;k<=N-2;k+=i)
            {
                prime[k]=false;
                pf[k]=i;
            }
        }
    }
}

    
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


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<vector<array<int, 3>>> g(n + 1);
    for(int i=1;i<=n-1;++i) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        g[x].push_back({y, b, a});
        g[y].push_back({x, a, b});
    }
    vector<int> num(n + 1, 0), den(n + 1, 0), f(n + 1, 0);
    vector<int> mp(n + 1, 0);

    vector<vector<pii>> gg(n + 1);

    Mint sum = 0;

    function<void(int, int, Mint)> dfs = [&](int s, int p, Mint u) {
        sum += u;
        // debug(s, f);
        for(auto [v, x, y]:g[s]) {
            if(v == p) {
                continue;
            }
            // x/y
            int xx = x, yy = y;
            while(x > 1 and !prime[x]) {
                int z = pf[x];
                while(x % z == 0) {
                    if(den[z] > 0) {
                        --den[z];
                    }
                    else {
                        ++num[z];
                    }
                    x /= z;
                }
            }
            if(x > 1) {
                if(den[x] > 0) {
                    --den[x];
                }
                else {
                    ++num[x];
                }
            }
            while(y > 1 and !prime[y]) {
                int z = pf[y];
                while(y % z == 0) {
                    if(num[z] > 0) {
                        --num[z];
                    }
                    else {
                        ++den[z];
                        amax(f[z], den[z]);
                    }
                    y /= z;
                }
            }
            if(y > 1) {
                if(num[y] > 0) {
                    --num[y];
                }
                else {
                    ++den[y];
                    amax(f[y], den[y]);
                }
            }
            dfs(v, s, u * Mint(xx) / yy);

            x = xx, y = yy;
            swap(x, y);
            while(x > 1 and !prime[x]) {
                int z = pf[x];
                while(x % z == 0) {
                    if(den[z] > 0) {
                        --den[z];
                    }
                    else {
                        ++num[z];
                    }
                    x /= z;
                }
            }
            if(x > 1) {
                if(den[x] > 0) {
                    --den[x];
                }
                else {
                    ++num[x];
                }
            }
            while(y > 1 and !prime[y]) {
                int z = pf[y];
                while(y % z == 0) {
                    if(num[z] > 0) {
                        --num[z];
                    }
                    else {
                        ++den[z];
                    }
                    y /= z;
                }
            }
            if(y > 1) {
                if(num[y] > 0) {
                    --num[y];
                }
                else {
                    ++den[y];
                }
            }

        }

    };
    dfs(2, 0, 1);
    Mint ans = 1;
    for(int i=2;i<=n;++i) {
        ans *= Mint(i).power(f[i]);
    }
    // debug(ans.val);
    cout << ans * sum << "\n";
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
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}