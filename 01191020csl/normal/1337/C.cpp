#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int head[200001], ver[400001], nxt[400001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
int ans[200001], fa[200001], dep[200001], size[200001];
void dfs(int x) {
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i]) {
			fa[ver[i]] = x;
			dep[ver[i]] = dep[x] + 1;
			dfs(ver[i]);
			size[x] += size[ver[i]];
		}
	ans[x] = dep[x] - size[x]++;
}
int main() {
	int n, k;
	n = read(), k = read();
	for (int i = 1; i < n; i++) {
		int u, v;
		u = read(), v = read();
		addedge(u, v);
	}
	dfs(1);
	sort(ans + 1, ans + n + 1);
	long long res = 0;
	for (int i = n; i >= n - k + 1; i--) res += ans[i];
	cout << res << endl;
}