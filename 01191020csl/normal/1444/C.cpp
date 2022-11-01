#include<bits/stdc++.h>
using namespace std;
int c[500001];
int head[500001], ver[1000001], nxt[1000001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
struct edge {
	int u, v;
}e[500001];
bool operator<(const edge &a, const edge &b) {
	if (c[a.u] == c[b.u]) return c[a.v] < c[b.v];
	return c[a.u] < c[b.u];
}
int fa[500001], dis[500001], size[500001], res[500001];
pair<int, int> getfa(int x) {
	if (!fa[x]) return make_pair(x, 0);
	pair<int, int> tmp = getfa(fa[x]);
	if (dis[x]) tmp.second ^= 1;
	return tmp;
}
vector<pair<int*, int> > change;
bool link(int x, int y) {
	pair<int, int> x0 = getfa(x), y0 = getfa(y);
	if (x0 == y0) return 0;
	if (x0.first == y0.first) return 1;
	if (size[x0.first] > size[y0.first]) swap(x0, y0);
	change.push_back(make_pair(&fa[x0.first], fa[x0.first]));
	change.push_back(make_pair(&size[y0.first], size[y0.first]));
	change.push_back(make_pair(&dis[x0.first], dis[x0.first]));
	fa[x0.first] = y0.first, size[y0.first] += size[x0.first];
	if (x0.second == y0.second) dis[x0.first] = 1;
	return 1;
}
bool work(int l, int r) {
	bool ans = 1;
	for (int i = l; i <= r; i++)
		ans &= link(e[i].u, e[i].v);
	while (change.size()) *((change.end()-1)->first) = (change.end()-1)->second, change.pop_back();
	return ans;
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> c[i];
	int tot = 0;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (c[u] == c[v]) addedge(u, v);
		else {
			++tot;
			if (c[u] > c[v]) swap(u, v);
			e[tot].u = u, e[tot].v = v;
		}
	}
	sort(e + 1, e + tot + 1);
	for (int i = 1; i <= k; i++) res[i] = 1;
	for (int i = 1; i <= n; i++) size[i] = 1;
	for (int i = 1; i < sz; i += 2)
		if (!link(ver[i], ver[i+1])) res[c[ver[i]]] = 0;
	change.clear();
	int last = 0;
	long long num = 0;
	for (int i = 1; i <= k; i++)
		if (res[i]) ++num;
	num = num*(num-1)/2;
	for (int i = 1; i <= tot; i++)
		if (i == tot || c[e[i].u] != c[e[i+1].u] || c[e[i].v] != c[e[i+1].v]) {
			if (res[c[e[i].u]] && res[c[e[i].v]] && !work(last + 1, i)) --num;
			last = i;
		}
	cout << num << endl;
}