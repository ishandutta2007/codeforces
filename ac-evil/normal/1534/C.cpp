#include <bits/stdc++.h>
typedef long long ll;
const int N = 4e5 + 5, P = 1e9 + 7;
int T, n, a[N], b[N], ib[N], vis[N];
void dfs(int x) {
	if (vis[b[x]]) return;
	vis[b[x]] = 1;
	dfs(ib[a[x]]);
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]), ib[b[i]] = i;
		int ok = 1;
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
			if (a[i] == b[i]) { ok = 0; break; }
		}
		if (!ok) { puts("0"); continue; }
		int cnt = 0, ans = 1;
		for (int i = 1; i <= n; i++)
			if (!vis[b[i]]) dfs(i), cnt++;
		for (int i = 1; i <= cnt; i++) ans = ans * 2 % P;
		printf("%d\n", ans);
	}
}