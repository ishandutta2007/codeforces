#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
const int maxn = 3e5 + 10;
const int mod = 1e9 + 7;

vector <int> t[maxn];

int diam[maxn];

int par[maxn];

int get_par(int v){
	return par[v] < 0 ? v : par[v] = get_par(par[v]);
}

bool visited[maxn];

int idx;

void dfs(int v, int root, int h = 0, int par = -1){
	visited[v] = 1;
	if (h > diam[root]){
		diam[root] = h;
		idx = v;
	}
	for (auto u : t[v]){
		if (u != par){
			dfs(u, root, h + 1, v);
		}
	}
}

void find_diameter(int v){
	idx = v;
	dfs(v, get_par(v));
	dfs(idx, get_par(v));
}

void merge(int v, int u){
	par[u] = v;
	diam[v] = max(max(diam[v], diam[u]), (diam[v] + 1) / 2 + (diam[u] + 1) / 2 + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	
	memset(par, -1, sizeof par);
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		par[get_par(v)] = get_par(u);

		t[v].push_back(u);
		t[u].push_back(v);
	}
	
	for (int v = 1; v <= n; v++){
		if (!visited[v]){
			find_diameter(v);
		}
	}
	
	for (int i = 0; i < q; i++){
		int type;
		cin >> type;
		if (type == 1){
			int v;
			cin >> v;
			v = get_par(v);
			cout << diam[v] << '\n';
		}
		else{
			int v, u;
			cin >> v >> u;
			v = get_par(v), u = get_par(u);
			if (v == u)
				continue;
			merge(v, u);
		}
	}
}