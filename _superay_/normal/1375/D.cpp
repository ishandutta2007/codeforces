#include <bits/stdc++.h>
using namespace std;
int n, a[1005], vis[1005];
inline int getmex() {
	for (int i = 0; i <= n; i++) vis[i] = 0;
	for (int i = 1; i <= n; i++) vis[a[i]] = 1;
	for (int i = 0; ; i++) if (!vis[i]) return i;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		vector<int> ans;
		int tt;
		while ((tt = getmex()) < n) {
			a[tt + 1] = tt;
			ans.push_back(tt + 1);
		}
		for (int i = 1; i <= n; i++) if (a[i] != i - 1) {
			a[i] = n;
			ans.push_back(i);
			while ((tt = getmex()) < n) {
				a[tt + 1] = tt;
				ans.push_back(tt + 1);
			}
		}
		assert((int)ans.size() <= 2 * n);
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); i++) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}