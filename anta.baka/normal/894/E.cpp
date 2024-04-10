#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6;

int n, m;
vector<pair<int, int>> g[maxn], g1[maxn], g2[maxn];
vector<bool> was;
vector<int> tps;
int comp;
vector<int> inc(maxn, -1);
ll sum[maxn];
ll p[20001];
vector<ll> dp(maxn, -1);

void dfs1(int v) {
	was[v] = true;
	for(pair<int, int> e : g[v])
		if(!was[e.first])
			dfs1(e.first);
	tps.push_back(v);
}

void dfs2(int v) {
	inc[v] = comp;
	for(pair<int, int> e : g1[v])
		if(inc[e.first] == -1)
			dfs2(e.first);
}

void dfs3(int v) {
	ll ad = 0;
	for(pair<int, int> e : g2[v]) {
		int to = e.first;
		if(dp[to] == -1) dfs3(to);
		ad = max(ad, dp[to] + e.second);
	}
	dp[v] = ad + sum[v];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for(int i = 1; i <= 20000; i++) p[i] = p[i - 1] + (ll)i * (i + 1) / 2;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w; --u; --v;
		g[u].push_back({v, w});
		g1[v].push_back({u, w});
	}
	was.assign(n, false);
	for(int i = 0; i < n; i++)
		if(!was[i])
			dfs1(i);
	reverse(tps.begin(), tps.end());
	for(int v : tps)
		if(inc[v] == -1) {
			dfs2(v);
			comp++;
		}
	for(int u = 0; u < n; u++)
		for(pair<int, int> e : g[u]) {
			int v = e.first, w = e.second;
			if(inc[u] == inc[v]) {
				int lf = 0, rg = 20000;
				while(lf < rg) {
					int md = (lf + rg) / 2;
					if(lf == md) md++;
					if(w - (ll)md * (md + 1) / 2 >= 0) lf = md;
					else rg = md - 1;
				}
				sum[inc[u]] += (ll)w * (lf + 1) - p[lf];
			} else
				g2[inc[u]].push_back({inc[v], w});
		}
	for(int i = 0; i < comp; i++)
		if(dp[i] == -1)
			dfs3(i);
	int s; cin >> s; s--; s = inc[s]; cout << dp[s];
}