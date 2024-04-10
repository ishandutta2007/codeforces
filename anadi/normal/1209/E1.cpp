#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 15;
const int M = 2007;
const int MASK = 1 << 12;

int n, m;
int in[N][M];

PII id[N];
int col[N][N];

int dp[MASK];
int tmp[MASK];
int best[N][MASK];

void solve(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &in[i][j]);
	
	for(int i = 1; i <= m; ++i){
		id[i] = {0, i};
		for(int j = 1; j <= n; ++j)
			id[i].st = max(id[i].st, in[j][i]);
	}
	
	sort(id + 1, id + m + 1);
	reverse(id + 1, id + m + 1);

	m = min(m, n);
	for(int i = 1; i <= m; ++i){
		int t = id[i].nd;
		for(int j = 0; j < n; ++j)
			col[i][j] = in[j + 1][t];
	}
	
	int mask = 1 << n;
	for(int i = 1; i <= m; ++i){
		for(int j = 0; j < mask; ++j)
			best[i][j] = 0;

		for(int j = 0; j < n; ++j){
			for(int k = 0; k < mask; ++k)
				tmp[k] = 0;
			
			for(int k = 1; k < mask; ++k){
				int id = __builtin_ctz(k);
				tmp[k] = tmp[k ^ (1 << id)];

				id = (id + j) % n;
				tmp[k] += col[i][id];
				best[i][k] = max(best[i][k], tmp[k]);
			}
		}
	}
	
	for(int i = 0; i < mask; ++i)
		dp[i] = 0;
	
	for(int i = 1; i <= m; ++i){
		for(int j = 0; j < mask; ++j)
			tmp[j] = 0;
		
		for(int j = 0; j < mask; ++j){
			tmp[j] = dp[j];
			for(int k = j; k > 0; k = (k - 1) & j)
				tmp[j] = max(tmp[j], best[i][k] + dp[j ^ k]);
		}
		
		for(int j = 0; j < mask; ++j)
			dp[j] = tmp[j];
	}
	
	printf("%d\n", dp[mask - 1]);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}