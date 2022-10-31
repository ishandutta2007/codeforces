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

int n, m;
int a[1000][1000];
int dps[4][1000][1000];

void calc(int dp[][1000], int sy, int sx, int dy, int dx) {
    for(int y = sy; 0 <= y && y < n; y += dy)
    for(int x = sx; 0 <= x && x < m; x += dx) {
        int t = 0;
        if(0 <= y-dy && y-dy < n) amax(t, dp[y-dy][x]);
        if(0 <= x-dx && x-dx < m) amax(t, dp[y][x-dx]);
        dp[y][x] = t + a[y][x];
    }
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
    calc(dps[0], 0, 0, 1, 1);
    calc(dps[1], n-1, m-1, -1, -1);
    calc(dps[2], n-1, 0, -1, 1);
    calc(dps[3], 0, m-1, 1, -1);
    int ans = -1;
    reu(y, 1, n-1) reu(x, 1, m-1) {
        //
        {   int t = 0;
            t += dps[0][y-1][x];
            t += dps[1][y+1][x];
            t += dps[2][y][x-1];
            t += dps[3][y][x+1];
            amax(ans, t);
        }
        //
        {   int t = 0;
            t += dps[0][y][x-1];
            t += dps[1][y][x+1];
            t += dps[2][y+1][x];
            t += dps[3][y-1][x];
            amax(ans, t);
        }
    }
    printf("%d\n", ans);
    return 0;
}