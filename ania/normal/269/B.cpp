#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int maxn = 5050;
int n,m;
pair<double,int> t[maxn];
int dp[maxn][maxn];
int suff[maxn][maxn];
vector<int> v[maxn];

int main() {
    scanf("%d%d", &n, &m);
    FOR(i,n) {
        scanf("%d%lf", &t[i].se, &t[i].fi);
        t[i].se--;
    }
    sort(t,t+n);
    FOR(i,n) {
        v[t[i].se].push_back(i);
    }
    /*
    FOR(i,m) {
        printf("%d: ", i);
        FOR(j,v[i].size()) {
            printf("%d, ", v[i][j]);
        }
        printf("\n");
    }
    */
    FOR(r, m) {
        suff[r][n] = 0;
        for (int p = n-1; p >= 0; p--) {
            suff[r][p] = suff[r][p+1] + (t[p].se <= r);
        }
    }
    FOR(r,m) {
        FOR(p,n) {
            int ex = 0;
            if (r == 0) {
                continue;
            }
            FOR(i,v[r].size()) {
                if (v[r][i] > p) {
                    break;
                } else {
                    ex++;
                }
            }
            dp[r][p] = ex + dp[r-1][p];
            FOR(i,v[r].size()) if (v[r][i] <= p) {
                //printf("dp = %d, 2i = %d, p = %d, v = %d, ex = %d\n", dp[r-1][v[r][i]-1], 2*i, p, v[r][i], ex);
                dp[r][p] = min(dp[r][p], dp[r-1][v[r][i]-1] + i + suff[r-1][v[r][i]+1] - suff[r-1][p+1]);
            }
            //printf("dp[%d][%d] = %d\n", r, p, dp[r][p]);
        }
    }
    printf("%d\n", dp[m-1][n-1]);
	return 0;
}