#include <functional>
#include <iostream>
#include <cstring>
#include <vector>
#define int long long // add this line
using namespace std;
const int N = 1e6 + 5;
struct dsu1 {
	int fa[N], t[N], sz[N];
	void init() {for(int i = 0; i < N; i++) fa[i] = i, sz[i] = 1;}
	int find(int x) {return fa[x] == x ? x : find(fa[x]);}
	void merge(int u, int v, int _t) {if(sz[u = find(u)] < sz[v = find(v)]) swap(u, v); fa[v] = u, sz[u] += sz[v], t[v] = _t;} // add .. = find(..)
} b;
int n, m, node, cnt, hd[N], nxt[N], to[N];
void add(int u, int v) {nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v;}
struct dsu2 {
	int fa[N], sz[N];
	void init() {for(int i = 0; i < N; i++) fa[i] = i, sz[i] = i <= n;}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	void merge(int u, int v) {int p = ++node; add(p, u = find(u)), add(p, v = find(v)), sz[p] = sz[u] + sz[v], fa[u] = fa[v] = p;}
} a;
int qcnt, latest[N], ans[N], lft[N], rt[N];
vector <int> modi[N], que[N];
signed main() {
	scanf("%lld%lld", &n, &m), node = n, a.init(), b.init();
	for(int i = 1, x, y; i <= m; i++) {
		char op[2];
		scanf("%s%lld", op, &x);
		if(*op == 'U') scanf("%lld", &y), a.merge(x, y);
		if(*op == 'M') scanf("%lld", &y), b.merge(x, y, i);
		if(*op == 'A') modi[a.find(x)].push_back(i);
		if(*op == 'Z') latest[b.find(x)] = i; // x -> b.find(x)
		if(*op == 'Q') {
			int time = 0, mertime = 0;
			for(int i = x; ; mertime = b.t[i], i = b.fa[i]) {
				if(latest[i] > mertime) time = latest[i];
				if(i == b.fa[i]) break;
			}
			rt[++qcnt] = i, lft[qcnt] = time + 1, que[x].push_back(qcnt);
		}
	}
	static int c[N];
	memset(c, 0, sizeof(c));
	function <void(int, int)> add = [&](int x, int v) {while(x <= m) c[x] += v, x += x & -x;}; // n -> m
	function <int(int)> sum = [&](int x) {int s = 0; while(x) s += c[x], x -= x & -x; return s;};
	function <int(int, int)> query = [&](int l, int r) {return sum(r) - sum(l - 1);};
	function <void(int)> dfs = [&](int id) {
		for(auto it : modi[id]) add(it, a.sz[id]);
		if(id <= n) for(auto it : que[id]) ans[it] = query(lft[it], rt[it]);
		for(int i = hd[id]; i; i = nxt[i]) dfs(to[i]);
		for(auto it : modi[id]) add(it, -a.sz[id]);
	};
	for(int i = 1; i <= node; i++) if(a.fa[i] == i) dfs(i);
	for(int i = 1; i <= qcnt; i++) printf("%lld\n", ans[i]); // %d -> %lld
	return 0;
}