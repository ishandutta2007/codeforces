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
int head[1000001], ver[2000001], nxt[2000001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
int fa[1000001], dep[1000001], len[1000001], son[1000001];
void dfs(int x) {
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i]) {
			fa[ver[i]] = x;
			dep[ver[i]] = dep[x] + 1;
			dfs(ver[i]);
			if (len[ver[i]] > len[son[x]]) son[x] = ver[i];
		}
	len[x] = len[son[x]] + 1;
}
int f[1000001], tmp[1000001], ans[1000001];
int cnt = 0;
void dp(int x) {
	f[x] = ++cnt;
	tmp[f[x]] = 1, ans[x] = 0;
	if (son[x]) {
		dp(son[x]);
		if (tmp[f[son[x]]+ans[son[x]]] > 1) ans[x] = ans[son[x]] + 1;
	}
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i] && son[x] != ver[i]) {
			dp(ver[i]);
			int p = ver[i], q = son[x], id = 1;
			while (p) {
				tmp[f[q]] += tmp[f[p]];
				if (tmp[f[q]] > tmp[f[x]+ans[x]] || (tmp[f[q]] == tmp[f[x]+ans[x]] && id < ans[x])) ans[x] = id;
				p = son[p], q = son[q], ++id;
			}
		}
}			
int main() {
	int n;
	n = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		addedge(u, v);
	}
	dfs(1);
	dp(1);
	for (int i = 1; i <= n; i++) write(ans[i]), putchar('\n');
}