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

int a[100000], b[100000];
int dp[2][301];
int main() {
    //10^3<=e, s<=3*10^5 300
    //DP[i][x] = aixb
    int n, m, s, e;
    scanf("%d%d%d%d", &n, &m, &s, &e);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, m) scanf("%d", &b[i]);
    vector<vi> poses(100001);
    rep(i, m) poses[b[i]].pb(i);
    int maxx = s / e;
    int ans = 0;
    mset(dp, INF);
    dp[0][0] = 0;
    rer(i, 0, n) {
        rer(x, 0, maxx) {
            int j = dp[i&1][x];
            if(j == INF) continue;
            int num = i + j;
            if(x * e + num <= s)
                amax(ans, x);
        }
        if(i < n) {
            const vi &v = poses[a[i]];
            mset(dp[i+1&1], INF);
            rer(x, 0, maxx) {
                int j = dp[i&1][x];
                if(j == INF) continue;
                amin(dp[i+1&1][x], j);
                //ja[i]
                vector<int>::const_iterator it = lower_bound(all(v), j);
                if(x < maxx && it != v.end())
                    amin(dp[i+1&1][x+1], *it+1);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}