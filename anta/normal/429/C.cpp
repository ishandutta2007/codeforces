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
#include <limits>
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

int c[24];
int internals;
int idx[11];
char popcnt[1 << 11];

char dp[1<<11][25][25][3];
char dp2[1<<11][25];

char rec2(int bset, int leafs);

char rec(int bset, int leafs, int rem, int cs) {
    char &r = dp[bset][leafs][rem][cs];
    if(r != -1) { if(r == -2) cerr << "Cycle!!!" << endl; return r; }
    if(bset == 0 && leafs == 0 && rem == 0 && cs == 2)
        return r = 1;
    r = -2;
    for(int sset = bset; ; (-- sset) &= bset) {
        int nrem = rem - popcnt[sset];
        for(int x = min(nrem, leafs); x >= 1; x --) {
            if(rec2(sset, x) &&
               rec(bset & ~sset, leafs - x, nrem - x, min(cs + 1, 2)))
                return r = 1;
        }
        if(sset == 0) break;
    }
    return r = 0;
}

char rec2(int bset, int leafs) {
    char &r = dp2[bset][leafs];
    if(r != -1) return r;
    int pcnt = popcnt[bset] + leafs;
    if(pcnt == 1) {
        return r = bset == 0 && leafs == 1;
    }
    rep(i, internals) if(bset >> i & 1) {
        if(c[idx[i]] == pcnt)
            if(rec(bset & ~(1 << i), leafs, pcnt - 1, 0))
                return r = 1;
    }
    return r = 0;
}

int main() {
    //internal node-1
    //(n + 1) / 2 <= leafs
    //n - (n + 1) / 2 >= n - leafs
    //internal node11
    // iff c_i  1
    //
    //bitDP
    int n;
    scanf("%d", &n);
    rep(i, n) scanf("%d", &c[i]);
    int leafs = count(c, c + n, 1);
    if(n - leafs > leafs - 1) {
        puts("NO");
        return 0;
    }
    internals = 0;
    rep(i, n) if(c[i] > 1)
        idx[internals ++] = i;
    rep(i, 1 << internals) {
        int cnt = 0;
        rep(j, internals) {
            if(i >> j & 1) {
                cnt ++;
            }
        }
        popcnt[i] = cnt;
    }
    mset(dp, -1); mset(dp2, -1);
    bool ans = rec2((1 << internals) - 1, leafs) != 0;
    puts(ans ? "YES" : "NO");
    return 0;
}