#include <bits/stdc++.h>
using namespace std;

const int N = 500 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;

bool mark[N];
vector <pair <int, int> > adj[N];
vector <int> ans;
int par[N];


int get_par(int v) {
	if (par[v] == v)
		return v;
	return par[v] = get_par(par[v]);
}


/*void dfs(int v) {
	mark[v] = true;
	for (auto p : adj[v]) {
		int u = p.first;
		if (!mark[u]) {
			ans.push_back(p.second);
			dfs(u);
		}
	}
}*/

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		par[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		int k, u, v;
		cin >> k;
		if (k == 1) {
			int u;
			cin >> u;
			v = 0;
			
		}
		else {
			cin >> u >> v;
		}
		u = get_par(u), v = get_par(v);
		if (u != v) {
			par[u] = v;
			ans.push_back(i);
		}
	}
/*	for (int i = 1; i <= m; i++) {
		if (mark[i]) {
			dfs(i);
		}
	}
	for (int i = 1; i <= m; i++) {
		if (!mark[i]) {
			dfs(i);
		}
	}*/
	long long t = 1;
	for (int i = 0; i < ans.size(); i++) {
		t *= 2;
		t %= mod;
	}
	cout << t << " " << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto x : ans) {
		cout << x << " ";
	}
	return 0;
}