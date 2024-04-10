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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 200015, M = 200015 * 32;
int n, a[N], rev[M];
pii dep[M];
pair<int, pii> ans[M];
bool valid[M], vis[M];
VI e[M];
void dfs(int u) {
	vis[u] = 1;
	pii Max = mp(0, 0), oMax = mp(0, 0);
	if(valid[u]) dep[u] = mp(0, u);
	for(int v : e[u]) {
		if(vis[v]) continue;
		dfs(v);
		dep[v].fi++;
		dep[u] = max(dep[u], dep[v]);
		ans[u] = max(ans[u], ans[v]);
		if(dep[v] > Max) {
			oMax = Max;
			Max = dep[v];
		} else if(dep[v] > oMax) {
			oMax = dep[v];
		}
	}
	if(valid[u]) ans[u] = max(ans[u], mp(dep[u].fi, mp(u, dep[u].se)));
	if(oMax.se > 0) ans[u] = max(ans[u], mp(Max.fi + oMax.fi, mp(Max.se, oMax.se)));
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	VI vec;
	rep(i, 1, n) {
		int x = a[i];
		while(x) {
			vec.pb(x);
			int o = 1 << (31 - __builtin_clz(x));
			if(o < x) o <<= 1;
			x = o - x;
		}
	}
	vec.pb(0);
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	auto id = [&](int o) -> int{
		return lower_bound(all(vec), o) - vec.begin() + 1;
	};
	rep(i, 1, n) {
		int x = a[i];
		valid[id(x)] = 1;
		rev[id(x)] = i;
		while(x) {
			int o = 1 << (31 - __builtin_clz(x));
			if(o < x) o <<= 1;
			e[id(o - x)].pb(id(x));
			x = o - x;
		}
	}
	assert(id(0) == 1);
	dfs(1);
	printf("%d %d %d\n", rev[ans[1].se.fi], rev[ans[1].se.se], ans[1].fi);
	return 0;
}