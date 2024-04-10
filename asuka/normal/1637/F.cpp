#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 200015;
int n, h[N], Max[N];
ll val[N];
vector<int> e[N];
void dfs(int u, int pa) {
	for (auto v : e[u]) {
		if (v == pa) continue;
		dfs(v, u);
		val[u] += val[v];
		Max[u] = max(Max[u], Max[v]);
	}
	if (Max[u] < h[u]) {
		val[u] += h[u] - Max[u];
		Max[u] = h[u];
	}
}
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &h[i]);
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v); e[v].pb(u);
	}
	int rt = max_element(h + 1, h + n + 1) - h;
	ll f[3], g[3];
	rep(i, 0, 2) f[i] = infll;
	f[0] = 0;
	for (auto u : e[rt]) {
		dfs(u, rt);
		rep(i, 0, 2) g[i] = infll;
		rep(i, 0, 2) g[i] = min(g[i], f[i] + val[u]);
		rep(i, 1, 2) g[i] = min(g[i], f[i - 1] + val[u] - Max[u] + h[rt]);
		swap(f, g);
	}
	printf("%lld\n", min(f[1] + h[rt], f[2]));
	return 0;
}