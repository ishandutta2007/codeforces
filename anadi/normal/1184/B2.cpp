#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 107;
const int NN = 1007;
const int INF = 1e9 + 7;

int n, m;
int dist[N][N];

int s, b, k, h;
vector <int> G[NN];
int adj[NN], adj2[NN];

int d[NN];
bool vis[NN];
queue <int> Q;

int pl2[NN], def[NN];
int pl1[NN], att[NN], fuel[NN];

bool dfs(int u){
	vis[u] = true;
	for(int v: G[u])
		if(adj2[v] == 0){
			adj2[v] = u;
			adj[u] = v;
			return true;
		}
		else if(d[adj2[v]] == d[u] + 1 && !vis[adj2[v]] && dfs(adj2[v])){
			adj[u] = v;
			adj2[v] = u;
			return true;
		}
		
	return false;
}

int matching(){
	while(true){
		for(int i = 1; i <= s; ++i)
			if(adj[i])
				d[i] = -1;
			else
				d[i] = 0, Q.push(i);

		while(!Q.empty()){
			int u = Q.front();
			Q.pop();
			
			for(int v: G[u]){
				int tv = adj2[v];
				if(tv == 0)	continue;
				if(d[tv] == -1){
					d[tv] = d[u] + 1;
					Q.push(tv);
				}
			}
		}
			
		for(int i = 1; i <= s; ++i)
			vis[i] = false;
		
		bool ok = false;
		for(int i = 1; i <= s; ++i)
			if(d[i] == 0)
				ok |= dfs(i);
		
		if(!ok)	break;
	}
	
	int ans = 0;
	for(int i = 1; i <= s; ++i)
		ans += adj[i] > 0;
	return ans;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			dist[i][j] = i == j ? 0 : INF;
	
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		if(u == v)	continue;
		dist[u][v] = dist[v][u] = 1;
	}
	
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	scanf("%d %d %d %d", &s, &b, &k, &h);
	for(int i = 1; i <= s; ++i)
		scanf("%d %d %d", &pl1[i], &att[i], &fuel[i]);
	for(int i = 1; i <= b; ++i)
		scanf("%d %d", &pl2[i], &def[i]);
	
	for(int i = 1; i <= s; ++i)
		for(int j = 1; j <= b; ++j)
			if(att[i] >= def[j] && dist[pl1[i]][pl2[j]] <= fuel[i])
				G[i].push_back(j);
	
	int t = matching();
	LL ans = min(1LL * t * k, 1LL * h * s);
	printf("%lld\n", ans);
	return 0;
}