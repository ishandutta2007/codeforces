#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int power(int x, int t)
{
	int ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1LL * ret * x % MOD;
		x = 1LL * x * x % MOD;
		t >>= 1;
	}
	return ret;
}

int n, par[200005];
vector<int> sons[200005];
int dp[200005][3];

void dfs(int v)
{
	rep(i, sons[v].size()) {
		int u = sons[v][i];
		dfs(u);
	}
	
	if(sons[v].empty()) dp[v][2] = 1;
	else {
		dp[v][0] = dp[v][2] = 1;
		rep(i, sons[v].size()) {
			int u = sons[v][i];
			dp[v][0] = 1LL * dp[v][0] * (dp[u][0] + dp[u][2]) % MOD;
			dp[v][1] = (dp[v][1] + 1LL * power((dp[u][0] + dp[u][2]) % MOD, MOD - 2) * (dp[u][1] + dp[u][2])) % MOD;
			dp[v][2] = 1LL * dp[v][2] * (2LL * dp[u][2] + dp[u][0] + dp[u][1]) % MOD;
		}
		dp[v][1] = 1LL * dp[v][1] * dp[v][0] % MOD;
		dp[v][2] = (dp[v][2] - dp[v][0] - dp[v][1] + 2LL * MOD) % MOD;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 2; i <= n; i ++) {
		scanf("%d", &par[i]);
		sons[par[i]].push_back(i);
	}
	dfs(1);
	printf("%d\n", (dp[1][0] + dp[1][2]) % MOD);
	return 0;
}