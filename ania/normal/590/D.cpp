#include<bits/stdc++.h>

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
#define REMIN(x,y) x = min(x,y);

const int inf = 1000100100;

int n,k,s;
int dp[2][166][12000];
int a[166];

int main() {
	scanf("%d%d%d", &n, &k, &s);
	FOR(i,n) scanf("%d", &a[i]);
	s = min(s, n*(n+1)/2);
	FORI(i,k) FOR(j,s+1) dp[0][i][j]=inf;
	FOR(i,k+1) FOR(j,s+1) dp[1][i][j]=inf;
	for (int p=n-1; p>=0; p--) {
		FOR(i,k+1) FOR(j,s+1) {
			REMIN(dp[1][i+1][j], dp[0][i][j]+a[p]);
			REMIN(dp[1][i][j+i], dp[0][i][j]);
			//printf(">>dp[%d][%d][%d] = %d\n", p, i, j, dp[0][i][j]);
		}
		FOR(i,k+1) FOR(j,s+1) {
			dp[0][i][j] = dp[1][i][j];
			dp[1][i][j] = inf;
			//printf("dp[%d][%d][%d] = %d\n", p+1, i, j, dp[0][i][j]);
		}
	}
	int res = inf;
	FOR(i,s+1) REMIN(res, dp[0][k][i]);
	printf("%d\n", res);
	return 0;
}