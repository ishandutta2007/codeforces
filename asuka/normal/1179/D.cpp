#include<bits/stdc++.h>
#define ll long long
#define N 500015
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
int n, gkp[N], siz[N];
ll dp[N], Min[N], ans = infll;
VI e[N];
ll s2(ll x) {return x * (x - 1) / 2;}
void dfs(int u, int fa) {
	siz[u] = 1;
	for(auto v : e[u]) if(v != fa) {
		dfs(v, u);
		siz[u] += siz[v];
	}
	dp[u] = siz[u] == 1 ? 0 : infll;
	for(auto v : e[u]) if(v != fa) {
		dp[u] = min(dp[u], dp[v] + s2(siz[u] - siz[v]));
		ans = min(ans, dp[v] + s2(n - siz[v]));
	}
	// printf("%d %d\n", u, dp[u]);
	VI vec;
	for(auto v : e[u]) if(v != fa) {
		if(gkp[siz[v]] != u) gkp[siz[v]] = u, Min[siz[v]] = dp[v], vec.pb(siz[v]);
		else ans = min(ans, dp[v] + Min[siz[v]] + s2(n - 2 * siz[v]));
		Min[siz[v]] = min(Min[siz[v]], dp[v]);
	}
	for(auto x : vec) for(auto y : vec) {
		if(x == y) continue;
		ans = min(ans, Min[x] + Min[y] + s2(n - x - y));
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1, 0);
	printf("%lld\n", (ll) n * (n - 1) - ans);
	return 0;
}