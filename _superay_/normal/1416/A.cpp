#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const int INF = 0x3f3f3f3f;
int n, a[N], ans[N];
vector<int> buck[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) buck[i].clear(), ans[i] = INF;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), buck[a[i]].push_back(i);
		for (int i = 1; i <= n; i++) if (buck[i].size()) {
			int mx = max(buck[i][0], n - buck[i].back() + 1);
			for (int j = 1; j < (int)buck[i].size(); j++) {
				mx = max(mx, buck[i][j] - buck[i][j - 1]);
			}
			ans[mx] = min(ans[mx], i);
		}
		for (int i = 2; i <= n; i++) ans[i] = min(ans[i], ans[i - 1]);
		for (int i = 1; i <= n; i++) printf("%d ", ans[i] == INF ? -1 : ans[i]);
		puts("");
	}
	return 0;
}