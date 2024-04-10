#include <bits/stdc++.h>

using namespace std;

typedef double d;
typedef long long int LL;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define PDD pair <d, d>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e2 + 3;
const LL INF = 100000000000000000LL;

int n, m, k;
int color[N];
LL cost[N][N];
LL dp[N][N][N];
LL mn[N][N][N];
LL minimum[N][2];

void wylicz(int a, int b, bool czy){
	for(int i = 1; i <= k; ++i){
		if(i > a)
			break;
		dp[a][b][i] = min(dp[a - 1][b][i], mn[a - 1][b][i - 1]);
		if(!czy)
			dp[a][b][i] = min(INF, dp[a][b][i] + cost[a][b]);
	}
}

void akt(int a){
	for(int i = 1; i <= k; ++i)
		minimum[i][0] = minimum[i][1] = INF;
	
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= k; ++j)
			if(dp[a][i][j] < minimum[j][0]){
				minimum[j][1] = minimum[j][0];
				minimum[j][0] = dp[a][i][j];
			}
			else if(dp[a][i][j] < minimum[j][1])
				minimum[j][1] = dp[a][i][j];
	
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= k; ++j)
			if(dp[a][i][j] == minimum[j][0])
				mn[a][i][j] = minimum[j][1];
			else
				mn[a][i][j] = minimum[j][0];
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &color[i]);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%I64d", &cost[i][j]);
	
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			for(int ii = 0; ii <= k; ++ii)
				mn[i][j][ii] = dp[i][j][ii] = INF;
	
	for(int i = 1; i <= m; ++i)
		mn[0][i][0] = dp[0][i][0] = 0;
	
	for(int i = 1; i <= n; ++i){
		if(color[i] != 0){
			wylicz(i, color[i], true);
			akt(i);
			continue;
		}
		
		for(int j = 1; j <= m; ++j)
			wylicz(i, j, false);
		akt(i);
	}
	
	LL ans = INF;
	for(int i = 1; i <= m; ++i)
		ans = min(ans, dp[n][i][k]);
	
	ans == INF ? puts("-1") : printf("%I64d\n", ans);
	return 0;
}