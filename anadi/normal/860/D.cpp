#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>
#define PIII pair <int, PII>

const int N = 2e5 + 7;
const int T = 3 * N + 7;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int cnt = 0;

int pre[N];
bool vis[N];
vector <int> G[N];
vector <PIII> res;

bool dfs(int u, int dad){
	pre[u] = ++cnt;
	vis[u] = true;
	vector <int> canUse;

	for(int v: G[u]){
		if(vis[v] && pre[u] < pre[v])
			canUse.pb(v);

		if(!vis[v] && !dfs(v, u))
			canUse.pb(v);
	}
	
	for(int i = 0; i + 1 < (int)canUse.size(); i += 2)
		res.pb({canUse[i], {u, canUse[i + 1]}});

	if((canUse.size() & 1) && dad != 0){
		res.pb({canUse[canUse.size() - 1], {u, dad}});
		return true;
	}
	
	return false;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	
	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			dfs(i, 0);
	
	printf("%d\n", (int)res.size());
	for(int i = 0; i < (int)res.size(); ++i)
		printf("%d %d %d\n", res[i].st, res[i].nd.st, res[i].nd.nd);
	return 0;
}