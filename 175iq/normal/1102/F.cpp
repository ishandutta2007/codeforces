#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long li;

const int N = 18;
const int M = 100 * 1000 + 13;
const int INF = 1e9;

int dp[1 << N][N];

int n, m;
int a[N][M];
int mn1[N][N], mn2[N][N];

int calc(int mask, int v){
	if (dp[mask][v] != -1)
		return dp[mask][v];
	dp[mask][v] = 0;
	forn(u, n) if (v != u && ((mask >> u) & 1))
		dp[mask][v] = max(dp[mask][v], min(mn1[u][v], calc(mask ^ (1 << v), u)));
	return dp[mask][v];
}

int main() {
	scanf("%d%d", &n, &m);
	forn(i, n) forn(j, m)
		scanf("%d", &a[i][j]);
	
	forn(i, n) forn(j, n){
		int val = INF;
		forn(k, m)
			val = min(val, abs(a[i][k] - a[j][k]));
		mn1[i][j] = val;
		val = INF;
		forn(k, m - 1)
			val = min(val, abs(a[i][k] - a[j][k + 1]));
		mn2[i][j] = val;
	}
	
	int ans = 0;
	forn(i, n){
		memset(dp, -1, sizeof(dp));
		forn(j, n)
			dp[1 << j][j] = (j == i ? INF : 0);
		forn(j, n)
			ans = max(ans, min(mn2[j][i], calc((1 << n) - 1, j)));
	}
	
	printf("%d\n", ans);
}