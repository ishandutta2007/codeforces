#include <bits/stdc++.h>
using std::sort; using std::vector; using std::pair; using std::make_pair;
typedef long long LL;
const int N = 1005, M = 1000005;
int n, T, a[N*2], b[M];
vector<pair<int, int> > ans;
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n*2; i++) scanf("%d", &a[i]);
		sort(a+1, a+2*n+1);
		int ok = 0;
		for (int i = 1; i < n*2; i++) {
			int flag = 1; ans.clear();
			for (int j = 1; j < n*2; j++) if (j != i) b[a[j]]++;
			for (int j = n*2 - 1, last = a[n*2]; j; j--) {
				if (!b[a[j]]) continue;
				b[a[j]]--;
				int t = last - a[j];
				if (!b[t]) { flag = 0; break; }
				b[t]--; last = a[j];
				ans.push_back(make_pair(t, a[j]));
			}
			for (int j = 1; j <= n*2; j++) b[a[j]] = 0;
			if (flag) { ok = i; break; }
		}
		if (!ok) puts("NO");
		else {
			puts("YES");
			printf("%d\n%d %d\n", a[ok] + a[n*2], a[ok], a[n*2]);
			for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
	return 0;
}