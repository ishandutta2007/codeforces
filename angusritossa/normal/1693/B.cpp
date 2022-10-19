#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 200010
vector<int> adj[MAXN];
int l[MAXN], r[MAXN], ans;
int dfs(int a) {
	int sum = 0;
	for (auto b: adj[a]) {
		sum += dfs(b);
		sum = min(sum, r[a]);
	}
	D("at %d, mxChild = %d, l=%d, r=%d\n", a, sum, l[a], r[a]);
	if (sum < l[a]) {
		sum = r[a];
		ans++;
	}
	return min(sum, r[a]);
}
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 2; i <= n; i++) {
		int p;
		scanf("%d", &p);
		adj[p].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &l[i], &r[i]);
	}
	ans = 0;
	dfs(1);
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}