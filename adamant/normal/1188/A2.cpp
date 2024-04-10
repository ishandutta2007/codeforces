#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 1e3 + 42;
vector<int> g[maxn];
int par[maxn], sz[maxn];
basic_string<int> leaves[maxn];

void dfs(int v) {
	sz[v] = 1;
	for(auto u: g[v]) {
		if(u != par[v]) {
			par[u] = v;
			dfs(u);
			sz[v] += sz[u];
			leaves[v] += leaves[u][0];
		}
	}
	if(g[v].size() == 1) {
		leaves[v] = {v};
	}
}


vector<tuple<int, int, int>> ans;
int need[maxn];
tuple<int, int, int> changers[maxn];

void change(int v, int added = 0) {
	for(auto u: g[v]) {
		if(u != par[v]) {
			int a, b, c;
			tie(a, b, c) = changers[u];
			int d = need[u] - added * (a == leaves[v][0]);
			ans.emplace_back(a, b, d / 2);
			ans.emplace_back(a, c, d / 2);
			ans.emplace_back(b, c, -d / 2);
			change(u, added * (a == leaves[v][0]) + d);
		}
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int u[n], v[n], val[n];
	for(int i = 1; i < n; i++) {
		cin >> u[i] >> v[i] >> val[i];
		u[i]--, v[i]--;
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	bool ok = true;
	for(int i = 0; i < n; i++) {
		ok &= g[i].size() == 1 || g[i].size() >= 3;
	}
	if(!ok) {
		cout << "NO" << endl;
	} else if(n == 2) {
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << 1 << ' ' << 2 << ' '<< val[1] << endl;
		return 0;
	} else {
		cout << "YES" << endl;
		int root = 0;
		while(g[root].size() == 1) {
			root++;
		}
		par[root] = root;
		dfs(root);
		for(int i = 1; i < n; i++) {
			if(sz[u[i]] > sz[v[i]]) {
				swap(u[i], v[i]);
			}
			int a = leaves[u[i]][0];
			int b = 0;
			while(leaves[v[i]][b] == a) {
				b++;
			}
			int c = b + 1;
			b = leaves[v[i]][b];
			while(c < (int)leaves[v[i]].size() && leaves[v[i]][c] == a) {
				c++;
			}
			if(c == (int)leaves[v[i]].size()) {
				int w = par[v[i]];
				c = 0;
				while(leaves[w][c] == a || leaves[w][c] == b) {
					c++;
				}
				c = leaves[w][c];
			} else {
				c = leaves[v[i]][c];
			}
			changers[u[i]] = {a, b, c};
			need[u[i]] = val[i];
		}
		change(root);
		cout << ans.size() << endl;
		for(auto it: ans) {
			int a, b, c;
			tie(a, b, c) = it;
			cout << a + 1 << ' ' << b + 1 << ' ' << c << endl;
		}
	}
	return 0;
}