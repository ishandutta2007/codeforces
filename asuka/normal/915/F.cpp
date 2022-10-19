#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
int n, a[N], p[N], pos[N], fa[N], siz[N];
ll ans;
VI e[N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v) return;
	if(siz[u] < siz[v]) swap(u, v);
	siz[u] += siz[v];
	fa[v] = u;
}
void solve() {
	rep(i, 1, n) p[i] = i;
	rep(i, 1, n) fa[i] = i, siz[i] = 1;
	sort(p + 1, p + n + 1, [&](int u, int v) {
		return a[u] < a[v];
	});
	rep(i, 1, n) pos[p[i]] = i;
	rep(i, 1, n) {
		int u = p[i];
		VI vec;
		for(auto v : e[u]) {
			if(pos[v] < pos[u]) vec.pb(v);
		}
		ll cnt = 0, sum = 0;
		for(auto v : vec) {
			cnt += sum * siz[find(v)] + siz[find(v)];
			sum += siz[find(v)];
		}
		for(auto v : vec) {
			uni(u, v);
		}
		ans += a[u] * cnt;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	solve();
	rep(i, 1, n) a[i] = -a[i];
	solve();
	printf("%lld\n", ans);
	return 0;
}