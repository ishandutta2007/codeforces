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
int u[50001], v[50001], c[50001], t[50001];
vector<int> e[50001];
bool cmp(int a, int b) {
	return c[a] < c[b];
}
int head[500001], ver[2000001], nxt[2000001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
}
int dfn[500001], low[500001];
int vis[500001], stk[500001];
int now, top, cnt, scc[500001];
void tarjan(int x) {
	dfn[x] = low[x] = ++now;
	stk[++top] = x, vis[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (!vis[ver[i]]) tarjan(ver[i]), low[x] = min(low[x], low[ver[i]]);
		else if (vis[ver[i]] == 1)low[x] = min(low[x], dfn[ver[i]]);
	if (dfn[x] == low[x]) {
		scc[x] = ++cnt, vis[x] = 2;
		while (stk[top] != x) {
			scc[stk[top]] = cnt;
			vis[stk[top]] = 2;
			--top;
		}
		--top;
	}
}
bool _2sat(int n) {
	now = cnt = 0;
	for (int i = 1; i <= n * 2; i++) vis[i] = 0;
	for (int i = 1; i <= n * 2; i++)
		if (!vis[i]) tarjan(i);
	for (int i = 1; i <= n; i++)
		if (scc[i] == scc[i+n]) return 0;
	return 1;
}
int main() {
	int n, m;
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u[i] = read(), v[i] = read(), c[i] = read(), t[i] = read();
		e[u[i]].push_back(i), e[v[i]].push_back(i);
	}
	int tot = m;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		sort(e[i].begin(), e[i].end(), cmp);
		for (int j = 1; j < e[i].size(); j++)
			if (c[e[i][j]] == c[e[i][j-1]]) {
				if (tmp) {
					puts("No");
					return 0;
				}
				tmp = j;
			}
		if (tmp) {
			addedge(e[i][tmp], m*5+e[i][tmp-1]);
			addedge(e[i][tmp-1], m*5+e[i][tmp]);
			addedge(m*5+e[i][tmp-1], e[i][tmp]);
			addedge(m*5+e[i][tmp], e[i][tmp-1]);
			for (int j = 0; j < e[i].size(); j++)
				if (j != tmp && j != tmp-1) addedge(e[i][j], m*5+e[i][j]);
		}
		else {
			for (int j = 1; j < e[i].size(); j++) {
				addedge(j+tot, j+1+tot);
				addedge(j+1+tot+e[i].size(), j+tot+e[i].size());
				addedge(j+1+tot+m*5, j+tot+m*5);
				addedge(j+tot+e[i].size()+m*5, j+1+tot+e[i].size()+m*5);
			}
			for (int j = 0; j < e[i].size(); j++) {
				addedge(e[i][j], j+1+tot);
				addedge(e[i][j], j+1+tot+e[i].size());
				addedge(j+1+tot+m*5, e[i][j]+m*5);
				addedge(j+1+tot+e[i].size()+m*5, e[i][j]+m*5);
			}
			for (int j = 1; j < e[i].size(); j++) {
				addedge(e[i][j], j+tot+m*5);
				addedge(e[i][j-1], j+1+tot+e[i].size()+m*5);
				addedge(j+tot, e[i][j]+m*5);
				addedge(j+1+tot+e[i].size(), e[i][j-1]+m*5);
			}
		}
		tot += e[i].size() * 2;
	}
	int tmp = sz;
	int l = 0, r = 1000000001;
	while (l < r) {
		int mid = (l + r) / 2;
		for (int i = 1; i <= m * 10; i++)
			while (head[i] > tmp) head[i] = nxt[head[i]];
		sz = tmp;
		for (int i = 1; i <= m; i++)
			if (t[i] > mid) addedge(i, i+m*5);
		if (_2sat(m * 5)) r = mid;
		else l = mid + 1;
	}
	if (l == 1000000001) {
		puts("No");
		return 0;
	}
	puts("Yes");
	write(l), putchar(' ');
	for (int i = 1; i <= m * 10; i++)
		while (head[i] > tmp) head[i] = nxt[head[i]];
	sz = tmp;
	for (int i = 1; i <= m; i++)
		if (t[i] > l) addedge(i, i+m*5);
	_2sat(m * 5);
	int res = 0;
	for (int i = 1; i <= m; i++)
		if (scc[i] < scc[i+m*5]) ++res;
	write(res), putchar('\n');
	for (int i = 1; i <= m; i++)
		if (scc[i] < scc[i+m*5]) write(i), putchar(' ');
	putchar('\n');
}