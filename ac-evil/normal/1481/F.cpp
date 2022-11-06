#include <bits/stdc++.h>
#define chkmax(a, b) a = max(a, b)
using std::vector; using std::max; using std::min;
const int N = 100005;
int n, x, dep[N], ok[N], la[N], cnt[N], max_dep = 0, col[N];
vector<int> e[N], t[N], f[N];
void dfs(int u, int f) {
	t[dep[u] = dep[f] + 1].push_back(u);
	for (int i = 0; i < e[u].size(); i++)
		dfs(e[u][i], u);
	chkmax(max_dep, dep[u]);
}
int main() {
	scanf("%d%d", &n, &x);
	for (int i = 2; i <= n; i++) {
		int fa; scanf("%d", &fa);
		e[fa].push_back(i);
	}
	dfs(1, 0);
	ok[0] = 1;
	for (int i = 1; i <= max_dep; i++) f[t[i].size()].push_back(i);
	for (int i = 1; i <= n; i++) if (f[i].size()) {
		for (int j = 0; j < i; j++) cnt[j] = 0;
		for (int j = i; j <= x; j++) {
			if (ok[j]) cnt[j] = 0;
			else if (ok[j - i] && cnt[j - i] < f[i].size()) cnt[j] = cnt[j - i] + 1, la[j] = f[i][cnt[j] - 1], ok[j] = 1;
		}
	}
	if (ok[x]) {
		printf("%d\n", max_dep);
		for (int p = x; p; p -= t[la[p]].size())
			for (int j = 0; j < t[la[p]].size(); j++) col[t[la[p]][j]] = 1;
	} else {
		printf("%d\n", max_dep + 1);
		int tot = n;
		for (int i = 1; i <= max_dep; i++) {
			if (t[i].size() <= max(x, tot - x)) {
				if (t[i].size() <= x) {
					for (int j = 0; j < t[i].size(); j++) col[t[i][j]] = 1;
					x -= t[i].size();
				}
				tot -= t[i].size();
			} else {
				int cur = x*2 < tot;
				for (int j = 0; j < t[i].size(); j++)
					if (e[t[i][j]].size()) {
						if (cur) col[t[i][j]] = 1, x--;
						tot--;
					}
				for (int j = 0; j < t[i].size(); j++)
					if (!e[t[i][j]].size()) {
						if (cur) {
							if (x) col[t[i][j]] = 1, x--;
						} else {
							if (x == tot) col[t[i][j]] = 1, x--;
						}
						tot--;
					}
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%c", col[i] == 1 ? 'a' : 'b');
	return 0;
}