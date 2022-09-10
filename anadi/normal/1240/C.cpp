#include <bits/stdc++.h>

using namespace std;

typedef long double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, k;
LL dp[N][2];
vector <PII> G[N];

void dfs(int u, int p){
	LL allSum = 0;
	vector <LL> diffs;

	for(auto v: G[u])
		if(v.st != p){
			dfs(v.st, u);
			allSum += dp[v.st][1];
			diffs.push_back(dp[v.st][1] - v.nd - dp[v.st][0]);
		}
	
	dp[u][0] = dp[u][1] = allSum;
	sort(diffs.begin(), diffs.end());
	
	for(int i = 0; i < k && i < (int)diffs.size(); ++i)
		dp[u][1] -= diffs[i];
	
	for(int i = 0; i < k - 1 && i < (int)diffs.size() && diffs[i] < 0; ++i)
		dp[u][0] -= diffs[i];
	dp[u][1] = max(dp[u][0], dp[u][1]);
}

void solve(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		G[i].clear(), dp[i][0] = dp[i][1] = 0;

	for(int i = 1; i < n; ++i){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	
	dfs(1, 0);
	printf("%lld\n", dp[1][1]);
}

int main(){
	int quest;
	scanf("%d", &quest);
	
	while(quest--)
		solve();
	return 0;
}