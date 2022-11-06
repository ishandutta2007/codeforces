#include <bits/stdc++.h>
#define IT set<int>::iterator
using std::vector; using std::sort; using std::set; using std::lower_bound;
const int N = 500005;
int T, n, m, d[N], p[N], q[N];
vector<int> e[N], e2[N];
set<int> S;
void dfs1(int u) {
	for (IT it = S.begin(); it != S.end(); it++) {
		int pos = lower_bound(e[u].begin(), e[u].end(), *it) - e[u].begin();
		if (pos != e[u].size() && e[u][pos] == *it) continue;
		e2[u].push_back(*it);
	}
	for (int i = 0; i < e2[u].size(); i++)
		S.erase(e2[u][i]);
	for (int i = 0; i < e2[u].size(); i++)
		dfs1(e2[u][i]);
}
int tot;
void dfs2(int u, int f) {
	for (int i = 0, v; i < e2[u].size(); i++)
		dfs2(v = e2[u][i], u);
	if (d[u] > 1 || d[u] == 1 && !f) {
		vector<int> v;
		if (d[f] == 1) v.push_back(f);
		for (int i = 0; i < e2[u].size(); i++)
			if (d[e2[u][i]] == 1) v.push_back(e2[u][i]);
		p[u] = tot, q[u] = tot + v.size();
		for (int i = 0; i < v.size(); i++)
			p[v[i]] = tot + i + 1, q[v[i]] = tot + i;
		d[f]--; d[u] = 0;
		tot += v.size() + 1;
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			e[i].clear(), e2[i].clear(), d[i] = p[i] = q[i] = 0;
		for (int i = 1; i <= m; i++) {
			int u, v; scanf("%d%d", &u, &v);
			e[u].push_back(v), e[v].push_back(u);
			d[u]++, d[v]++;
		}
		int m = n;
		S.clear();
		for (int i = 1; i <= n; i++) {
			sort(e[i].begin(), e[i].end());
			if (d[i] == m - 1) {
				p[i] = q[i] = m; m--;
				for (int j = 0; j < e[i].size(); j++)
					d[e[i][j]]--;
			} else S.insert(i);
		}
		tot = 1;
		while (S.size()) {
			int rt = *S.begin();
			S.erase(rt), dfs1(rt);
			for (int i = 1; i <= n; i++) d[i] = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 0; j < e2[i].size(); j++)
					d[i]++, d[e2[i][j]]++;
			dfs2(rt, 0);
		}
		for (int i = 1; i <= n; i++) printf("%d%c", p[i], " \n"[i == n]);
		for (int i = 1; i <= n; i++) printf("%d%c", q[i], " \n"[i == n]);
	}
	return 0;
}