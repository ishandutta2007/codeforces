#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n, k, a[N][2];
bool vis[N * 2];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= k; i++) {
			scanf("%d%d", &a[i][0], &a[i][1]);
			if (a[i][0] > a[i][1]) swap(a[i][0], a[i][1]);
			vis[a[i][0]] = vis[a[i][1]] = 1;
		}
		vector<int> ret;
		for (int i = 1; i <= n * 2; i++)
			if (!vis[i]) ret.push_back(i);
		int now = k;
		for (int i = 0; i < n - k; i++) {
			now++;
			a[now][0] = ret[i];
			a[now][1] = ret[i + n - k];
		}
		int ans = 0;
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++) {
				if (a[i][1] < a[j][0] || a[j][1] < a[i][0]) continue;
				if (a[i][0] < a[j][0] && a[i][1] > a[j][1] || a[j][0] < a[i][0] && a[j][1] > a[i][1]) continue;
				ans++;
			}
		printf("%d\n", ans);
	}
	return 0;
}