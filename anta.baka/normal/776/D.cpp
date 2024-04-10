#include <bits/stdc++.h>

using namespace std;

#define rank iHateThisContest

vector<int> par, rank;

int find(int v) {
	if(par[v] == v)
		return v;
	return par[v] = find(par[v]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if(u != v) {
		if(rank[u] < rank[v])
			swap(u, v);
		par[v] = u;
		if(rank[u] == rank[v])
			rank[u]++;
	}
}

vector<vector<int>> g, g1;
vector<bool> was;
vector<int> tt;

void dfs(int v, int t) {
	was[v] = true;
	tt[v] = t;
	for(int to : g1[v])
		if(was[to] == false)
			dfs(to, !t);
		else if(t == tt[to]) {
			cout << "NO";
			exit(0);
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	rank.resize(m, 0);
	par.resize(m);
	for(int i = 0; i < m; i++)
		par[i] = i;
	vector<int> clr(n);
	for(int i = 0; i < n; i++)
		cin >> clr[i];
	g.resize(n);
	for(int i = 0; i < m; i++) {
		int siz;
		cin >> siz;
		for(int j = 0; j < siz; j++) {
			int t;
			cin >> t;
			--t;
			g[t].push_back(i);
		}
	}
	for(int i = 0; i < n; i++)
		if(clr[i] == 1)
			uni(g[i][0], g[i][1]);
	for(int i = 0; i < n; i++)
		if(clr[i] == 0 && find(g[i][0]) == find(g[i][1]))
			return cout << "NO", 0;
	g1.resize(m);
	for(int i = 0; i < n; i++)
		if(clr[i] == 0) {
			int u = find(g[i][0]);
			int v = find(g[i][1]);
			g1[u].push_back(v);
			g1[v].push_back(u);
		}
	was.assign(m, false);
	tt.resize(m);
	for(int i = 0; i < m; i++)
		if(was[i] == false)
			dfs(i, 0);
	cout << "YES";
}