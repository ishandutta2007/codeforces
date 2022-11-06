#include <bits/stdc++.h>
using std::vector;
const int N = 100005;
int T, n, m, vis[N], ans[N];
vector<int> v[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) vis[i] = 0;
		for (int i = 1; i <= m; i++) {
			v[i].clear(); ans[i] = 0;
			int x; scanf("%d", &x);
			for (int j = 0; j < x; j++) {
				int y; scanf("%d", &y);
				v[i].push_back(y);
			}
		}
		for (int i = 1; i <= m; i++)
			if (v[i].size() == 1) vis[v[i][0]]++;
		int ok = 1;
		for (int i = 1; i <= n; i++)
			if (vis[i] > (m + 1) / 2) { ok = 0; break; }
		if (!ok) { puts("NO"); continue; }
		puts("YES");
		for (int i = 1; i <= m; i++)
			if (v[i].size() == 1) ans[i] = v[i][0];
		else {
			for (int j = 0; j < v[i].size(); j++)
				if (vis[v[i][j]] < (m + 1) / 2) {
					if (ans[i] == 0 || vis[v[i][j]] < vis[ans[i]])
						ans[i] = v[i][j];
				}
			vis[ans[i]]++;
		}
		for (int i = 1; i <= m; i++)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}