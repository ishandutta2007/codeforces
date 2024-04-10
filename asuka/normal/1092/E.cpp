#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, m, vis[N], fa[N], ht[N];
VI e[N];
vector<pii> vec;
int dfs(int u, int f) {
	vis[u] = 1;
	fa[u] = f;
	int hson = u;
	ht[u] = 0;
	for (auto v : e[u]) if (v != f) {
			int vson = dfs(v, u);
			if (ht[v] + 1 > ht[u]) {
				ht[u] = ht[v] + 1;
				hson = vson;
			}
		}
	return hson;
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	int ans = 0;
	rep(i, 1, n) {
		if (!vis[i]) {
			int u = dfs(i, 0);
			int v = dfs(u, 0);
			rep(_, 1, ht[u] / 2) v = fa[v];
			vec.pb(mp((ht[u] + 1) / 2, v));
			ans = max(ans, ht[u]);
		}
	}
	sort(all(vec));
	reverse(all(vec));
	if (SZ(vec) == 2) ans = max(ans, vec[0].fi + vec[1].fi + 1);
	else if(SZ(vec) > 2) ans = max({ans, vec[0].fi + vec[1].fi + 1, vec[1].fi + vec[2].fi + 2});
	printf("%d\n", ans);
	rep(i, 1, SZ(vec) - 1) printf("%d %d\n", vec[0].se, vec[i].se);
	return 0;
}
/*
4 2
1 2
2 3
*/