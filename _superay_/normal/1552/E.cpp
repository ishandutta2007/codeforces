#include <bits/stdc++.h>
using namespace std;
int n, k, c[10005], ans[105][2], vis[105];
vector<int> vec[105];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n * k; i++) scanf("%d", &c[i]), vec[c[i]].push_back(i);
	for (int l = 1; l <= n; l += (k - 1)) {
		int r = min(n, l + k - 2);
		for (int t = 1; t <= r - l + 1; t++) {
			int mx = -1, fr = -1;
			for (int j = l; j <= r; j++) if (!vis[j]) {
				if (mx < vec[j][vec[j].size() - 2]) {
					mx = vec[j][vec[j].size() - 2];
					fr = j;
				}
			}
			ans[fr][0] = vec[fr][vec[fr].size() - 2];
			ans[fr][1] = vec[fr].back();
			vis[fr] = 1;
			for (int j = l; j <= r; j++) if (!vis[j]) vec[j].pop_back();
		}
	}
	for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}