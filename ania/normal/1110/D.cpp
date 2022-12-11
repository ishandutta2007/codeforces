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

const int N = 1000100;

int dp[N][3][3];
int c[N];

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	FOR(i,n) {
		int a;
		scanf("%d", &a);
		c[a]++;
	}
	for (int k = 1; k <= m; k++) {
		FOR(x,3) FOR(y,3) {
			if (c[k] < x+y) continue;
			if (c[k-1] < y) continue;
			FOR(z,3) {
				if (c[k] < x+y+z) continue;
				if (c[k-1] < y+z) continue;
				if (k>=2 && c[k-2] < z) continue;
				dp[k][x][y] = max(dp[k][x][y], dp[k-1][y][z] + (c[k]-x-y-z) / 3 + z);
			}
		}
	}
	printf("%d\n", dp[m][0][0]);
	return 0;
}