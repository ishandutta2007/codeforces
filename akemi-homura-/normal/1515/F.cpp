#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, m, cc, fa[N];
long long a[N], x;
vector<pair<int, int> > G[N];
set<pair<long long, int> > st;
int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
int main() {
	scanf("%d%d%lld", &n, &m, &x);
	long long sum = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), fa[i] = i, sum += a[i], st.emplace(a[i], i);
	if (sum < x * (n - 1)) {
		puts("NO");
		return 0;
	}
	cc = n;
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].emplace_back(v, i);
		G[v].emplace_back(u, i);
	}
	puts("YES");
	while (cc > 1) {
		int u = prev(st.end()) -> second;
		st.erase(prev(st.end()));
		while (G[u].size() && Find(G[u].back().first) == u) G[u].pop_back();
		int v = Find(G[u].back().first);
		assert(a[u] + a[v] >= x);
		a[u] = a[u] + a[v] - x;
		st.erase(make_pair(a[v], v));
		st.emplace(a[u], u);
		printf("%d\n", G[u].back().second);
		G[u].pop_back();
		fa[v] = u;
		cc--;
		if (G[u].size() < G[v].size()) G[u].swap(G[v]);
		for (auto w : G[v]) G[u].push_back(w);
		vector<pair<int, int> >().swap(G[v]);
	}
	return 0;
}