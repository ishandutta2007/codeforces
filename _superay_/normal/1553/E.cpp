#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, m, p[N], cnt[N], q[N], vis[N], g[N];
inline bool check(int k) {
	for (int i = 1; i <= n; i++) vis[i] = 0;
	for (int i = 1; i <= n; i++) {
		q[i] = (i - 1 - k + n) % n + 1;
		g[p[i]] = q[i];
	}
	int c = 0;
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		int j = i;
		while (!vis[j]) vis[j] = 1, j = g[j];
		c++;
	}
	return n - c <= m;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
			cnt[(i - p[i] + n) % n]++;
		}
		vector<int> ans;
		for (int i = 0; i < n; i++) if (cnt[i] * 3 >= n) {
			if (check(i)) ans.push_back(i);
		}
		printf("%d", (int)ans.size());
		for (int x : ans) printf(" %d", x);
		printf("\n");
	}
	return 0;
}