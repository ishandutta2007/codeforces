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

int dp[1001][1001];
int dpp[1001][1001];
int main() {
    int n;
    scanf("%d", &n);
    vector<pair<pii,int> > cp(n);
    rep(i, n) {
        scanf("%d%d", &cp[i].first.first, &cp[i].first.second);
        cp[i].second = i;
    }
    sort(all(cp));
    int k;
    scanf("%d", &k);
    vpii rs(k);
    rep(i, k) {
        scanf("%d", &rs[i].first);
        rs[i].second = i;
    }
    sort(all(rs));
    mset(dp, -1);
    dp[0][0] = 0;
    rep(i, n) {
        int t = lower_bound(all(rs), mp(cp[i].first.first, -1)) - rs.begin();
        int p = cp[i].first.second;
        rep(j, k+1) {
            int x = dp[i][j];
            if(x == -1) continue;
            if(dp[i+1][j] < x) {
                dp[i+1][j] = x;
                dpp[i+1][j] = j;
            }
            int u = max(j, t);
            if(u < k && dp[i+1][u+1] < x + p) {
                dp[i+1][u+1] = x + p;
                dpp[i+1][u+1] = j;
            }
        }
    }
    int ans = 0;
    rep(j, k+1) amax(ans, dp[n][j]);
    int ii = n, jj = -1;
    rep(j, k+1) if(ans == dp[n][j]) {
        jj = j;
        break;
    }
    vector<pii> v;
    while(ii > 0) {
        int nj = dpp[ii][jj];
        if(nj != jj)
            v.push_back(mp(cp[ii-1].second, rs[jj-1].second));
        ii --; jj = nj;
    }
    sort(all(v));
    printf("%d %d\n", (int)v.size(), ans);
    rep(i, v.size())
        printf("%d %d\n", v[i].first + 1, v[i].second + 1);
    return 0;
}