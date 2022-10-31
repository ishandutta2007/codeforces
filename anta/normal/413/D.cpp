#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

template<int MOD>
struct ModInt {
    static const int Mod = MOD;
    unsigned x;
    ModInt(): x(0) { }
    ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
    ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
    int get() const { return (int)x; }
    
    ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while(b) {
            long long t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        return ModInt(u);
    }
    
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1;
    while(k) {
        if(k & 1) r *= a;
        a *= a;
        k >>= 1;
    }
    return r;
}
typedef ModInt<1000000007> mint;

mint dp[2001][2][1<<10];
int a[2000];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    rep(i, n) scanf("%d", &a[i]);
    mset(dp, 0);
    if(a[0] == 0 || a[0] == 2) dp[1][0][1 << 0] += 1;
    if(a[0] == 0 || a[0] == 4) dp[1][0][1 << 1] += 1;
    reu(i, 1, n+1) rep(won, 2) rep(seq, 1 << (k-1)) {
        mint x = dp[i][won][seq];
        if(x.get() == 0) continue;
//      cerr << i << ", " << won << ", " << seq << ": " << x.get() << endl;
        if(i == n) continue;
        if(a[i] == 0 || a[i] == 2) {
            int nseq = (seq + 1) & ~(1 << (k-1));
            dp[i+1][won || nseq == 0][nseq] += x;
        }
        if(a[i] == 0 || a[i] == 4) {
            if(seq & 1) {
                dp[i+1][won][1 << 1] += x;
            }else {
                int nseq = (seq + 2) & ~(1 << (k-1));
                dp[i+1][won || nseq == 0][nseq] += x;
            }
        }
    }
    mint ans = 0;
    rep(seq, 1 << (k-1)) ans += dp[n][1][seq];
    printf("%d\n", ans.get());
    return 0;
}