#include <iostream>
#include <vector>
using namespace std;

const int N = 1000 * 1000 + 5;

int st[N], ed[N];
vector <int> adj[N];
vector <pair <int, int> > adj2[N];
vector <int> e[N];
vector <int> vec;
int h[N];
int par[N];
bool mark1[N];
bool mark2[N];
bool mark[N];
int jmp[N];

int get_par(int v) {
	if (par[v] == v) {
		return v;
	}
	return par[v] = get_par(par[v]);
}

void dfs(int v, int pr = 0) {
	mark[v] = true;
	for (auto p : adj2[v]) {
		int u = p.first, e = p.second;
		if (!mark[u]) {
			h[u] = h[v] + 1;
			dfs(u, e);
			jmp[v] = min(jmp[v], jmp[u]);
		}
		else {
			if (e != pr) {
				jmp[v] = min(jmp[v], h[u]);
			}
		}
	}
//	cout << v << " " << pr << " " << h[v] << " " << jmp[v] << endl;
	if (jmp[v] >= h[v]) {
		mark2[pr] = true;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	fill(jmp, jmp + n + 1, N);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		st[i] = u;
		ed[i] = v;
		e[w].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 1; i < N; i++) {
		vec.clear();
		for (auto x : e[i]) {
			int u = st[x], v = ed[x];
			u = get_par(u), v = get_par(v);
			if (u != v) {
				vec.push_back(u);
				vec.push_back(v);
				mark1[x] = true;
				adj2[u].push_back({v, x});
				adj2[v].push_back({u, x});
			}
		}
		for (auto v : vec) {
			if (!mark[v]) {
				dfs(v);
			}
		}
		for (auto v : vec) {
			mark[v] = false;
			h[v] = 0;
			jmp[v] = N;
		//	int u = st[x], v = ed[x];
		//	u = get_par(u), v = get_par(v);
			adj2[v].clear();
		}
		
		for (auto x : e[i]) {
			int u = st[x], v = ed[x];
			u = get_par(u), v = get_par(v);
			if (u != v) {
				par[u] = v;
			}			
		}
	}
	for (int i = 1; i <= m; i++) {
		if (mark1[i]) {
			if (mark2[i]) {
				cout << "any";
			}
			else {
				cout << "at least one";
			}
		}
		else {
			cout << "none";
		}
		cout << endl;
	}
	
	return 0;
}