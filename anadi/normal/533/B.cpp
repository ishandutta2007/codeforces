#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int val[N];
LL dp[N][2];
vector <int> G[N];

void dfs(int u){
	dp[u][1] = -INF;
	for(int v: G[u]){
		dfs(v);
		LL nd = max(dp[u][0] + dp[v][0], dp[u][1] + dp[v][1]);
		LL nd2 = max(dp[u][1] + dp[v][0], dp[u][0] + dp[v][1]);
		
		dp[u][0] = nd;
		dp[u][1] = nd2;
	}
	
	dp[u][1] = max(dp[u][1], dp[u][0] + val[u]);
//	printf("%d :: %lld %lld\n", u, dp[u][0], dp[u][1]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int p;
		scanf("%d %d", &p, &val[i]);
		if(p != -1)
			G[p].push_back(i);
	}
	
	dfs(1);
	printf("%lld\n", max(dp[1][0], dp[1][1]));
	return 0;
}