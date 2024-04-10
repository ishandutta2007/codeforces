#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, ans;
int dp[N][2];
vector <int> G[N];

void make(vector <int> &in){
	sort(in.begin(), in.end());
	reverse(in.begin(), in.end());
}

void dfs(int u, int p){
	vector <int> Free, Taken;
	for(auto v: G[u])
		if(v != p){
			dfs(v, u);
			Free.push_back(dp[v][0]);
			Taken.push_back(max(dp[v][0], dp[v][1]));
		}

	if(Free.size() == 0){
		dp[u][0] = -1;
		dp[u][1] = -1;
		return;
	}

	make(Free);
	make(Taken);
	
	if(Free.size() >= 2){
		ans = max(ans, Free[0] + Free[1] + 1);
		ans = max(ans, Taken[0] + Taken[1] + (int)G[u].size() - 2);
	}
	
	dp[u][0] = max(Taken[0] + (int)G[u].size() - 2, (int)G[u].size() - 2);
	dp[u][1] = Free[0] + 1;

	ans = max(ans, dp[u][0]);
	ans = max(ans, dp[u][1] - 1);
	
//	printf("%d :: %d %d\n", u, dp[u][0], dp[u][1]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0);
	printf("%d\n", ans + 2);
	return 0;
}