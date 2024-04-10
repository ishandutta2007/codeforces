#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3e5 + 7;
const int MX = 998244353;
const LL INF = 1e18 + 9LL;

int n;
int dp[N][3];
vector <int> G[N];

void dfs(int u, int p){
	vector <int> T;
	for(int v: G[u])
		if(v != p)
			T.push_back(v);
	
	for(int v: T)
		dfs(v, u);

	vector <int> pref(T.size() + 2);
	vector <int> suf(T.size() + 2);
	
	pref[0] = 1LL;
	for(int i = 0; i < (int)T.size(); ++i)
		pref[i + 1] = (1LL * pref[i] * (dp[T[i]][2] + dp[T[i]][1]))%MX;
	
	suf[T.size() + 1] = 1LL;
	for(int i = T.size(); i > 0; --i)
		suf[i] = (1LL * suf[i + 1] * (dp[T[i - 1]][2] + dp[T[i - 1]][1]))%MX;
	
	dp[u][0] = pref[T.size()];
	for(int i = 1; i <= (int)T.size(); ++i)
		dp[u][1] = (dp[u][1] + ((1LL * pref[i - 1] * suf[i + 1])%MX) * dp[T[i - 1]][0])%MX;
	
	dp[u][2] = 1;
	for(int v: T)
		dp[u][2] = (1LL * dp[u][2] * dp[v][2])%MX;
	dp[u][2] = (dp[u][2] + dp[u][1])%MX;
	
//	printf("%d :: %d %d %d\n", u, dp[u][0], dp[u][1], dp[u][2]);
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
	printf("%d\n", dp[1][2]);
	return 0;
}