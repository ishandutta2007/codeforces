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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
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
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

int powmod(ll x, ll y, int MOD) {
    ll a = x % MOD, b = 1 % MOD;
    while(y) {
        if(y & 1) {
            (b *= a) %= MOD;
        }
        (a *= a) %= MOD;
        y >>= 1;
    }
    return (int)b;
}
const int PRIMEFACTORIZES_MAXN = 211111;
int primeFactor[PRIMEFACTORIZES_MAXN+1];
void primeFactorizes() {
    primeFactor[1] = 1;
    rer(i, 2, PRIMEFACTORIZES_MAXN) if(!primeFactor[i]) {
        primeFactor[i] = i;
        if((ll)i * i <= PRIMEFACTORIZES_MAXN)
        for(int j = i * i; j <= PRIMEFACTORIZES_MAXN; j += i) {
            if(!primeFactor[j]) primeFactor[j] = i;
        }
    }
}

int main() {
    int n, MOD;
    scanf("%d", &n);
    static int a[111111], b[111111];
    rep(i, n) scanf("%d", &a[i]);
    rep(i, n) scanf("%d", &b[i]);
    scanf("%d", &MOD);
    map<int, int> c; int d = 0;
    rep(i, n) c[a[i]] ++, c[b[i]] ++;
    rep(i, n) if(a[i] == b[i]) d ++;
    static int f[211111];
    each(i, c) {
        f[1] ++;
        f[i->second+1] --;
    }
    rer(i, 1, 210000) f[i] += f[i-1];
    primeFactorizes();
    static ll g[211111];
    rer(i, 1, 210000) {
        int x = i;
        while(x != 1) {
            g[primeFactor[x]] += f[i];
            x /= primeFactor[x];
        }
    }
    g[2] -= d;
    ll r = 1;
    rer(i, 1, 210000) if(primeFactor[i] == i) {
        (r *= powmod(i, g[i], MOD)) %= MOD;
    }
    printf("%I64d\n", r);
    return 0;
}