#include <bits/stdc++.h>
typedef long long LL;
const int N = 500005, P = 1e9 + 7;
int n, m, fa[N], k[N], x[N], y[N], vis[N];
int fset(int x) { return fa[x] == x ? x : fa[x] = fset(fa[x]); }
void merge(int x, int y) {
	fa[fset(x)] = fset(y);
}
int qpow(int a, int b) {
	int t = 1;
	for (; b; b >>= 1, a = 1LL*a*a%P)
		if (b & 1) t = 1LL*t*a%P;
	return t;
}
std::vector<int> ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &k[i], &x[i]);
		if (k[i] == 2) scanf("%d", &y[i]);
	}
	for (int i = 1; i <= m; i++) fa[i] = i;
	for (int i = 1; i <= n; i++) {
		if (k[i] == 1) {
			if (fset(0) == fset(x[i])) continue;
			ans.push_back(i); merge(0, x[i]);
		} else {
			if (fset(x[i]) == fset(y[i])) continue;
			ans.push_back(i); merge(x[i], y[i]);
		}
	}
	printf("%d %d\n", qpow(2, ans.size()), ans.size());
	std::sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	return 0;
}