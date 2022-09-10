#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e5 + 7;
const int M = 1e6 + 7;
const int MX = 1e9 + 7;

int n, m;
int ans[N];
bool vis[N];
vector <PII> G[N];

int cnt;
int val[M];
int edges[M][10];
vector <int> vert[M];

void add(int u, int nr, int v){
	vector <int> who;
	while(nr){
		who.push_back(nr % 10);
		nr /= 10;
	}
	
	while(who.size()){
		int t = who.back();
		if(edges[u][t] == 0){
			edges[u][t] = ++cnt;
			val[cnt] = (10LL * val[u] + t) % MX;
		}
		
		u = edges[u][t];
		who.pop_back();
	}
	
	vert[u].push_back(v);
}

void addEdges(int u, int t){
	for(auto v: G[u]){
		if(vis[v.st])
			continue;
		add(t, v.nd, v.st);
	}
}

void bfs(){
	queue <int> Q;
	Q.push(1);
	
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		for(auto v: vert[u])
			if(!vis[v]){
				vis[v] = true;
				ans[v] = val[u];
				addEdges(v, u);
			}
		
		for(int i = 0; i < 10; ++i)
			if(edges[u][i] > 0)
				Q.push(edges[u][i]);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	
	cnt = 1;
	vert[1].push_back(1);
	
	bfs();
	for(int i = 2; i <= n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}