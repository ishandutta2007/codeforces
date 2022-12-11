#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

double p[22][22], dp[1<<17][17];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) FOR(j,n) scanf("%lf", &p[i][j]);
	n--;
	FOR(m,(1<<n)) FOR(i,n) if (m & (1<<i)) {
		dp[m][i] = 1;
		FOR(j,n) if (m&(1<<j)) dp[m][i] *= p[0][j+1];
		FOR(j,n) if (m&(1<<j)) if (i!=j) {
			dp[m][i] = max(dp[m][i], dp[m^(1<<i)][j]*p[j+1][i+1]+dp[m^(1<<j)][i]*p[i+1][j+1]);
		}
		//printf("dp[%d][%d] = %.5lf\n", m, i, dp[m][i]);
	}
	double res = 0;
	FOR(i,n) res = max(res, dp[(1<<n)-1][i]);
	if (n==0) res=1;
	printf("%.8lf\n", res);
	return 0;
}