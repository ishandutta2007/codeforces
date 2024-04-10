#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;


const int N = 1000 * 1000 + 5;
int tm = 1;
pair <int, int> mx;


vector <int> adj[N];
vector <pair <int, int> > t[N];
int sz[N];
int cnt[N];
int h[N];
int st[N];
int ft[N];
int rl[N];
int par[N];
int ans[N];


void pdfs(int v) {
	sz[v] = 1;
	st[v] = tm;
	rl[tm] = v;
	tm++;
	for (auto u : adj[v]) {
		if (u != par[v]) {
			par[u] = v;
			h[u] = h[v] + 1;
			pdfs(u);
			sz[v] += sz[u];
		}
	}
	ft[v] = tm;
}
void dfs(int v) {
	int bg = 0;
	for (auto u : adj[v]) {
		if (u != par[v] && sz[u] > sz[bg]) {
			bg = u;
		}
	}
	for (auto u : adj[v]) {
		if (u != par[v] && u != bg) {
			dfs(u);
			for (int i = st[u]; i < ft[u]; i++) {
				int x = rl[i];
				cnt[h[x]] = 0;
			}
			mx = {0, 0};
		}
	}
	mx = {0, 0};
	if (bg) {
		dfs(bg);
	}
	cnt[h[v]]++;
	mx = max(mx, {cnt[h[v]], -h[v]});
	for (auto u : adj[v]) {
		if (u != par[v] && u != bg) {
			for (int i = st[u]; i < ft[u]; i++) {
				int x = rl[i];
				cnt[h[x]]++;
				mx = max(mx, {cnt[h[x]], -h[x]});
			}
		}
	}
	ans[v] = -mx.second - h[v];
}

int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	pdfs(1);
//	for (int i = 1; i <= n; i++) {
//		cout << i << " " << st[i] << " " << ft[i] << endl;
//	}
//	cout << 37 << endl;
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}