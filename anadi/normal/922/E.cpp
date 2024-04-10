#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 19LL;

int n, W, B, X;
LL dp[N][10 * N];

int cnt[N];
int cost[N];

int main(){
	scanf("%d %d %d %d", &n, &W, &B, &X);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &cnt[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &cost[i]);
	
	int sum = 0;
	dp[1][0] = W;

	for(int i = 1; i <= n; ++i){
		int cur = 1;
		vector <int> r;
		
		int u = cnt[i];
		while(cur <= u){
			r.push_back(cur);
			u -= cur;
			cur *= 2;
		}
		
		if(u > 0)
			r.push_back(u);
		
		for(int j = 1; j <= cnt[i]; ++j)
			dp[i][sum + j] = -INF;
		
		for(int v: r){
			for(int j = sum; j >= 0; --j)
				if(dp[i][j] >= 1LL * v * cost[i])
					dp[i][j + v] = max(dp[i][j] - 1LL * v * cost[i], dp[i][j + v]);
			sum += v;
		}
		
		for(int j = 0; j <= sum; ++j)
			if(dp[i][j] >= 0)
				dp[i + 1][j] = min(dp[i][j] + X, W + 1LL * j * B);
			else
				dp[i + 1][j] = -INF;
		
//		for(int j = 1; j <= sum; ++j)
//			printf("%lld ", dp[i][j]);
//		puts("");
	}
	
	for(int i = sum; i >= 0; --i)
		if(dp[n][i] >= 0){
			printf("%d\n", i);
			return 0;
		}

	return 0;
}