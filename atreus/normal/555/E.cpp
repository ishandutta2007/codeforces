/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
int c[maxn], up[maxn], h[maxn];
bool visited[maxn];
set<int> s[maxn];

vector<int> g[maxn];

void dfs(int v, int par = -1){
	c[v] = v;
	visited[v] = 1;
	up[v] = h[v];
	int cnt = 0;
	for (auto u : g[v]){
		if (u == par)
			cnt ++;
		else if (!visited[u]){
			h[u] = h[v] + 1;
			dfs(u, v);
			up[v] = min(up[v], up[u]);
			if (s[c[u]].size() > s[c[v]].size())
				c[v] = c[u];
		}
		else
			up[v] = min(up[v], h[u]);
	}
	if (cnt > 1)
		up[v] = min(up[v], h[v] - 1);

	for (auto u : g[v]){
		if (h[u] == h[v] + 1 and c[u] != c[v]){
			for (auto it : s[c[u]]){
				if (s[c[v]].find(-it) != s[c[v]].end())
					s[c[v]].erase(-it);
				else
					s[c[v]].insert(it);
			}
			s[c[u]].clear();
		}
	}
	if (c[v] != v){
		for (auto it : s[v]){
			if (s[c[v]].find(-it) != s[c[v]].end())
				s[c[v]].erase(-it);
			else
				s[c[v]].insert(it);
		}
		s[v].clear();
	}
	if (up[v] < h[v])
		return;	
	if (s[c[v]].empty())
		return;	
	int minimum = *s[c[v]].begin();
	auto it = s[c[v]].end();
	it --;
	int maximum = *it;
	if (minimum < 0 and maximum > 0){
		cout << "No" << endl;
		exit(0);
	}
}

int par[maxn];
int get_par(int v){
	if (par[v] < 0)
		return v;
	return par[v] = get_par(par[v]);
}

void merge(int v, int u){
	v = get_par(v), u = get_par(u);
	if (v == u)
		return;
	par[v] = u;
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(par, -1, sizeof par);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
		merge(v, u);
	}
	string answer = "Yes";
	for (int i = 0; i < q; i++){
		int v, u;
		cin >> v >> u;
		if (get_par(v) != get_par(u))
			answer = "No";
		s[v].insert(i + 1);
		s[u].insert(-i - 1);
	}
	if (answer == "No")
		return cout << answer << endl, 0;
	for (int v = 1; v <= n; v++)
		if (!visited[v])
			dfs(v);
	cout << "Yes" << endl;
}