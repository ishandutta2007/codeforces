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

const int mod = 1000000007;

int n,m,x;
vector<vi> dp[2];

int dpn() {
	FOR(i,2) dp[i].resize(n+2, vi(n+2,0));
	dp[0][n][0]=1;
	FOR(i,m) {
		FOR(j,n+1) FOR(k,n+1) {
			dp[1][j][k] = k==0 ? 0 : dp[0][j+1][k-1];
			dp[1][j][k] += dp[0][j+1][k];
			if (dp[1][j][k] >= mod) dp[1][j][k] -= mod;
			if (i!=x) {
				dp[1][j][k] += dp[0][j][k+1];
				if (dp[1][j][k] >= mod) dp[1][j][k] -= mod;
				dp[1][j][k] += dp[0][j][k];
				if (dp[1][j][k] >= mod) dp[1][j][k] -= mod;
			}
		}

		FOR(j,n+1) FOR(k,n+1) dp[0][j][k] = dp[1][j][k];
	}
	FORI(i,n) dp[0][0][0] = 1LL*dp[0][0][0]*i%mod;
	return dp[0][0][0];
}

int dpm() {
	return 0;
}

int main() {
	scanf("%d%d%d", &n, &m, &x);
	x--;
	printf("%d\n", n<=m ? dpn() : 0);
	return 0;
}