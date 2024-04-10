#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 200015;
int n, f[N], g[N], l[N], r[N];
vector<int> e[N];

void dfs(int u) {
	ll sm = 0;
	g[u] = 0;

	for (int v : e[u]) {
		dfs(v);
		sm += f[v];
		g[u] += g[v];
	}

	if (sm < l[u]) g[u]++, f[u] = r[u];
	else f[u] = min(sm, (ll) r[u]);
}

void solve() {
	scanf("%d", &n);

	rep(i, 1, n) e[i].clear();

	rep(i, 2, n) {
		int p;
		scanf("%d", &p);
		e[p].pb(i);
	}

	rep(i, 1, n) scanf("%d%d", &l[i], &r[i]);

	dfs(1);
	printf("%d\n", g[1]);
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int T;

	for (scanf("%d", &T); T--;) solve();

	return 0;
}