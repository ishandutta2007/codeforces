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
int id[N];
vector <int> G[N], R[N];

int cnt;
bool vis[N];
bool good[N];
vector <int> ord;

void clear(){
	cnt = 0;
	ord.clear();
	
	for(int i = 1; i <= n; ++i){
		good[i] = vis[i] = false;
		G[i].clear(), R[i].clear();
	}
}

void dfs(int u){
	vis[u] = true;
	for(auto v: G[u])
		if(!vis[v])
			dfs(v);
	ord.push_back(u);
}

void dfsR(int u){
	vis[u] = true;
	id[u] = cnt;
	
	for(auto v: R[u])
		if(!vis[v])
			dfsR(v);
}

void solve(){
	scanf("%d %d", &n, &m);
	clear();

	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);

		G[u].push_back(v);
		R[v].push_back(u);
	}
	
	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			dfs(i);
	
	for(int i = 1; i <= n; ++i)
		vis[i] = false;
	reverse(ord.begin(), ord.end());
	
	for(auto v: ord)
		if(!vis[v]){
			++cnt;
			dfsR(v);
		}
	
	if(cnt == 1){
		puts("No");
		return;
	}

	for(int i = 1; i <= cnt; ++i)
		good[i] = true;

	int goodID = -1;
	for(int i = 1; i <= n; ++i){
		for(auto v: G[i])
			if(id[v] != id[i])
				good[id[i]] = false;
	}
	
	for(int i = 1; i <= n; ++i)
		if(good[i])
			goodID = i;
	
	assert(goodID != -1);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(id[i] == goodID)
			++ans;
	
	puts("Yes");
	printf("%d %d\n", ans, n - ans);
	for(int i = 1; i <= n; ++i)
		if(id[i] == goodID)
			printf("%d ", i);
	puts("");
	for(int i = 1; i <= n; ++i)
		if(id[i] != goodID)
			printf("%d ", i);
	puts("");
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}