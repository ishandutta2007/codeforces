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
#include <complex>
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
    
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
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

/*
int n;
vector<pii> dbg;
vector<vector<vpii> > dbgs;
void rec(int i, int j) {
    if(i == n) {
        dbgs[j].pb(dbg);
        return;
    }
    vpii choices;
    rer(R, i+1, n) reu(L, 0, i) choices.pb(mp(L,R));
    rep(mask, 1 << choices.size()) {
        rep(k, choices.size()) if(mask >> k & 1)
            dbg.pb(choices[k]);
        rec(n, j);
        rep(k, choices.size()) if(mask >> k & 1)
            dbg.pop_back();
    }
    rer(r, i+1, n) {
        reu(l, i, r) {
            //LR
            //i+1  R  r  Li 
            //R  r  L  i 
            //R  r  l  L
            vpii choices;
            reu(R, i+1, r) reu(L, 0, i) choices.pb(mp(L, R));
            reu(L, 0, i) choices.pb(mp(L, r));
            reu(L, l+1, r) choices.pb(mp(L, r));
            rep(mask, 1 << choices.size()) {
                rep(k, choices.size()) if(mask >> k & 1)
                    dbg.pb(choices[k]);
                dbg.pb(mp(l, -r));
                rec(r, j+1);
                dbg.pop_back();
                rep(k, choices.size()) if(mask >> k & 1)
                    dbg.pop_back();
            }
        }
    }
}
*/

mint dp[501][501];  //,k
mint pow2[501*501];
int main() {
    /*
    n = 4;
    dbgs.resize(100);
    rec(0, 0);
    int cnt = 0;
    rep(kk, dbgs.size()) {
        each(v, dbgs[kk]) {
            cnt ++;
            cerr << kk << ": ";
            each(l, *v) cerr << l->first << "," << l->second << ", ";
            cerr << endl;
        }
    }
    cerr << "cnt: " << cnt << endl;
    */
    int n, k;
    while(~scanf("%d%d", &n, &k)) {
    pow2[0] = 1;
    rer(i, 1, n*n) pow2[i] = pow2[i-1] * 2;
    mset(dp, 0);
    dp[0][0] = 1;
    //
    rep(i, n) {
        rep(j, k) {
            mint x = dp[i][j];
            if(x.get() == 0) continue;
            rer(r, i+1, n) {
                mint a = 0;
                //\Sigma_
//              int partsx = r * (i+1) - i*i - (r-1) - 1;
//              a += (mint(2) ^ partsx) * (r - i);
//              for(int ii = 0; ii <= (r-1)-i; ii ++) {
//                  int partsz = ii;
//                  a += (mint(2) ^ partsz);
//              }
                a = pow2[r-i]-1;
                int partsy = r * (i+1) - i*i - (r-1) - 1;
                a *= pow2[partsy];
                dp[r][j+1] += a * x;
                /*
                reu(l, i, r) {
                    //LR
                    //i+1  R  r  Li 
                    //R  r  L  i 
                    //R  r  l  L
//                  int part1 = 0, part2 = 0, part3 = 0;
//                  part1 = (r - (i+1)) * i;
//                  part2 = i;
//                  part3 = r - (l+1);
                    int parts = r * (i+1) - i*i - l - 1;
                    mint a = mint(2) ^ parts;
                    dp[r][j+1] += a * x;
                }
                */
            }
        }
        //
        //LR
        //i+1  R  n  L  i
        int part1 = 0;
        rer(R, i+1, n) reu(L, 0, i) part1 ++;
        mint a = mint(2) ^ part1;
        dp[n][k] += a * dp[i][k];
    }
    mint ans = dp[n][k];
    printf("%d\n", ans.get());
    }
    return 0;
}