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

int n,q;
char a[55][5], b[55][5];
int dp[55][55];

int main() {
	scanf("%d%d", &n, &q);
	FOR(i,q) {
		scanf("%s %s", a[i], b[i]);
	}
	dp[0][0] = 1;
	FOR(i,n-1) FOR(j,6) {
		FOR(k,q) if (b[k][0] == 'a'+j) dp[i+1][a[k][0]-'a'] += dp[i][j];
	}
	int res = 0;
	FOR(j,6) res += dp[n-1][j];
	printf("%d\n", res);
	return 0;
}