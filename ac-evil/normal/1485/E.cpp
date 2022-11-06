#include <bits/stdc++.h>
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long long LL;
const int N = 200005;
using std::min; using std::max; using std::vector;
int T, n, a[N], vis[N], fa[N], dep[N], mx[N], mn[N]; LL f[N], g0[N], g1[N]; // g0 : fu + afau; g1 : fu - afau
vector<int> e[N], l;
int main() {
	//freopen("ques.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			e[i].clear(), vis[i] = mx[i] = g0[i] = 0, mn[i] = 1e9, g1[i] = -1e9;
		for (int i = 2; i <= n; i++) {
			int v; scanf("%d", &v);
			e[i].push_back(v), e[v].push_back(i);
		}
		for (int i = 2; i <= n; i++) scanf("%d", &a[i]);
		l.push_back(1); vis[1] = 1; dep[1] = 0;
		for (int i = 0; i < l.size(); i++) {
			int u = l[i];
			chkmax(mx[dep[u]], a[u]), chkmin(mn[dep[u]], a[u]);
			for (int j = 0, v; j < e[u].size(); j++)
				if (v = e[u][j], !vis[v]) l.push_back(v), dep[v] = dep[u] + 1, vis[v] = 1, fa[v] = u;
		}
		//for (int i = 1; i <= n; i++) printf("<%d %d %d>\n", dep[i], mx[i], mn[i]);
		while (l.size()) {
			int u = l[l.size() - 1]; l.pop_back();
			//printf("!%d ", u);
			f[u] = max((LL)max(mx[dep[u]] - a[u], a[u] - mn[dep[u]]), max(g0[dep[u] + 1] - a[u], g1[dep[u] + 1] + a[u]));
			for (int i = 0, v; i < e[u].size(); i++)
				if (v = e[u][i], v != fa[u]) chkmax(f[u], f[v] + max(mx[dep[u]] - a[u], a[u] - mn[dep[u]]));
			chkmax(g0[dep[u]], f[u] + a[fa[u]]), chkmax(g1[dep[u]], f[u] - a[fa[u]]);
		}
		//for (int i = 1; i <= n; i++) printf("%d : %lld\n", i, f[i]); puts("");
		printf("%lld\n", f[1]);
	}
	return 0;
}