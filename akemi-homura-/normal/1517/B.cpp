#include <bits/stdc++.h>
using namespace std;
int n, m, b[105][105], ans[105], vis[105];
vector<int> buck[105];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) buck[i].clear();
		vector<pair<int, pair<int, int> > > vec;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
			scanf("%d", &b[i][j]);
			vec.push_back(make_pair(b[i][j], make_pair(i, j)));
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < m; i++) {
			int x = vec[i].second.first, y = vec[i].second.second;
			buck[x].push_back(y);
		}
		int cur = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) vis[j] = 0;
			int cnt = cur;
			for (int j : buck[i]) vis[j] = 1, ans[++cnt] = b[i][j];
			cur = cnt;
			for (int j = 1; j <= m; j++) if (!vis[j]) {
				++cnt;
				if (cnt > m) cnt -= m;
				ans[cnt] = b[i][j];
			}
			for (int j = 1; j <= m; j++) printf("%d%c", ans[j], " \n"[j == m]);
		}
	}
	return 0;
}