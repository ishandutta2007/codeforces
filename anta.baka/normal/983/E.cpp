#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 2e5;

int n, m, dep[maxn], tsz[maxn], up[maxn][18], tin[maxn], tout[maxn], tik_tak;
vector<int> g[maxn], cntout(maxn, 0);
vector<pair<int, int>> vin[maxn];

void dfs1(int v, int p) {
	tin[v] = tik_tak++;
	up[v][0] = p;
	for(int i = 1; i < 18; i++) up[v][i] = up[up[v][i - 1]][i - 1];
	tsz[v] = 1;
	for(int to : g[v]) {
		dep[to] = dep[v] + 1;
		dfs1(to, v);
		tsz[v] += tsz[to];
	}
	tout[v] = tik_tak++;
}

bool upper(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if(tin[u] > tin[v]) swap(u, v);
	if(upper(u, v)) return u;
	for(int i = 17; i >= 0; i--)
		if(!upper(up[u][i], v))
			u = up[u][i];
	return up[u][0];
}

int li[maxn];
multiset<pair<int, int>> deps[maxn];
int pup[maxn][18];

void dfs2(int v) {
	for(int to : g[v]) dfs2(to);
	if(g[v].empty()) {
		li[v] = v;
	} else {
		li[v] = li[g[v][0]];
		for(int to : g[v])
			if(sz(deps[li[to]]) > sz(deps[li[v]]))
				li[v] = li[to];
		for(int to : g[v])
			if(li[to] != li[v])
				for(pair<int, int> x : deps[li[to]])
					deps[li[v]].insert(x);
	}
	for(pair<int, int> x : vin[v]) deps[li[v]].insert(x);
	pup[v][0] = (deps[li[v]].empty() ? v : deps[li[v]].begin()->second);
	for(int i = 0; i < cntout[v]; i++) deps[li[v]].erase(deps[li[v]].find({dep[v], v}));
}

int lb[maxn], rb[maxn], tik_tak1 = -1;

void dfs3(int v) {
	lb[v] = ++tik_tak1;
	for(int i = 1; i < 18; i++) pup[v][i] = pup[pup[v][i - 1]][i - 1];
	for(int to : g[v]) dfs3(to);
	rb[v] = tik_tak1;
}

vector<pair<int, int>> vec;
vector<int> t[2 * maxn];

bool get(int v, int l, int r) {
	if(t[v][0] > r) return false;
	int lf = 0, rg = sz(t[v]) - 1;
	while(lf < rg) {
		int md = (lf + rg + 1) >> 1;
		if(t[v][md] <= r) lf = md;
		else rg = md - 1;
	}
	return l <= t[v][lf];
}

bool get(int l, int r, int l1, int r1) {
	bool ok = false;
	for(l += sz(vec), r += sz(vec); l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
		if(l & 1) ok |= get(l, l1, r1);
		if(!(r & 1)) ok |= get(r, l1, r1);
	}
	return ok;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++) {
		int j; cin >> j; j--;
		g[j].push_back(i);
	}
	dfs1(0, 0);
	cin >> m;
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		if(tin[u] > tin[v]) swap(u, v);
		if(upper(u, v)) {
			vin[v].push_back({dep[u], u});
			cntout[u]++;
		} else {
			int w = lca(u, v);
			vin[u].push_back({dep[w], w});
			vin[v].push_back({dep[w], w});
			cntout[w] += 2;
			vec.push_back({u, v});
		}
	}
	dfs2(0);
	dfs3(0);
	sort(all(vec), [](pair<int, int> a, pair<int, int> b){ return lb[a.first] < lb[b.first]; });
	for(int i = 0; i < sz(vec); i++) t[i + sz(vec)].push_back(lb[vec[i].second]);
	for(int i = sz(vec) - 1; i > 0; i--) merge(all(t[i * 2]), all(t[i * 2 + 1]), back_inserter(t[i]));
	cin >> m;
	while(m--) {
		int u, v; cin >> u >> v; u--; v--;
		if(tin[u] > tin[v]) swap(u, v);
		int ans = 0;
		if(upper(u, v)) {
			for(int i = 17; i >= 0; i--)
				if(!upper(pup[v][i], u))
					v = pup[v][i], ans += (1 << i);
			ans++;
			v = pup[v][0];
			if(!upper(v, u)) ans = -1;
			cout << ans << '\n';
		} else {
			for(int i = 17; i >= 0; i--)
				if(!upper(pup[v][i], u))
					v = pup[v][i], ans += (1 << i);
			for(int i = 17; i >= 0; i--)
				if(!upper(pup[u][i], v))
					u = pup[u][i], ans += (1 << i);
			if(!upper(pup[u][0], v) || !upper(pup[v][0], u)) {
				cout << -1 << '\n';
				continue;
			}
			ans += 2;
			if(sz(vec) && lb[vec[0].first] <= rb[u] && lb[u] <= lb[vec.back().first]) {
				int lf = 0, rg = sz(vec) - 1;
				while(lf < rg) {
					int md = (lf + rg) >> 1;
					if(lb[vec[md].first] >= lb[u]) rg = md;
					else lf = md + 1;
				}
				int L = lf;
				lf = 0, rg = sz(vec) - 1;
				while(lf < rg) {
					int md = (lf + rg + 1) >> 1;
					if(lb[vec[md].first] <= rb[u]) lf = md;
					else rg = md - 1;
				}
				int R = lf;
				if(L <= R && get(L, R, lb[v], rb[v])) ans--;
			}
			cout << ans << '\n';
		}
	}
}