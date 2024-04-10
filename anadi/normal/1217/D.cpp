#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5007;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, m;
int s[N], e[N];

int ans[N];
bool vis[N];
vector <int> G[N];

int cnt;
int nr[N];

void dfs(int u){
	vis[u] = true;
	for(auto v: G[u]){
		int nxt = e[v];
		if(ans[v] == 0 && !vis[nxt])
			dfs(nxt);
	}
	
	nr[u] = ++cnt;
}

bool solve(int curVal){
	for(int i = 1; i <= n; ++i)
		nr[i] = 0, vis[i] = false;
	cnt = 0;
	
	bool isZero = false;
	for(int i = 1; i <= m; ++i)
		isZero |= ans[i] == 0;
	
	if(!isZero)
		return true;
	
	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			dfs(i);
	
	for(int i = 1; i <= m; ++i)
		if(ans[i] == 0 && nr[e[i]] < nr[s[i]])
			ans[i] = curVal;
	return false;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d %d", &s[i], &e[i]);
		G[s[i]].push_back(i);
	}
	
	int ret = 0;
	while(true){
		if(solve(ret + 1))
			break;
		++ret;
	}
	
	printf("%d\n", ret);
	for(int i = 1; i <= m; ++i)
		printf("%d ", ans[i]);
	return 0;
}