#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
void write(int num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
struct node {
	int num, nxt;
}nd[500001];
int cnt = 1;
int head[100001], cur[100001], ver[1000001], nxt[1000001], sz = 1;
int deg[100001], vis[1000001];
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
	++deg[u], ++deg[v];
}
int dfs(int &p, int x, int t, int op) {
	if (op) p = ++cnt, nd[p].num = x;
	if (x == t && op) return p;
	for (int &i = cur[x]; i; i = nxt[i])
		if (!vis[i] && !vis[i^1]) {
			vis[i] = vis[i^1] = 1;
			--deg[x], --deg[ver[i]];
			return dfs(nd[p].nxt, ver[i], t, 1);
		}
}
int main() {
	int n, m;
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int u, v;
		u = read(), v = read();
		addedge(u, v);
	}
	vector<int> odd;
	for (int i = 1; i <= n; i++)
		if (deg[i] & 1) odd.push_back(i);
	while (odd.size()) {
		int u = *(odd.end()-1);
		odd.pop_back();
		int v = *(odd.end()-1);
		odd.pop_back();
		addedge(u, v), ++m;
	}
	if (m & 1) addedge(1, 1), ++m;
	write(m), putchar('\n');
	nd[1].num = 1;
	int p = 1, x = 0;
	memcpy(cur, head, sizeof(int) * 100001);
	while (++x, p) {
		while (deg[nd[p].num]) {
			int np = nd[p].nxt, ed = dfs(p, nd[p].num, nd[p].num, 0);
			nd[ed].nxt = np;
		}
		if (nd[p].nxt) {
			if (x & 1) write(nd[p].num), putchar(' '), write(nd[nd[p].nxt].num), putchar('\n');
			else write(nd[nd[p].nxt].num), putchar(' '), write(nd[p].num), putchar('\n');
		}
		p = nd[p].nxt;
	}
}