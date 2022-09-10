#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
bool vis[N];
vector <int> G[N];

void dfs(int u){
	vis[u] = true;
	for(auto v: G[u])
		if(!vis[v])
			dfs(v);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int ans = n;
	for(int i = 1; i <= n; ++i)
		if(!vis[i]){
			dfs(i);
			ans--;
		}
	
	printf("%d\n", m - ans);
	return 0;
}