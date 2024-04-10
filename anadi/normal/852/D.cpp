#include <bits/stdc++.h>

using namespace std;

const int N = 607;
const int inf = 1e9 + 7;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

int n, m;
int c, k;
int odl[N];
int city[N];
int d[N][N];
int adj[N][N];
bool visited[N];

queue <int> Q2;
vector <int> V[N];
vector <PII> G[N];
priority_queue <PII> Q;

void dijkstra(int t, int s){
	for(int i = 1; i <= n; ++i)
		d[t][i] = inf,
		visited[i] = false;
	d[t][s] = 0;
	
	Q.push({0, s});
	while(!Q.empty()){
		int u = Q.top().nd;
		Q.pop();
		
		if(visited[u])
			continue;
		visited[u] = true;
		
		for(PII v: G[u])
			if(d[t][v.st] > d[t][u] + v.nd){
				d[t][v.st] = d[t][u] + v.nd;
				Q.push({-d[t][v.st], v.st});
			}
	}
}

bool dfs(int u){
	visited[u] = true;
	for(int v: V[u]){
		int x = adj[v][1];
		if(x == 0){
			adj[u][0] = v;
			adj[v][1] = u;
			return true;
		}
		else if(!visited[x] && odl[x] == odl[u] + 1 && dfs(x)){
			adj[u][0] = v;
			adj[v][1] = u;
			return true;
		}
	}
	
	return false;
}

int matching(){
	int cnt = 0;
	for(int i = 1; i <= c; ++i)
		adj[i][0] = 0;
	for(int i = 1; i <= n; ++i)
		adj[i][1] = 0;
	
	while(true){
		for(int i = 1; i <= c; ++i)
			if(adj[i][0] == 0)
				Q2.push(i),
				odl[i] = 0;
			else
				odl[i] = -1;
		
		while(!Q2.empty()){
			int u = Q2.front();
			Q2.pop();
			
			for(int x: V[u]){
				int v = adj[x][1];
				if(odl[v] == -1){
					odl[v] = odl[u] + 1;
					Q2.push(v);
				}
			}
		}
		
		for(int i = 1; i <= c; ++i)
			visited[i] = false;
		
		bool czy = false;
		for(int i = 1; i <= c; ++i)
			if(odl[i] == 0 && dfs(i))
				++cnt,
				czy = true;
		
		if(!czy)
			break;
	}
	
	return cnt;
}

bool check(int czasik){
	for(int i = 1; i <= c; ++i){
		V[i].clear();
		for(int j = 1; j <= n; ++j)
			if(d[i][j] <= czasik)
				V[i].pb(j);
	}
	
	if(matching() >= k)
		return true;
	return false;
}

int bs(int p, int k){
	while(p < k){
		int m = (p + k) >> 1;
		if(check(m))
			k = m;
		else
			p = m + 1;
	}
	
	return p;
}

int main(){
	scanf("%d %d %d %d", &n, &m, &c, &k);
	for(int i = 1; i <= c; ++i)
		scanf("%d", &city[i]);

	for(int i = 1; i <= m; ++i){
		int u, v, cost;
		scanf("%d %d %d", &u, &v, &cost);
		G[u].pb({v, cost});
		G[v].pb({u, cost});
	}
	
	for(int i = 1; i <= c; ++i)
		dijkstra(i, city[i]);
	
	int x = bs(0, 1731312);
	printf("%d\n", x == 1731312 ? -1 : x);
	return 0;
}