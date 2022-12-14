#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

vector<int> g[N], t[N], rg[N], bucket[N];
int sdom[N], par[N], dom[N], dsu[N], label[N];
int arr[N], rev[N], Time;

int Find(int u, int x = 0){
	if (u == dsu[u])
		return x ? -1 : u;
	int v = Find(dsu[u], x + 1);
	if (v < 0)
		return u;
	if (sdom[label[dsu[u]]] < sdom[label[u]])
		label[u] = label[dsu[u]];
	dsu[u] = v;
	return x ? v : label[u];
}
void Union(int u,int v){ //Add an edge u-->v
	dsu[v] = u;
}

void dfs(int v){
	arr[v] = ++Time;
	rev[Time] = v;
	label[Time] = sdom[Time] = dsu[Time] = Time; 
	for (auto u : g[v]){	
		if (!arr[u]){
			dfs(u);
			par[arr[u]]=arr[v];
		}
		rg[arr[u]].push_back(arr[v]);
	}
}

void build_dominatortree(int n){
	for (int i = 1; i <= n; i++)
		if (!arr[i])
			dfs(i);
	for (int i = n; i >= 1; i--){
		for (auto j : rg[i])
			sdom[i] = min(sdom[i], sdom[Find(j)]);

		if (i > 1)
			bucket[sdom[i]].push_back(i);

		for (auto w : bucket[i]){
			int v = Find(w);
			if (sdom[v] == sdom[w])
				dom[w] = sdom[w];
			else 
				dom[w] = v;
		}
		if (i > 1)
			Union(par[i], i);
	}
	for (int i = 2; i <= n; i++){
		if (dom[i] != sdom[i])
			dom[i]=dom[dom[i]];
		t[rev[i]].push_back(rev[dom[i]]);
		t[rev[dom[i]]].push_back(rev[i]);
	}
}

vector<pair<int,int>> G[N];
ll dis[N];

void dijkstra(int n){
	memset(dis, 63, sizeof dis);
	dis[1] = 0;
	set<pair<ll,int>> s;
	s.insert({dis[1], 1});
	while (!s.empty()){
		int v = (*s.begin()).second;
		s.erase(s.begin());
		for (auto ed : G[v]){
			int u = ed.first, w = ed.second;
			if (dis[u] > dis[v] + w){
				s.erase({dis[u],u});
				dis[u] = dis[v] + w;
				s.insert({dis[u],u});
			}
		}
	}
	for (int v = 1; v <= n; v++){
		for (auto ed : G[v]){
			int u = ed.first, w = ed.second;
			if (dis[u] == dis[v] + w)
				g[v].push_back(u);
		}
	}
}

int sz[N];

int DFS(int v, int par = -1){
	sz[v] = 1;
	for (auto u : t[v])
		if (u != par)	
			sz[v] += DFS(u, v);
	return sz[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		if (v == s)
			v = 1;
		else if (v == 1)
			v = s;
		if (u == s)
			u = 1;
		else if (u == 1)
			u = s;
		G[v].push_back({u, w});
		G[u].push_back({v, w});
	}
	dijkstra(n);
	build_dominatortree(n);
	DFS(1);
	cout << *max_element(sz + 2, sz + n + 1) << endl;
}