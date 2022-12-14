#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int c[maxn];
set<int> ver[maxn], adj[maxn];
map<int, int> last[maxn];

void add(int cmp, int v){
	adj[cmp].insert(v);
}

void merge(int v, int u){
	if (c[v] == c[u])
		return;
	if (ver[c[v]].size() + adj[c[v]].size() > ver[c[u]].size() + adj[c[u]].size())
		swap(v, u);
	int tmp = c[v];
	for (auto it : ver[c[v]]){
		ver[c[u]].insert(it);
		c[it] = c[u];
		if (adj[c[u]].find(it) != adj[c[u]].end())
			adj[c[u]].erase(it);
	}
	ver[tmp].clear();
	for (auto it : adj[tmp])
		if (ver[c[u]].find(it) == ver[c[u]].end())
			adj[c[u]].insert(it);
	adj[tmp].clear();
}

int main(){
	ios_base::sync_with_stdio (false);
	int n, m, C, q;
	cin >> n >> m >> C >> q;
	for (int v = 1; v <= n; v++){
		c[v] = v;
		ver[c[v]].insert(v);
	}
	for (int i = 0; i < m; i++){
		int v, u, x;
		cin >> v >> u >> x;
		if (last[v].count(x))
			merge(u, last[v][x]);
		if (last[u].count(x))
			merge(v, last[u][x]);
		add(c[v], u);
		add(c[u], v);
		last[v][x] = u;
		last[u][x] = v;
	}
	while (q --){
		char type;
		cin >> type;
		if (type == '?'){
			int x, y;
			cin >> x >> y;
			if (ver[c[x]].find(y) != ver[c[x]].end() or adj[c[x]].find(y) != adj[c[x]].end())
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		else{
			int v, u, x;
			cin >> v >> u >> x;
			if (last[v].count(x))
				merge(u, last[v][x]);
			if (last[u].count(x))
				merge(v, last[u][x]);
			add(c[v], u);
			add(c[u], v);
			last[v][x] = u;
			last[u][x] = v;
		}
	}
}