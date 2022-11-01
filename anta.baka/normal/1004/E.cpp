#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
const int maxn = 1e5;
#define x first
#define y second

int n, k, dep[maxn], maxd, U, V, fr[maxn], pref[maxn], suff[maxn];
vector<pair<int, int>> g[maxn];

void dfs(int v) {
	for(auto e : g[v]) if(dep[e.x] == 0) dep[e.x] = dep[v] + e.y, dfs(e.x);
}

void upd(int v) {
	for(int u = 0; u < n; u++) if(dep[u] > maxd) U = u, V = v, maxd = dep[u];
}

vector<int> cur, path, curr, pathh;
void dfs1(int v, int p) {
	cur.push_back(v);
	if(v == V) path = cur, pathh = curr;
	for(auto e : g[v]) if(e.x != p) curr.push_back(e.y), dfs1(e.x, v), curr.pop_back();
	cur.pop_back();
}

void dfs2(int v, int st) {
	fr[st] = max(fr[st], dep[v]);
	for(auto e : g[v]) if(dep[e.x] == -1) dep[e.x] = dep[v] + e.y, dfs2(e.x, st);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++) {
		int u, v, w; cin >> u >> v >> w; u--; v--;
		g[u].push_back({v, w}); g[v].push_back({u, w});
	}
	dfs(0); upd(0); memset(dep, 0, sizeof(dep)); dfs(U); upd(U);
	dfs1(U, -1); memset(dep, -1, sizeof(dep));
	for(int v : path) dep[v] = 0;
	for(int v : path) dfs2(v, v);
	for(int i = 0; i < sz(path); i++) pref[i] = max(i ? pref[i - 1] + pathh[i - 1]: 0, fr[path[i]]);
	for(int i = sz(path) - 1; i >= 0; i--) suff[i] = max(i != sz(path) - 1 ? suff[i + 1] + pathh[i] : 0, fr[path[i]]);
	k = min(k, sz(path));
	multiset<int> window;
	int ans = INT_MAX;
	for(int i = 0; i < k - 1; i++) window.insert(fr[path[i]]);
	for(int i = k - 1; i < sz(path); i++) {
		window.insert(fr[path[i]]);
		ans = min(ans, max({pref[i - k + 1], *window.rbegin(), suff[i]}));
		window.erase(fr[path[i - k + 1]]);
	}
	cout << ans;
}