#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PII pair <int, int>

const int N = 2e5 + 7;
const int T = 3 * N + 9;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n;
int cnt, cycles;

int vis[N];
bool inCycle[N];
vector <int> G[N];
vector <int> V[N];

void dfs(int u){
	vis[u] = cnt;
	for(int v: G[u])
		if(vis[v] == 0){
			dfs(v);
			inCycle[u] = inCycle[v];
		}
		else if(vis[v] == cnt)
			cycles++,
			inCycle[u] = true;
		else
			inCycle[u] = inCycle[v];
}

void dfs2(int u){
	++cnt;
	vis[u] = 1;
	for(int v: V[u])
		if(vis[v] == 0)
			dfs2(v);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		if(u == v)	
			cycles--;

		G[u].pb(v);
		V[u].pb(v), V[v].pb(u);
	}
	
	for(int i = 1; i <= 2 * n; ++i)
		if(vis[i] == 0)
			++cnt, dfs(i);
	
	int res = 1;
	for(int i = 1; i <= cycles; ++i)
		res = (res * 2)%MX;

	for(int i = 1; i <= 2 * n; ++i)
		vis[i] = 0;
	
	for(int i = 1; i <= 2 * n; ++i)
		if(!inCycle[i] && vis[i] == 0)
			cnt = 0,
			dfs2(i),
			res = (1LL * res * cnt)%MX;
	printf("%d\n", res);
	return 0;
}