#include <bits/stdc++.h>
using std::sort; using std::vector; using std::max;
const int N = 200000;
int T, n, a[N+5], b[N+5], f[N+5];
vector<int> fac[N+5];
int main() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= sqrt(i); j++) {
			if (i % j) continue;
			int x = j, y = i/j;
			if (x != i) fac[i].push_back(x);
			if (y != x && y != i) fac[i].push_back(y);
		}
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[a[i]]++;
		sort(a+1, a+n+1);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			f[a[i]] = b[a[i]];
			for (int j = 0; j < fac[a[i]].size(); j++)
				f[a[i]] = max(f[a[i]], f[fac[a[i]][j]] + b[a[i]]);
			ans = max(ans, f[a[i]]);
		}
		for (int i = 1; i <= n; i++) f[a[i]] = 0, b[a[i]] = 0;
		printf("%d\n", n-ans);
	}
	return 0;
}