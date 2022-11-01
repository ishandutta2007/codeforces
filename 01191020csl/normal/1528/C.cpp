#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	int num = 0;
	while (isdigit(c)) {
		num = num * 10 + c - '0';
		c = getchar();
	}
	return num;
}
struct tree {
	int head[300001], ver[600001], nxt[600001], sz;
	void addedge(int u, int v) {
		ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
		ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
	}
	void clear(int n) {
		for (int i = 1; i <= n; i++) head[i] = 0;
		sz = 0;
	}
}g1, g2;
int fa[300001], st[300001], size[300001], tot;
void dfs(int x) {
	st[x] = ++tot, size[x] = 1;
	for (int i = g2.head[x]; i; i = g2.nxt[i])
		if (fa[x] != g2.ver[i]) {
			fa[g2.ver[i]] = x;
			dfs(g2.ver[i]);
			size[x] += size[g2.ver[i]];
		}
}
int n, ans, now;
long long c1[300001], c2[300001];
void add(int x, int op, long long c[]) {
	for (; x <= n; x += x & -x) c[x] += op;
}
long long query(int x, long long c[]) {
	long long ans = 0;
	for (; x; x -= x & -x) ans += c[x];
	return ans;
}
void solve(int x) {
	int flag = 0, val = 0;
	if (query(st[x]+size[x]-1, c2) == query(st[x]-1, c2)) {
		flag = 1;
		val = query(st[x], c1);
		if (val) --now, add(st[val], -val, c1), add(st[val] + size[val], val, c1), add(st[val], -1, c2);
		add(st[x], x, c1), add(st[x] + size[x], -x, c1), add(st[x], 1, c2), ans = max(ans, ++now);
	}
	for (int i = g1.head[x]; i; i = g1.nxt[i])
		if (fa[x] != g1.ver[i]) {
			fa[g1.ver[i]] = x;
			solve(g1.ver[i]);
		}
	if (flag) {
		--now, add(st[x], -x, c1), add(st[x] + size[x], x, c1), add(st[x], -1, c2);
		if (val) ++now, add(st[val], val, c1), add(st[val] + size[val], -val, c1), add(st[val], 1, c2);
	}
}
int main() {
	int t = read();
	while (t--) {
		n = read();
		for (int i = 2; i <= n; i++) g1.addedge(read(), i);
		for (int i = 2; i <= n; i++) g2.addedge(read(), i);
		tot = 0, dfs(1);
		for (int i = 1; i <= n; i++) fa[i] = 0;
		ans = now = 0;
		solve(1);
		for (int i = 1; i <= n; i++) fa[i] = 0;
		cout << ans << endl;
		g1.clear(n), g2.clear(n);
	}
}