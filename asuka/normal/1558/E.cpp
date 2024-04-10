#include<bits/stdc++.h>
#define int long long
#define N 2005
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
int n, m, a[N], b[N], inset[N], from[N], vis[N];
int dt;
VI e[N], vec;
void fuck(int x) {
	// printf("route\n");
	while(!inset[x]) {
		// printf("%lld\n", x);
		dt += b[x];
		vec.pb(x);
		inset[x] = 1;
		x = from[x];
	}
	// printf("%lld\n", x);
}
bool dfs(int u, int pw) {
	// printf("CUR: %lld %lld\n", u, pw);
	vis[u] = 1;
	for(auto v : e[u]) {
		// printf("V %lld\n", v);
		if(pw <= a[v]) continue;
		if(inset[u] && inset[v]) continue;
		if(v == from[u]) continue;
		// printf("VV %lld -> %lld\n", u, v);
		if(vis[v]) {
			// printf("%lld %lld\n", u, v);
			fuck(v);
			fuck(u);
			return 1;
		} else {
			from[v] = u;
			if(dfs(v, pw + b[v])) return 1;
		}
	}
	return 0;
}
bool check(int p) {
	// printf("P %lld\n", p);
	vec.clear();
	rep(i, 1, n) inset[i] = 0;
	vec.pb(1);
	inset[1] = 1;
	rep(i, 1, n) {
		rep(j, 1, n) from[j] = j, vis[j] = inset[j];
		// printf("SET :\n");
		// for(auto x : vec) printf("%lld ", x); printf("\n");
		dt = 0;
		for(auto x : vec) {
			// printf("START %lld\n", x);
			if(dfs(x, p)) {
				break;
			}
		}
		p += dt;
	}
	return SZ(vec) == n;
}
void solve() {
	scanf("%lld%lld", &n, &m);
	rep(i, 2, n) scanf("%lld", &a[i]);
	rep(i, 2, n) scanf("%lld", &b[i]);
	rep(i, 1, n) e[i].clear();
	rep(i, 1, m) {
		int u, v;
		scanf("%lld%lld", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	int l = 1, r = 1e9 + 1, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", ans);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T;
	scanf("%lld", &T);
	while(T --> 0) solve();
	return 0;
}
/*
1
4 4
3 5 6
2 1 1
1 2
2 3
3 4
4 2
*/