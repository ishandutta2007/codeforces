#include<bits/stdc++.h>
#define MAXL 200000
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int head[400001], ver[1000010], vis[1000010], id[1000010], nxt[1000010], sz = 1;
int deg[400001];
void addedge(int u, int v, int i) {
	ver[++sz] = v, id[sz] = i, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, id[sz] = i, nxt[sz] = head[v], head[v] = sz;
	++deg[u], ++deg[v];
}
int res[400001], seq[400001], len;
bool dfs(int u) {
	for (int &i = head[u]; i; i = nxt[i])
		if (!vis[i] && !vis[i^1]) {
			vis[i] = vis[i^1] = 1;
			res[++len] = id[i];
			seq[len] = ver[i];
			dfs(ver[i]);
			return 1;
		}
	return 0;
}
int ans[200001];
int main() {
	int n = read();
	for (int i = 1; i <= n; i++) {
		int u, v;
		u = read(), v = read();
		addedge(u, v + MAXL, i);
	}
	for (int i = 1; i <= MAXL * 2; i++) 
		if (deg[i] & 1) addedge(i, 0, 0);
	for (int i = 1; i <= MAXL * 2; i++)
		while (dfs(i)) {
			assert(seq[len] == i);
			int tmp = 0, id = 0;
			for (int j = 1; j <= len; j++) 
				ans[res[j]] = seq[j] <= MAXL;
			len = 0;
		}
	for (int i = 1; i <= n; i++)
		if (ans[i]) putchar('b');
		else putchar('r');
	putchar('\n');
}