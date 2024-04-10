#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5;
const int maxq = 1e6;
const int SZ = 317; //  1 

int n, rt, a[maxn], tik_tak, tin[maxn], vec[maxn], ri[maxn], dep[maxn], q, z;
vector<int> g[maxn];
vector<vector<int>> lo(316, vector<int>(maxn, INT_MAX));

void dfs(int v, int p) {
	tin[v] = tik_tak++;
	vec[tin[v]] = v;
	ri[v] = tin[v];
	for(int to : g[v])
		if(to != p) {
			dep[to] = dep[v] + 1;
			dfs(to, v);
			ri[v] = ri[to];
		}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> rt; rt--;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(rt, -1);
	for(int i = 0; i < (n + SZ - 1) / SZ; i++) {
		int l = i * SZ, r = (i + 1) * SZ - 1;
		for(int j = l; j <= r; j++) {
			int v = vec[j];
			lo[i][dep[v]] = min(lo[i][dep[v]], a[v]);
		}
		for(int j = 1; j < n; j++) lo[i][j] = min(lo[i][j], lo[i][j - 1]);
	}
	cin >> q;
	while(q--) {
		int p, q; cin >> p >> q;
		int v = (p + z) % n, d = (q + z) % n;
		int l = tin[v], r = ri[v];
		d += dep[v];
		d = min(d, n - 1);
		int ans = INT_MAX;
		int bl = l / SZ, br = r / SZ;
		if(bl != br) {
			int bou = (bl + 1) * SZ - 1;
			for(int j = l; j <= bou; j++)
				if(dep[vec[j]] <= d)
					ans = min(ans, a[vec[j]]);
			bou = br * SZ;
			for(int j = bou; j <= r; j++)
				if(dep[vec[j]] <= d)
					ans = min(ans, a[vec[j]]);
			for(int j = bl + 1; j <= br - 1; j++)
				ans = min(ans, lo[j][d]);
		} else {
			for(int j = l; j <= r; j++)
				if(dep[vec[j]] <= d)
					ans = min(ans, a[vec[j]]);
		}
		cout << ans << '\n';
		z = ans;
	}
}