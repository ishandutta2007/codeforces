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
typedef ModInt<1000000007> mint;

const int Alphabets = 20;       //
const int AlphabetBase = 0; //
struct PMA {
    PMA *fail;
    PMA *next[Alphabets];
    int acceptvalue;
    PMA(): fail(NULL), acceptvalue(0) { mset(next, 0); }
};
PMA PMAs[201];
int nPMAs;
PMA *buildPMA(const vi p[], int v[], int ps) {
    nPMAs = 0;
    PMA *root = new(&PMAs[nPMAs++])PMA;
    for(int i = 0; i < ps; ++i) {
        PMA *t = root;
        rep(j, p[i].size()) {
            int c = p[i][j] - AlphabetBase;
            if(t->next[c] == NULL) t->next[c] = new(&PMAs[nPMAs++])PMA;
            t = t->next[c];
        }
        t->acceptvalue += v[i];
    }
    queue<PMA*> Q;
    rep(c, Alphabets) {
        if(root->next[c]) {
            root->next[c]->fail = root;
            Q.push(root->next[c]);
        }else root->next[c] = root;
    }
    while(!Q.empty()) {
        PMA *t = Q.front(); Q.pop();
        rep(c, Alphabets) {
            if (t->next[c]) {
                Q.push(t->next[c]);
                PMA *r = t->fail;
                while (!r->next[c]) r = r->fail;
                t->next[c]->fail = r->next[c];
                t->next[c]->acceptvalue += r->next[c]->acceptvalue;
            }
        }
    }
    return root;
}

int x[201]; bool eqok;
int l[201], r[201];
int v[200];
vi ps[201];
mint dp[2][201][501][2][2];
vector<pair<int,int> > pmaNexts[201];

mint solve(const PMA *root, int lrlen, int K) {
    mset(dp, 0);
    bool glt = 0;
    for(int i = lrlen-1; i >= 0; i --) {
        dp[i&1][root - PMAs][K][glt][1] += 1;
        glt |= 0 < x[i];
        mset(dp[i+1&1], 0);
        rep(s, nPMAs) rer(k, 0, K) rep(lt, 2) rep(first, 2) {
            mint t = dp[i&1][s][k][lt][first];
            if(t.get() == 0) continue;
//          cerr << i << ", " << s << ", " << k << ", " << lt << ", " << first << ": " << t.get() << endl;
            int d = x[i];
            each(it, pmaNexts[s]) {
                int e = it->first, ns = it->second;
                if(first == 1 && e == 0) continue;
                if(lt || e <= d) {
                    int nk = k - PMAs[ns].acceptvalue;
                    if(0 <= nk)
                        dp[i+1&1][ns][nk][lt || e < d][0] += t;
                }
            }
        }
    }
    mint res = 0;
    rep(s, nPMAs) rer(k, 0, K) rep(lt, 2) rep(first, 2) {
        if(eqok || lt)
            res += dp[1][s][k][lt][first];
    }
    return res;
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int lrlen = 0;
    {   int len;
        scanf("%d", &len);
        amax(lrlen, len);
        mset(l, 0);
        rep(i, len) scanf("%d", &l[len-1-i]);
    }
    {   int len;
        scanf("%d", &len);
        amax(lrlen, len);
        mset(r, 0);
        rep(i, len) scanf("%d", &r[len-1-i]);
    }
    rep(i, n) {
        int len;
        scanf("%d", &len);
        ps[i].assign(len, -1);
        rep(j, len) scanf("%d", &ps[i][j]);
        scanf("%d", &v[i]);
    }
    PMA *root = buildPMA(ps, v, n);
    rep(i, nPMAs) {
        pmaNexts[i].clear();
        const PMA &p = PMAs[i];
        rep(a, m) {
            const PMA *q = &p;
            while(!q->next[a]) q = q->fail;
            q = q->next[a];
            pmaNexts[i].push_back(mp(a, q - PMAs));
        }
    }
    mint ans = 0;
    rep(i, lrlen+1) x[i] = r[i];
    eqok = true;
    ans += solve(root, lrlen, k);
    rep(i, lrlen+1) x[i] = l[i];
    eqok = false;
    ans -= solve(root, lrlen, k);
    printf("%d\n", ans.get());
    return 0;
}