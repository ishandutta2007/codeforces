#include <bits/stdc++.h>
#define pb push_back
using std::max; using std::min; using std::vector;
const int N = 100005;
int T, n, m, a[N], b[N], c[N], ans[N];
vector<int> v[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= m; i++) scanf("%d", &c[i]);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i <= n; i++)
			if (a[i] != b[i]) v[b[i]].pb(i);
		if (v[c[m]].empty()) {
			int ok = 0;
			for (int i = 1; i <= n; i++) if (b[i] == c[m]) { ans[m] = i; ok = 1; break; }
			if (!ok) { puts("NO"); continue; }
		}
		else ans[m] = v[c[m]][v[c[m]].size() - 1], v[c[m]].pop_back();
		for (int i = m - 1; i; i--) {
			if (v[c[i]].empty()) ans[i] = ans[m];
			else ans[i] = v[c[i]][v[c[i]].size() - 1], v[c[i]].pop_back();
		}
		int ok = 1;
		for (int i = 1; i <= n; i++) if (v[i].size()) { ok = 0; break; }
		if (!ok) { puts("NO"); continue; }
		puts("YES");
		for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}