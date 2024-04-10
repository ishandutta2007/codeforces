#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<pair<int, int>> g[200000];
vector<bool> was;
vector<int> path, e_path, cycle, e_cycle;
int extra_e;
vector<ll> deep, tmp;
vector<ll> p, pp, s, ss;
vector<int> sz;
int re[200000];
vector<vector<pair<int, int>>> g1;

void dfs1(int v, int p) {
	was[v] = true;
	path.push_back(v);
	for(pair<int, int> e : g[v])
		if(e.first != p && was[e.first]) {
			if(cycle.empty()) {
				cycle = path;
				e_cycle = e_path;
				reverse(cycle.begin(), cycle.end());
				reverse(e_cycle.begin(), e_cycle.end());
				while(cycle.back() != e.first) {
					cycle.pop_back();
					e_cycle.pop_back();
				}
				extra_e = e.second;
			}
		} else if(e.first != p) {
			e_path.push_back(e.second);
			dfs1(e.first, v);
			e_path.pop_back();
		}
	path.pop_back();
}

void dfs2(int v) {
	re[v] = sz.back()++;
	was[v] = true;
	for(pair<int, int> e : g[v])
		if(was[e.first] == false) {
			dfs2(e.first);
			deep[v] = max(deep[v], deep[e.first] + e.second);
		}
}

void dfs3(int v) {
	was[v] = true;
	for(pair<int, int> e : g[v])
		if(was[e.first] == false) {
			g1[re[v]].push_back({re[e.first], e.second});
			g1[re[e.first]].push_back({re[v], e.second});
			dfs3(e.first);
		}
}

pair<ll, int> dfs4(int v, int p) {
	pair<ll, int> ret = {0, v};
	for(pair<int, int> e : g1[v])
		if(e.first != p) {
			pair<ll, int> to = dfs4(e.first, v);
			ret = max(ret, {to.first + e.second, to.second});
		}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	was.assign(n, false);
	dfs1(0, -1);
	int m = cycle.size();
	was.assign(n, false);
	for(int v : cycle)
		was[v] = true;
	deep.assign(n, 0);
	for(int v : cycle) {
		sz.push_back(0);
		dfs2(v);
	}
	was.assign(n, false);
	for(int v : cycle)
		was[v] = true;
	ll maxd = 0;
	for(int i = 0; i < m; i++) {
		g1.clear();
		g1.resize(sz[i]);
		dfs3(cycle[i]);
		pair<ll, int> one = dfs4(re[cycle[i]], -1);
		maxd = max({maxd, one.first, dfs4(one.second, -1).first});
	}
	tmp.resize(m);
	tmp[0] = 0;
	for(int i = 0; i < m - 1; i++)
		tmp[i + 1] = tmp[i] + e_cycle[i];
	p.resize(m);
	pp.resize(m);
	s.resize(m);
	ss.resize(m);
	p[0] = deep[cycle[0]];
	for(int i = 1; i < m; i++)
		p[i] = max(p[i - 1], tmp[i] + deep[cycle[i]]);
	s[m - 1] = deep[cycle[m - 1]];
	for(int i = m - 2; i >= 0; i--)
		s[i] = max(s[i + 1], tmp[m - 1] - tmp[i] + deep[cycle[i]]);
	pp[0] = 0;
	int v = 0;
	for(int i = 1; i < m; i++) {
		if(deep[cycle[i - 1]] + tmp[i] - tmp[i - 1] >= deep[cycle[v]] + tmp[i] - tmp[v])
			v = i - 1;
		pp[i] = max(pp[i - 1], deep[cycle[v]] + deep[cycle[i]] + tmp[i] - tmp[v]);
	}
	ss[m - 1] = 0;
	v = m - 1;
	for(int i = m - 2; i >= 0; i--) {
		if(deep[cycle[i + 1]] + tmp[i + 1] - tmp[i] >= deep[cycle[v]] + tmp[v] - tmp[i])
			v = i + 1;
		ss[i] = max(ss[i + 1], deep[cycle[v]] + deep[cycle[i]] + tmp[v] - tmp[i]);
	}
	ll ans = pp[m - 1];
	for(int i = 0; i < m - 1; i++)
		ans = min(ans, max({pp[i], ss[i + 1], p[i] + s[i + 1] + extra_e}));
	cout << max(ans, maxd);
}