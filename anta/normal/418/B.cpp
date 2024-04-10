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

int x[100], k[100];
int g[100];
ll dp[1<<20];
int main() {
    int n, m, b;
    scanf("%d%d%d", &n, &m, &b);
    rep(i, n) {
        int mm;
        scanf("%d%d%d", &x[i], &k[i], &mm);
        g[i] = 0;
        rep(j, mm) {
            int p;
            scanf("%d", &p), p --;
            g[i] |= 1 << p;
        }
    }
    vpii perm(n);
    rep(i, n) perm[i] = mp(k[i], i);
    sort(all(perm));
    mset(dp, INF);
    ll ans = INFL;
    dp[0] = 0;
    rep(ii, n) {
        int i = perm[ii].second, kk = perm[ii].first;
        int xx = x[i], gg = g[i];
        for(int j = (1<<m)-1; j >= 0; j --)
            amin(dp[j | gg], dp[j] + xx);
        amin(ans, dp[(1 << m) - 1] + (ll)b * kk);
    }
    if(ans == INFL) puts("-1");
    else cout << ans << endl;
    return 0;
}