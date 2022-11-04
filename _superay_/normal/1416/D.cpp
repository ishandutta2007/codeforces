#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int M = 300005;
const int Q = 500005;
int n, m, q, p[N], fa[N], eu[M], ev[M], ew[M], tr[M], ord[M], ty[Q], tv[Q];
set<int> st[N];
inline bool cmp(int i, int j) {
	return ew[i] > ew[j];
}
int Find(int x) {
	return x == fa[x] ? x : Find(fa[x]);
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &eu[i], &ev[i]);
		ew[i] = Q;
		ord[i] = i;
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &ty[i], &tv[i]);
		if (ty[i] == 2) ew[tv[i]] = i;
	}
	sort(ord + 1, ord + 1 + m, cmp);
	for (int i = 1; i <= n; i++) fa[i] = i, st[i].insert(p[i]);
	vector<pair<int, int> > stkfa;
	vector<int> stkp;
	for (int i = 1; i <= m; i++) {
		int u = eu[ord[i]], v = ev[ord[i]];
		int a = Find(u), b = Find(v);
		if (a != b) {
			if (st[a].size() > st[b].size()) swap(a, b);
			fa[a] = b;
			stkfa.emplace_back(a, b);
			stkp.push_back(0);
			while (st[a].size()) {
				st[b].insert(*st[a].begin());
				stkp.push_back(*st[a].begin());
				st[a].erase(st[a].begin());
			}
			tr[ord[i]] = 1;
		}
	}
	for (int i = 1; i <= q; i++) {
		if (ty[i] == 1) {
			int u = Find(tv[i]);
			if (st[u].size()) {
				auto it = st[u].end();
				--it;
				printf("%d\n", *it);
				st[u].erase(it);
			} else puts("0");
		} else {
			if (!tr[tv[i]]) continue;
			int a = stkfa.back().first, b = stkfa.back().second;
			stkfa.pop_back();
			fa[a] = a;
			int x;
			while (true) {
				x = stkp.back();
				stkp.pop_back();
				if (!x) break;
				if (st[b].find(x) != st[b].end()) {
					st[b].erase(x);
					st[a].insert(x);
				}
			}
		}
	}
	return 0;
}