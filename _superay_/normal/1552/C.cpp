#include <bits/stdc++.h>
using namespace std;
int n, k, X[105], Y[105], vis[205];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= 2 * n; i++) vis[i] = 0;
		for (int i = 1; i <= k; i++) scanf("%d%d", &X[i], &Y[i]), vis[X[i]] = vis[Y[i]] = 1;
		vector<int> vec;
		for (int i = 1; i <= 2 * n; i++) if (!vis[i]) vec.push_back(i);
		for (int i = k + 1; i <= n; i++) {
			X[i] = vec[i - k - 1];
			Y[i] = vec[i - k - 1 + vec.size() / 2];
		}
		for (int i = 1; i <= n; i++) if (X[i] > Y[i]) swap(X[i], Y[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) {
			if (X[i] < X[j] && X[j] < Y[i] && Y[i] < Y[j]) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}