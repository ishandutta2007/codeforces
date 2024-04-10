#include<bits/stdc++.h>
#define ll long long
#define N 205
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
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
int n, k, a[N];
VI e[N];
VI dfs(int u, int fa) {
	#define rf(i) (SZ(f) - (i) - 1)
	#define rg(i) (SZ(g) - (i) - 1)
	VI f;
	f.pb(a[u]);
	for(auto v : e[u]) if(v != fa) {
		VI g = dfs(v, u);
		g.pb(0);
		if(SZ(f) < SZ(g)) swap(f, g);
		rep(lvl, 0, SZ(g) - 1){
			int v1 = f[rf(lvl)] + ((k - lvl + 1 < SZ(g)) ? g[rg(max(lvl, k - lvl + 1))] : 0);
			int v2 = g[rg(lvl)] + ((k - lvl + 1 < SZ(f)) ? f[rf(max(lvl, k - lvl + 1))] : 0);
			f[rf(lvl)] = max({f[rf(lvl)], v1, v2});
		}
		per(lvl, 0, SZ(g) - 1) {
			if(0 <= rf(lvl + 1) && rf(lvl + 1) < SZ(f))
				f[rf(lvl)] = max(f[rf(lvl)], f[rf(lvl + 1)]);
		}
	}
	return f;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	VI res = dfs(1, 0);
	printf("%d\n", *max_element(all(res)));
	return 0;
}