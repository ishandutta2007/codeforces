#include <bits/stdc++.h>
using namespace std;
const int N = 150005;
const int V = 1000005;
int zhi[V], pri[V], tot, mnp[V];
inline void Sieve() {
	zhi[1] = 1;
	for (int i = 2; i < V; i++) {
		if (!zhi[i]) pri[++tot] = i, mnp[i] = i;
		for (int j = 1; j <= tot && i * pri[j] < V; j++) {
			zhi[i * pri[j]] = 1;
			mnp[i * pri[j]] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}
inline vector<int> getp(int t) {
	vector<int> ret;
	while (t > 1) {
		int pp = mnp[t];
		ret.push_back(pp);
		while (t % pp == 0) t /= pp;
	}
	return ret;
}
int n, q, a[N], fa[N];
vector<int> vap[N], vap1[N];
vector<int> pav[V];
set<pair<int, int> > st;
int gf[V];
int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y) {
	fa[Find(x)] = Find(y);
}
int main() {
	Sieve();
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		vap[i] = getp(a[i]);
		vap1[i] = getp(a[i] + 1);
		for (int p : vap[i]) {
			pav[p].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int p = 1; p < V; p++) if (pav[p].size() > 1) {
		for (int i = 1; i < (int)pav[p].size(); i++) {
			Union(pav[p][i - 1], pav[p][i]);
		}
	}
	for (int p = 1; p < V; p++) if (pav[p].size()) {
		gf[p] = Find(pav[p][0]);
	}
	for (int i = 1; i <= n; i++) {
		int rt = Find(i);
		set<int> cur;
		cur.insert(rt);
		for (int q : vap1[i]) if (gf[q]) {
			cur.insert(gf[q]);
		}
		if (cur.size() > 1) {
			for (int x : cur) for (int y : cur) if (x != y) {
				st.emplace(min(x, y), max(x, y));
			}
		}
	}
	while (q--) {
		int s, t;
		scanf("%d%d", &s, &t);
		if (Find(s) == Find(t)) {
			puts("0");
			continue;
		}
		if (a[s] % 2 == 0 || a[t] % 2 == 0) {
			puts("1");
			continue;
		}
		s = Find(s), t = Find(t);
		if (st.count(make_pair(min(s, t), max(s, t)))) {
			puts("1");
			continue;
		}
		puts("2");
	}
	return 0;
}