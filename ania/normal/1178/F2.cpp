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
const int M = 1000100;
const int mod = 998244353;

int c[M];
int posl[N];

int dp[N][N];

int rec(int le, int ri) {
	vi t, mul;
	for (int i = le; i < ri; i++) {
		int cur = c[i];
		
		int beg = -1, curmul = 1;
		for (int j = i; j <= posl[cur]; j++) {
			if (c[j] != cur) {
				if (c[j] < c[i]) return 0;
				if (beg == -1) beg = j;
			} else {
				if (beg != -1) {
					int val = rec(beg, j);
					curmul = 1LL * curmul * val % mod;
				}
				beg = -1;
			}
		}
		
		t.pb(cur);
		mul.pb(curmul);
		
		i = posl[cur];
	}
	int n = SZ(t);
	
	FOR(i,n+2) FOR(j,n+2) dp[i][j] = 0;
	FOR(i,n+2) dp[i][i] = 1;
	FOR(i,n) dp[i][i+1] = 1;
	
	for (int l = 2; l <= n; l++) {
		for (int a = 0; a+l <= n; a++) {
			int b = a+l;
			int pos = a;
			for (int i = a; i < b; i++) if (t[i] < t[pos]) pos = i;
			ll sum_le = 0, sum_ri = 0;
			ll mul_all = 1;
			//for (int i = a; i < b; i++) mul_all = 1LL * mul_all * mul[i] % mod;
			for (int i = a; i <= pos; i++) {
				sum_le += 1LL * dp[a][i] * dp[i][pos] % mod;
			}
			for (int j = pos+1; j <= b; j++) {
				sum_ri += 1LL * dp[pos+1][j] * dp[j][b] % mod;
			}
			sum_le %= mod;
			sum_ri %= mod;
			dp[a][b] = (1LL * sum_le * sum_ri % mod * mul_all + dp[a][b]) % mod;
		}
	}
	FOR(i,n) dp[0][n] = 1LL * dp[0][n] * mul[i] % mod;
	
	//printf("rec %d %d = %d\n", le, ri, dp[0][n]);
	return dp[0][n];
}

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	FOR(i,m) scanf("%d", &c[i]);
	
	FOR(i,m) {
		posl[c[i]] = i;
	}
	
	printf("%d\n", rec(0,m));
	return 0;
}