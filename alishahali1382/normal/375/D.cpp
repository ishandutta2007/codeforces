#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define pb push_back
const int MAXN = 100010;

int n, m, k, u, v, x, y, t, a, b;
int C[MAXN];
int ans[MAXN];
vector<int> G[MAXN];
vector<pair<int, int>> query[MAXN];
unordered_map<int, int> cnt[MAXN], val[MAXN];

void add(int a, int x, int y){
	for (int i=0; i<y; i++) val[a][++cnt[a][x]]++;
}

void merge(int a, int b){ // a <-- b
	
	if (cnt[a].size()<cnt[b].size()){
		cnt[a].swap(cnt[b]);
		val[a].swap(val[b]);
	}
	for (auto p:cnt[b]) add(a, p.first, p.second);
}

void dfs(int node, int par){
	for (int v:G[node]) if (v!=par){
		dfs(v, node);
		merge(node, v);
	}
	add(node, C[node], 1);
	
	for (auto p:query[node]) ans[p.second]=val[node][p.first];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>C[i];
	for (int i=0; i<n-1; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=m; i++){
		cin>>v>>k;
		query[v].pb({k, i});
	}
	dfs(1, 1);
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}