// Har Har Mahadev
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

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif

    
const int MOD=MM;
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


const int N = 1000005;

int rcnt[N],ccnt[N];

int f[N][2][2], g[N][2][2], t[2][2];
int tcnt = 0;

set<pii> ones,zeros;

int _runtimeTerror_()
{
    int n,m,k;
    cin >> n >> m >> k;
    int open_r = n, open_c = m;
    int good_r = 0, good_c = 0;

    auto rm = [&](int x,int y,int v)
    {
        set<int> pos;
        for(int i=0;i<2;++i) {
            for(int j=0;j<2;++j) {
                if(f[x][i][j]) {
                    pos.insert(i^j);
                }
            }
        }
        if(sz(pos) == 1) {
            --good_r;
        }
        --rcnt[x];
        --f[x][y%2][v];
        if(rcnt[x] == 0) {
            ++open_r;
        }
        pos.clear();
        for(int i=0;i<2;++i) {
            for(int j=0;j<2;++j) {
                if(f[x][i][j]) {
                    pos.insert(i^j);
                }
            }
        }
        if(sz(pos) == 1) {
            good_r += 1;
        }

        {
            swap(x,y);
            set<int> pos;
            for(int i=0;i<2;++i) {
                for(int j=0;j<2;++j) {
                    if(g[x][i][j]) {
                        pos.insert(i^j);
                    }
                }
            }
            if(sz(pos) == 1) {
                --good_c;
            }
            --ccnt[x];
            --g[x][y%2][v];
            if(ccnt[x] == 0) {
                ++open_c;
            }
            pos.clear();
            for(int i=0;i<2;++i) {
                for(int j=0;j<2;++j) {
                    if(g[x][i][j]) {
                        pos.insert(i^j);
                    }
                }
            }
            if(sz(pos) == 1) {
                good_c += 1;
            }
        }
        --t[(x+y)%2][v];
    };

    auto add = [&](int x,int y,int v) {
        if(rcnt[x] == 0) {
            --open_r;
        }
        set<int> pos;
        for(int i=0;i<2;++i) {
            for(int j=0;j<2;++j) {
                if(f[x][i][j]) {
                    pos.insert(i^j);
                }
            }
        }
        if(sz(pos) == 1) {
            --good_r;
        }
        ++rcnt[x];
        ++f[x][y%2][v];
        pos.clear();
        for(int i=0;i<2;++i) {
            for(int j=0;j<2;++j) {
                if(f[x][i][j]) {
                    pos.insert(i^j);
                }
            }
        }
        if(sz(pos) == 1) {
            good_r += 1;
        }

        {
            swap(x,y);
            if(ccnt[x] == 0) {
                --open_c;
            }
            set<int> pos;
            for(int i=0;i<2;++i) {
                for(int j=0;j<2;++j) {
                    if(g[x][i][j]) {
                        pos.insert(i^j);
                    }
                }
            }
            if(sz(pos) == 1) {
                --good_c;
            }
            ++ccnt[x];
            ++g[x][y%2][v];
            if(ccnt[x] == 0) {
                ++open_c;
            }
            pos.clear();
            for(int i=0;i<2;++i) {
                for(int j=0;j<2;++j) {
                    if(g[x][i][j]) {
                        pos.insert(i^j);
                    }
                }
            }
            if(sz(pos) == 1) {
                good_c += 1;
            }
        }
        // debug(x,y,v);
        ++t[(x+y)%2][v];
    };

    auto clear = [&](int x,int y)
    {
        if(ones.count({x,y})) {
            ones.erase({x,y});
            --tcnt;
            rm(x,y,1);
        }
        else if(zeros.count({x,y})) {
            zeros.erase({x,y});
            --tcnt;
            rm(x,y,0);
        }
    };

    auto one = [&](int x,int y) {
        if(zeros.count({x,y})) {
            zeros.erase({x,y});
            rm(x,y,0);
            --tcnt;
        }
        if(!ones.count({x,y})) {
            add(x,y,1);
            ++tcnt;
            ones.insert({x,y});
        }
    };

    auto zero = [&](int x,int y) {
        if(ones.count({x,y})) {
            ones.erase({x,y});
            rm(x,y,1);
            --tcnt;
        }
        if(!zeros.count({x,y})) {
            add(x,y,0);
            ++tcnt;
            zeros.insert({x,y});
        }
    };

    auto answer = [&]()
    {
        if(tcnt == 0) {
            Mint ans = Mint(2).power(n) + Mint(2).power(m) - 2;
            return ans;
        }
        Mint ans = 0;
        if(open_r + good_r == n) {
            ans += Mint(2).power(open_r);
        }
        if(open_c + good_c == m) {
            ans += Mint(2).power(open_c);
        }
        set<int> pos;
        for(int i=0;i<2;++i) {
            for(int j=0;j<2;++j) {
                if(t[i][j]) {
                    pos.insert(i^j);
                }
            }
        }
        // debug(pos);
        if(sz(pos) == 1) {
            ans -= 1;
        }
        return ans;
    };

    while(k--) {
        int x,y,t;
        cin >> x >> y >> t;
        if(t == -1) {
            clear(x,y);
        }
        else if(t == 1) {
            one(x,y);
        }
        else {
            zero(x,y);
        }
        // debug(open_r,open_c,good_r,good_c);
        cout << answer() << "\n";
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}