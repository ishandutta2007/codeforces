#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 87;
const int inf = 1e9 + 7;

int n, k, m;
int cost[N][N];
int dp[N][N][N];

int main(){
	scanf("%d %d %d", &n, &k, &m);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cost[i][j] = i == j ? 0 : inf;
	
	for(int i = 1; i <= m; ++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		cost[a][b] = min(cost[a][b], c);
	}
	
	for(int need = 1; need <= k; ++need)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dp[need][i][j] = inf;
	
	for(int i = 1; i <= n; ++i)
		dp[1][i][i] = 0;
	
	for(int i = 2; i <= k; ++i){
		for(int l = i - 1; l < n; ++l)
			for(int j = 1; j + l <= n; ++j){
				if(cost[j][j + l] < inf)
					for(int v = j + 1; v <= j + l; ++v)
						dp[i][j][j + l] = min(dp[i][j][j + l], dp[i - 1][j + l][v] + cost[j][j + l]);
				
				for(int v = j + 1; v <= j + l; ++v)
					dp[i][j][j + l] = min(dp[i][j][j + l], dp[i - 1][v][j + l] + cost[j][v]);
				
				if(cost[j + l][j] < inf)
					for(int v = j; v < j + l; ++v)
						dp[i][j + l][j] = min(dp[i][j + l][j], dp[i - 1][j][v] + cost[j + l][j]);
				
				for(int v = j; v < j + l; ++v)
					dp[i][j + l][j] = min(dp[i][j + l][j], dp[i - 1][v][j] + cost[j + l][v]);
			}
	}
	
	int res = inf;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			res = min(res, dp[k][i][j]);

	if(res == inf)	puts("-1");
	else	printf("%d\n", res);
	return 0;
}