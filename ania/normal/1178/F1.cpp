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

const int N = 555;
const int mod = 998244353;

int n,m;
int c[N];

int dp[N][N];

int main() {
	scanf("%d%d", &n, &m);
	FOR(i,m) scanf("%d", &c[i]);
	
	FOR(i,n+2) dp[i][i+1] = dp[i][i] = 1;
	
	for (int l = 2; l <= n; l++) {
		for (int a = 0; a+l <= n; a++) {
			int b = a+l;
			int pos = a;
			for (int i = a; i < b; i++) if (c[i] < c[pos]) pos = i;
			ll sum_le = 0, sum_ri = 0;
			for (int i = a; i <= pos; i++) {
				sum_le += 1LL * dp[a][i] * dp[i][pos] % mod;
			}
			for (int j = pos+1; j <= b; j++) {
				sum_ri += 1LL * dp[pos+1][j] * dp[j][b] % mod;
			}
			sum_le %= mod;
			sum_ri %= mod;
			dp[a][b] = (1LL * sum_le * sum_ri + dp[a][b]) % mod;
		}
	}
	
	printf("%d\n", dp[0][n]);
	return 0;
}