#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
vector<int> ls;
void Pr() {
	printf("%d\n", (int)ls.size());
	for (int x : ls) printf("%d ", x);
	exit(0);
}
namespace F {
	int fa[N], deg[N], vis[N];
	set<int> G[N];
	int Find(int x) {
		return fa[x] == x ? x : fa[x] = Find(fa[x]);
	}
	void dfs(int u) {
		while (G[u].size()) {
			int v = *G[u].begin();
			G[u].erase(v);
			G[v].erase(u);
			dfs(v);
		}
		ls.push_back(u);
	}
	bool solve(int n, vector<pair<int, int> > ve, int st) {
		for (int i = 1; i <= n; i++) fa[i] = i, G[i].clear(), deg[i] = 0, vis[i] = 0;
		for (auto e : ve) {
			int u = e.first, v = e.second;
			G[u].insert(v);
			G[v].insert(u);
			deg[u]++;
			deg[v]++;
			vis[u] = vis[v] = 1;
			fa[Find(u)] = Find(v);
		}
		vector<int> bu;
		for (int i = 1; i <= n; i++) if (vis[i]) bu.push_back(i);
		if (!bu.size()) {
			ls.clear();
			return true;
		}
		for (int i : bu) if (Find(i) != Find(bu[0])) return false;
		int cc = 0;
		for (int i : bu) if (deg[i] % 2 == 1) cc++;
		if (cc > 2) return false;
		ls.clear();
		dfs(st);
		return true;
	}
}
int n, m, deg[N], vis[N];
vector<pair<int, int> > ve;
set<pair<int, int> > st;
int main() {
	scanf("%d%d", &n, &m);
	ve.resize(m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &ve[i].first, &ve[i].second);
		if (ve[i].first > ve[i].second) swap(ve[i].first, ve[i].second);
		deg[ve[i].first]++;
		deg[ve[i].second]++;
		st.emplace(ve[i].first, ve[i].second);
	}
	for (int i = 1; i <= n; i++) {
		vector<int> bad;
		for (int j = 1; j <= n; j++) vis[j] = 0;
		for (int j = 1; j <= n; j++) if (j != i && deg[j] % 2 == 1) {
			if (!st.count(make_pair(min(i, j), max(i, j)))) {
				bad.push_back(j);
			} else
				vis[j] = 1;
		}
		if (bad.size() > 1) continue;
		if (bad.size() == 1) {
			vector<pair<int, int> > nv;
			for (auto &e : ve) {
				if ((e.first == i && vis[e.second]) || (e.second == i && vis[e.first])) {
				} else {
					nv.push_back(e);
				}
			}
			if (F::solve(n, nv, i)) {
				ls.push_back(-1);
				for (int j = 1; j <= n; j++) if (vis[j]) {
					ls.push_back(j);
					ls.push_back(i);
				}
				Pr();
			}
		} else {
			for (int k = 1; k <= n; k++) if (vis[k]) {
				vis[k] = 0;
				vector<pair<int, int> > nv;
				for (auto &e : ve) {
					if ((e.first == i && vis[e.second]) || (e.second == i && vis[e.first])) {
					} else {
						nv.push_back(e);
					}
				}
				if (F::solve(n, nv, i)) {
					ls.push_back(-1);
					for (int j = 1; j <= n; j++) if (vis[j]) {
						ls.push_back(j);
						ls.push_back(i);
					}
					Pr();
				}
				vis[k] = 1;
			}
			vector<pair<int, int> > nv;
			for (auto &e : ve) {
				if ((e.first == i && vis[e.second]) || (e.second == i && vis[e.first])) {
				} else {
					nv.push_back(e);
				}
			}
			if (F::solve(n, nv, i)) {
				ls.push_back(-1);
				for (int j = 1; j <= n; j++) if (vis[j]) {
					ls.push_back(j);
					ls.push_back(i);
				}
				Pr();
			}
		}
	}
	puts("0");
	return 0;
}