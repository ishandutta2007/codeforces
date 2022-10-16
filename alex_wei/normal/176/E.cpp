#include <bits/stdc++.h>
using namespace std;

const int K = 17;
const int N = 1e5 + 5;
int n, q, dn, lg[N], dfn[N], rdep[N], fa[N], mi[K][N];
vector <pair <int, int>> e[N];
long long ans, dep[N];
int get(int x, int y) {return rdep[x] < rdep[y] ? x : y;}
void dfs(int id, int f) {
	mi[0][dfn[id] = ++dn] = id, fa[id] = f, rdep[id] = rdep[f] + 1;
	for(auto it : e[id]) {
		int to = it.first;
		if(to == f) continue;
		dep[to] = dep[id] + it.second, dfs(to, id);
	}
}
int lca(int u, int v) {
	if(u == v) return u;
	if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
	int d = lg[v - (++u) + 1];
	return fa[get(mi[d][u], mi[d][v - (1 << d) + 1])];
}
long long dis(int u, int v) {return dep[u] + dep[v] - dep[lca(u, v)] * 2;}
int main() {
	cin >> n;
	for(int i = 1; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[x].push_back({y, z}), e[y].push_back({x, z});
	}
	dfs(1, 0), cin >> q;
	for(int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 1; i <= lg[n]; i++)
		for(int j = 1; j + (1 << i) - 1 <= n; j++)
			mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
	set <int> s;
	for(int i = 1, x; i <= q; i++) {
		char op; cin >> op;
		if(op == '?') cout << ans / 2 << endl;
		else if(op == '+') {
			cin >> x;
			auto it = s.lower_bound(dfn[x]);
			if(it != s.end() && it != s.begin()) ans -= dis(mi[0][*--it], mi[0][*it]), it++;
			else if(s.size()) ans -= dis(mi[0][*s.begin()], mi[0][*--s.end()]);
			if(it != s.end()) ans += dis(mi[0][*it], x);
			else if(s.size()) ans += dis(mi[0][*s.begin()], x);
			if(it != s.begin()) ans += dis(mi[0][*--it], x);
			else if(s.size()) ans += dis(mi[0][*--s.end()], x);
			s.insert(dfn[x]);
		}
		else {
			cin >> x, s.erase(dfn[x]);
			auto it = s.lower_bound(dfn[x]);
			if(it != s.end()) ans -= dis(x, mi[0][*it]);
			else if(s.size()) ans -= dis(x, mi[0][*s.begin()]);
			if(it != s.begin()) ans -= dis(x, mi[0][*--it]), it++;
			else if(s.size()) ans -= dis(x, mi[0][*--s.end()]); 
			if(it != s.end() && it != s.begin()) ans += dis(mi[0][*--it], mi[0][*it]);
			else if(s.size()) ans += dis(mi[0][*s.begin()], mi[0][*--s.end()]);
		}
	}
	return 0;
}