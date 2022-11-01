#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> g[200000], dep(200000, -1);
vector<bool> used;
vector<int> x, y, z;

void add(int a, int b, int c) {
	x.push_back(a);
	y.push_back(b);
	z.push_back(c);
}

void dfs(int v, int p) {
	int last = -1;
	for(int to : g[v]) {
		if(dep[to] != -1) {
			if(dep[to] > dep[v]) {
				if(last == -1) last = to;
				else {
					add(last, v, to);
					last = -1;
				}
			}
			continue;
		}
		dep[to] = dep[v] + 1;
		dfs(to, v);
		if(!used[to]) {
			if(last == -1) last = to;
			else {
				add(last, v, to);
				last = -1;
			}
		}
	}
	if(last != -1 && p != -1) {
		used[v] = true;
		add(p, v, last);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	used.assign(n, false);
	for(int i = 0; i < n; i++)
		if(dep[i] == -1) {
			dep[i] = 0;
			dfs(i, -1);
		}
	cout << x.size() << '\n';
	for(int i = 0; i < x.size(); i++)
		cout << x[i] + 1 << ' ' << y[i] + 1 << ' ' << z[i] + 1 << '\n';
}