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
#include <list>
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
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

#define RSUM_MAXN 40
struct RectangeSum {
    typedef short Sum;
    Sum sum[RSUM_MAXN+1][RSUM_MAXN+1];
    template<typename T, unsigned W>
    void init(int h, int w, T a[][W]) {
        rer(y, 0, h) rer(x, 0, w) sum[y][x] = (y == 0 || x == 0) ? 0 :
            sum[y-1][x] + sum[y][x-1] - sum[y-1][x-1] + a[y-1][x-1];
    }
    //[l, r), [t, b)
    inline Sum get(int t, int l, int b, int r) {
        return sum[b][r] - sum[b][l] - sum[t][r] + sum[t][l];
    }
};
char a[40][41];
RectangeSum sum;
int memo[41][41][41][41];

int rec(int t, int l, int b, int r) {
    if(t>=b||l>=r) return 0;
    int &res = memo[t][l][b][r];
    if(res != -1) return res;
    res = 0;
    if(sum.get(t, l, b, r) == 0) {
        res ++;
//      cerr << t << ", " << l << ", "<< b << ", " <<r << endl;
    }
    rep(i, 1<<4) if(i) {
        int tt = t, ll = l, bb = b, rr = r;
        if(i >> 0 & 1) tt ++;
        if(i >> 1 & 1) ll ++;
        if(i >> 2 & 1) bb --;
        if(i >> 3 & 1) rr --;
        bool parity = false;
        rep(j, 4) parity ^= i >> j & 1;
        res += (parity ? 1 : -1) * rec(tt, ll, bb, rr);
    }
    return res;
}

int main() {
    int n, m, Q;
    scanf("%d%d%d", &n, &m, &Q);
    rep(i, n) {
        scanf("%s", a[i]);
        rep(j, m) a[i][j] -= '0';
    }
    sum.init(n, m, a);
    mset(memo, -1);
    rep(i, Q) {
        int t, l, b, r;
        scanf("%d%d%d%d", &t, &l, &b, &r);
        t --, l --;
        printf("%d\n", rec(t, l, b, r));
    }
    return 0;
}