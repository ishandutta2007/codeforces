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

const int N = 5050;
const int mod = 1000000007;

int n;
char s[N];
int cc[2][N];
int dp[N][33];
int t[N];

void test() {
	scanf("%d %s", &n, s);
	cc[0][0]=1;
	for (int nn=1; nn<=n-1; nn++) {
		FOR(k,n) {
			cc[1][k] = cc[0][k-1] + cc[0][k];
			if (cc[1][k] >= mod) cc[1][k] -= mod;
		}
		FOR(k,n) cc[0][k] = cc[1][k];
		//FOR(k,n) printf("%d ", cc[0][k]);
		//printf("\n");
	}
	FOR(i,n) {
		dp[1][s[i]-'a']=1;
		for (int k=2;k<=n;k++) {
			int p=s[i]-'a';
			dp[k][p]=0;
			FOR(c,26) if (c != p) {
				dp[k][p] += dp[k-1][c];
				if (dp[k][p] >= mod) dp[k][p] -= mod;
			}
		}
		//printf("i=%d, s[i]=%c\n", i, s[i]);
		//for (int k=2;k<=n;k++) FOR(c,26) if (dp[k][c]) printf("%d %c %d\n", k, 'a'+c, dp[k][c]);
	}
	FORI(k,n) FOR(c,26) {
		t[k] += dp[k][c];
		if (t[k] >= mod) t[k] -= mod;
	}
	int res=0;
	FORI(k,n) {
		//printf("k=%d, t=%d, c=%d\n", k, t[k], cc[0][k]);
		res += 1LL * t[k] * cc[0][k-1] % mod;
		if (res >= mod) res -= mod;
	}
	printf("%d\n", res);
}

int main() {
	test();
	return 0;
}