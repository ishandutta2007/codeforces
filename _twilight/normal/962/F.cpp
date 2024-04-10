#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

#define pii pair<int, int>

int n, m;
boolean vis[N];
vector<int> ans;
vector<pii> G[N];
boolean on_tree[N];
int s1[N], s2[N], d[N];

void dfs1(int p, int fa) {
	vis[p] = true;
	d[p] = d[fa] + 1;
	for (auto& par : G[p]) {
		int e = par.first;
		if (!vis[e]) {
			on_tree[par.second] = true;
			dfs1(e, p);
		} else {
			if (e == fa) {
				on_tree[par.second] = true;
			} else if (d[e] < d[p]) {
				s1[e]--;
				s1[p]++;
			}
		}
	}
}

int dfs2(int p, int fa) {
	for (auto par : G[p]) {
		if (on_tree[par.second]) {
			int e = par.first;
			if (e ^ fa) {
				s1[p] += dfs2(e, p);			
			}
		}
	}
	return s1[p];
}

void dfs3(int p, int fa) {
	s1[p] += s1[fa];
	for (auto par : G[p]) {
		if (on_tree[par.second]) {
			int e = par.first;
			if (e ^ fa) {
				dfs3(e, p);			
			}
		}
	}
}

void dfs4(int p, int fa) {
	for (auto par : G[p]) {
		int e = par.first;
		if (e == fa)
			continue;
		if (on_tree[par.second]) {
			dfs4(e, p);
		} else {
			if (d[e] < d[p]) {
				if (s1[p] - s1[e] > d[p] - d[e]) {
					s2[e]--;
					s2[p]++;
				} else {
					ans.emplace_back(par.second);
				}
			}
		}
	}
}

int dfs5(int p, int fa, int fe) {
	for (auto par : G[p]) {
		if (on_tree[par.second]) {
			int e = par.first;
			if (e ^ fa) {
				s2[p] += dfs5(e, p, par.second);			
			}
		}
	}
	if (!s2[p] && (s1[p] - s1[fa]) && fe > 0) {
		ans.push_back(fe);
	}
	return s2[p];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		G[u].emplace_back(v, i);
		G[v].emplace_back(u, i);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs1(i, 0);
			dfs2(i, 0);
			dfs3(i, 0);
			dfs4(i, 0);
			dfs5(i, 0, 0);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", (signed) ans.size());
	for (auto e : ans) {
		printf("%d ", e);
	}
	return 0;
}