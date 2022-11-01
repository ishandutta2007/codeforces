/*
 
 
 
 
 
 





 
 

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5;

int n, m;
vector<int> g[maxn];
vector<bool> was(maxn, false);
int timer, tin[maxn], fup[maxn];
set<pair<int, int>> bridges;

inline void addedge(int u, int v) {
	if(u > v) swap(u, v);
	bridges.insert({u, v});
}

void dfs(int v, int p = -1) {
	was[v] = true;
	tin[v] = fup[v] = timer++;
	for(int to : g[v]) {
		if(to == p) continue;
		if(was[to]) fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if(fup[to] > tin[v]) addedge(v, to);
		}
	}
}

int lo, hi;

inline bool can(int u, int v) {
	if(u > v) swap(u, v);
	return bridges.find({u, v}) == bridges.end();
}

void dfs1(int v) {
	was[v] = true;
	lo = min(lo, v);
	hi = max(hi, v);
	for(int to : g[v])
		if(!was[to] && can(v, to)) dfs1(to);
}

vector<pair<int, int>> segs;

vector<vector<int>> t;
vector<vector<ll>> suff;

inline ll get(int v, int x) {
	if(t[v][0] > x) return suff[v][0];
	int sz = t[v].size();
	int lf = 0, rg = sz - 1;
	while(lf < rg) {
		int md = (lf + rg) >> 1;
		if(lf == md) md++;
		if(t[v][md] <= x) lf = md;
		else rg = md - 1;
	}
	ll ret = 0;
	if(lf != sz - 1) ret = suff[v][lf + 1];
	ret += (ll)x * (lf + 1);
	return ret;
}

inline ll get(int l, int r, int x) {
	ll ret = 0;
	for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
		if(l & 1) ret += get(l, x);
		if(!(r & 1)) ret += get(r, x);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v); g[v].push_back(u);
	}
	for(int i = 0; i < n; i++) if(!was[i]) dfs(i);
	was.assign(n, false);
	for(int v = 0; v < n; v++)
		if(!was[v]) {
			lo = hi = v;
			dfs1(v);
			if(lo != hi) segs.push_back({lo, hi});
		}
	vector<int> ends(n, 0);
	for(pair<int, int> seg : segs) ends[seg.second] = max(ends[seg.second], seg.first + 1);
	for(int i = 1; i < n; i++) ends[i] = max(ends[i - 1], ends[i]);
	t.resize(2 * n);
	for(int i = 0; i < n; i++) t[i + n].push_back(ends[i]);
	for(int i = n - 1; i; i--) merge(t[i * 2].begin(), t[i * 2].end(), t[i * 2 + 1].begin(), t[i * 2 + 1].end(), back_inserter(t[i]));
	suff.resize(2 * n);
	for(int i = 1; i < 2 * n; i++) {
		int sz = t[i].size();
		suff[i].resize(sz);
		suff[i][sz - 1] = t[i][sz - 1];
		for(int j = sz - 2; j >= 0; j--) suff[i][j] = suff[i][j + 1] + t[i][j];
	}
	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r; l--; r--;
		ll ret = (l + r + 2) * (ll)(r - l + 1) / 2;
		ret -= get(l, r, l);
		cout << ret << '\n';
	}
}