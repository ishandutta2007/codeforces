#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int head[100001], ver[200001], nxt[200001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
int l[100001], r[100001];
int ans[100001];
bool dfs(int x) {
	for (int i = head[x]; i; i = nxt[i]) {
		if (ans[ver[i]] == ans[x]) return 0;
		if (ans[ver[i]] == 3 - ans[x]) continue;
		if (ans[ver[i]] = 3 - ans[x], !dfs(ver[i])) return 0;
	}
	return 1;
}
int main() {
	int t, T;
	t = read(), T = read();
	int n, m, n1 = 0, n2 = 0x3f3f3f3f;
	n = read(), m = read();
	for (int i = 1; i <= n; i++) l[i] = read(), r[i] = read(), n1 = max(n1, l[i]), n2 = min(n2, r[i]);
	int l1 = n1, r1 = n1, l2 = n2, r2 = n2;
	if (n1 + n2 < t) r1 = t - n2;
	if (n1 + n2 > T) l2 = T - n1;
	if (l2 < 0) {
		puts("IMPOSSIBLE");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (!(l[i] <= l1 && r[i] >= r1)) ans[i] = 2;
		if (!(l[i] <= l2 && r[i] >= r2)) {
			if (ans[i]) {
				puts("IMPOSSIBLE");
				return 0;
			}
			ans[i] = 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		u = read(), v = read();
		addedge(u, v);
	}
	for (int i = 1; i <= n; i++)
		if (ans[i] && !dfs(i)) {
			puts("IMPOSSIBLE");
			return 0;
		} 
	for (int i = 1; i <= n; i++)
		if (!ans[i])
			if (ans[i] = 1, !dfs(i)) {
				puts("IMPOSSIBLE");
				return 0;
			}
	puts("POSSIBLE");
	cout << r1 << ' ' << l2 << endl;
	for (int i = 1; i <= n; i++) putchar(ans[i]+'0');
	putchar('\n');
}