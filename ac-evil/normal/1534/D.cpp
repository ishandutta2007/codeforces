#include <bits/stdc++.h>
using std::vector; using std::pair;
const int N = 2e3 + 5;
int n, a[N], vis[N];
vector<int> dS[N];
vector<pair<int, int>> ans;
void qry(int x) {
	printf("? %d\n", x);
	fflush(stdout);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
}
void add(int x, int y) {
	if (vis[x] || vis[y]) return;
	ans.push_back({x, y});
}
void answer() {
	puts("!");
	for (int i = 0; i < n - 1; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	fflush(stdout);
}
int main() {
	scanf("%d", &n);
	qry(1);
	int mdep = 0;
	for (int i = 2; i <= n; i++) {
		dS[a[i]].push_back(i);
		mdep = std::max(mdep, a[i]);
		if (a[i] == 1) add(1, i);
	}
	vis[1] = 1;
	int odd = 0, even = 0;
	for (int i = 1; i <= mdep; i++)
		if (i & 1) odd += dS[i].size();
		else even += dS[i].size();
	int tag = 1;
	if (odd < even) tag = 0;
	for (int i = 1; i <= mdep; i++) {
		if (i % 2 == tag) continue;
		for (int j = 0; j < dS[i].size(); j++) {
			int u = dS[i][j]; qry(u);
			for (int k = 1; k <= n; k++)
				if (a[k] == 1) add(u, k);
			vis[u] = 1;
		}
	}
	answer();
	return 0;
}