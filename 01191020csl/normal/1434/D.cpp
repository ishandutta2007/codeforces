#include<bits/stdc++.h>
using namespace std;
int head[500001], ver[1000001], edge[1000001], nxt[1000001], sz;
void addedge(int u, int v, int w) {
	ver[++sz] = v, edge[sz] = w, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, edge[sz] = w, nxt[sz] = head[v], head[v] = sz;
}
int vis[500001];
int getroot(int x) {
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(x);
	int ans = x;
	vis[x] = 1;
	while (q.size()) {
		int u = q.front();
		q.pop(), ans = u;
		for (int i = head[u]; i; i = nxt[i])
			if (!vis[ver[i]]) {
				vis[ver[i]] = 1;
				q.push(ver[i]);
			}
	}
	return ans;
}
int n;
struct solve {
	struct node {
		int max0, max1, tag;
	}nd[2000001];
	int fa[500001], dep[500001], st[500001], seq[500001], ed[500001], val[500001], tot;
	void build(int p, int l, int r) {
		if (l == r) {
			if (val[seq[l]]) nd[p].max1 = dep[seq[l]], nd[p].max0 = 0;
			else nd[p].max0 = dep[seq[l]], nd[p].max1 = 0;
			return;
		}
		int mid = (l + r) / 2;
		build(p * 2, l, mid), build(p * 2 + 1, mid + 1, r);
		nd[p].max0 = max(nd[p*2].max0, nd[p*2+1].max0);
		nd[p].max1 = max(nd[p*2].max1, nd[p*2+1].max1);
	}
	void pushdown(int p) {
		if (!nd[p].tag) return;
		swap(nd[p*2].max0, nd[p*2].max1);
		swap(nd[p*2+1].max0, nd[p*2+1].max1);
		nd[p*2].tag ^= 1, nd[p*2+1].tag ^= 1, nd[p].tag = 0;
	}
	void modify(int p, int l, int r, int l0, int r0) {
		if (l >= l0 && r <= r0) {
			swap(nd[p].max0, nd[p].max1);
			nd[p].tag ^= 1;
			return;
		}
		pushdown(p);
		int mid = (l + r) / 2;
		if (l0 <= mid) modify(p * 2, l, mid, l0, r0);
		if (r0 > mid) modify(p * 2 + 1, mid + 1, r, l0, r0);
		nd[p].max0 = max(nd[p*2].max0, nd[p*2+1].max0);
		nd[p].max1 = max(nd[p*2].max1, nd[p*2+1].max1);
	}
	void dfs(int x) {
		st[x] = ++tot, seq[tot] = x;
		for (int i = head[x]; i; i = nxt[i])
			if (fa[x] != ver[i]) {
				fa[ver[i]] = x;
				dep[ver[i]] = dep[x] + 1;
				val[ver[i]] = val[x] ^ edge[i];
				dfs(ver[i]);
			}
		ed[x] = tot;
	}
	void init(int x) {
		dfs(x);
		build(1, 1, n);
	}
	int modify(int u, int v) {
		if (fa[v] == u) swap(u, v);
		modify(1, 1, n, st[u], ed[u]);
		return nd[1].max0;
	}
}s1, s2;
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addedge(u, v, w);
	}
	int r1 = getroot(1), r2 = getroot(r1);
	s1.init(r1), s2.init(r2);
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		cout << max(s1.modify(ver[2*x-1], ver[2*x]), s2.modify(ver[2*x-1], ver[2*x])) << endl;
	}
}