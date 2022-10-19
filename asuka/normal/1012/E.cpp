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
const int N = 200015;
vector<VI> ans;
int n, s, a[N], b[N], to[N], id[N], rev[N], fa[N], cnt;
bool vis[N];
VI num[N];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void solve() {
	rep(i, 1, n) vis[i] = 0;
	cnt = 0;
	ans.clear();
	rep(i, 1, n) {
		if(a[i] == b[i]) continue;
		int u = id[i];
		if(vis[u]) continue;
		VI v;
		int ou = u;
		while(!vis[u]) {
			vis[u] = 1;
			fa[u] = ou;
			v.pb(u);
			u = to[u];
		}
		ans.pb(v);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &s);
	vector<pii> vec;
	rep(i, 1, n) scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + n + 1);
	rep(i, 1, n) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
	rep(i, 1, n) b[i] = a[i];
	sort(b + 1, b + n + 1);
	int tot = 0;
	rep(i, 1, n) if(a[i] != b[i]) vec.pb(mp(a[i], i)), id[i] = ++tot, rev[tot] = i;
	if(tot > s) return puts("-1"), 0;
	sort(all(vec));
	rep(i, 1, n) if(a[i] != b[i]) to[id[i]] = lower_bound(all(vec), mp(a[i], i)) - vec.begin() + 1, num[a[i]].pb(id[i]);
	solve();
	rep(x, 1, n) {
		rep(i, 1, SZ(num[x]) - 1) {
			int u = num[x][i - 1], v = num[x][i];
			if(find(u) == find(v)) continue;
			fa[find(u)] = find(v);
			swap(to[u], to[v]);
			
		}
	}
	solve();
	int lef = s;
	for(auto x : ans) lef -= SZ(x);
	lef = min(lef, SZ(ans));
	if(lef > 1) {
		VI v;
		lef = min(lef, SZ(ans));
		rep(_, 0, lef - 1) v.pb(ans[_].back());
		per(_, 1, lef - 1) swap(to[v[_ - 1]], to[v[_]]);
		solve();
		reverse(all(ans));
		ans.pb(v);
		reverse(all(ans));
	}
	printf("%d\n", SZ(ans));
	for(auto x : ans) {
		printf("%d\n", SZ(x));
		for(auto o : x) printf("%d ", rev[o]);
		printf("\n");
	}
	return 0;
}