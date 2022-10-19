#include<bits/stdc++.h>
#define ll long long
#define N 300015
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
int n, q, m, dep[N], cov[N], pa[N];
VI e[N], g[N];
vector<VI> ans;
bool vis[N];
void dfs(int u, int fa) {
	vis[u] = 1;
	dep[u] = dep[fa] + 1;
	pa[u] = fa;
	for(auto v : e[u]) {
		if(vis[v]) continue;
		dfs(v, u);
		g[u].pb(v);
	}
}
pii f[N];
void dfs2(int u, int fa) {
	for(auto v : g[u]) {
		if(v == fa) continue;
		dfs2(v, u);
		f[u].fi += f[v].fi;
		f[u].se += f[v].se;
	}
	f[u].fi += f[u].se / 2;
	f[u].se %= 2;
	if(cov[u]) {
		if(!f[u].se) f[u].se = 1;
	} else {
		if(f[u].se) f[u].se = 0, f[u].fi++;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1, 0);
	scanf("%d", &q);
	while(q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		VI U, V, res;
		while(u != v) {
			if(dep[u] >= dep[v]) {
				cov[u] ^= 1;
				U.pb(u);
				u = pa[u];
			} else {
				cov[v] ^= 1;
				V.pb(v);
				v = pa[v];
			}
		}
		for(auto x : U) res.pb(x);
		res.pb(u);
		reverse(all(V));
		for(auto x : V) res.pb(x);
		ans.emplace_back(res);
	}
	bool flag = 1;
	rep(i, 2, n) if(cov[i]) flag = 0;
	if(flag) {
		puts("YES");
		for(auto x : ans){
			printf("%d\n", SZ(x));
			for(auto xx : x) printf("%d ", xx);
			printf("\n");
		}
		return 0;
	} else {
		puts("NO");
		dfs2(1, 0);
		printf("%d\n", f[1].fi);
	}
	return 0;
}