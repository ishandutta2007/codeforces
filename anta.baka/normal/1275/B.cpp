#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int N = 2e5 + 228;

int n;
int a[N];
vector<int> g[N];
int in[N];
int out[N];
int timer;
map<int, vector<int>> col;

void dfs(int v, int p) {
	col[a[v]].push_back(in[v] = timer++);
	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v);
		}
	}
	out[v] = timer;
}

bool up[N];
bool bot[N];
int ans;

bool contains(int l, int r, const vector<int>& a) {
	if (l >= r) {
		return false;
	}
	auto it = lower_bound(a.begin(), a.end(), l);
	if (it == a.end()) {
		return false;
	}
	return (*it < r);
}

void dfs1(int v, int p) {
	bot[v] = !contains(in[v] + 1, out[v], col[a[v]]);
	for (int to : g[v]) {
		if (to != p) {
			dfs1(to, v);
			bot[v] &= bot[to];
		}
	}
}

void dfs2(int v, int p) {
	vector<bool> kek(g[v].size() + 1, true);
	for (int i = g[v].size() - 1; i >= 0; i--) {
		kek[i] = kek[i + 1] && (g[v][i] == p || bot[g[v][i]]);
	}
	bool pref = true;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to != p) {
			up[to] &= up[v];
			up[to] &= !contains(0, in[v], col[a[v]]);
			up[to] &= !contains(in[v] + 1, in[to], col[a[v]]);
			up[to] &= !contains(out[to], n, col[a[v]]);
			up[to] &= pref;
			up[to] &= kek[i + 1];
			dfs2(to, v);
			pref &= bot[to];
		}
	}
	ans += (up[v] && bot[v] && col[a[v]].size() == 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		up[i] = true;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	dfs1(0, -1);
	dfs2(0, -1);
	cout << ans << endl;
}