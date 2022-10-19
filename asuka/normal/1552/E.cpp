#include<bits/stdc++.h>
#define ll long long
#define N 105
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
int n, k, c[N * N];
VI col[N];
vector<pii> a[N], ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &k);
	rep(i, 1, n * k) scanf("%d", &c[i]), col[c[i]].pb(i);
	rep(i, 1, n) {
		rep(j, 1, SZ(col[i]) - 1) {
			a[i].pb(mp(col[i][j - 1], col[i][j]));
		}
	}
	int v = (n + k - 2) / (k - 1);
	int lst = 0;
	while(SZ(ans) < n) {
		VI tmp;
		rep(i, 1, n) {
			if(SZ(a[i]) > 0) tmp.pb(i);
		}
		sort(all(tmp), [&](int u, int v){return a[u].front().se < a[v].front().se;});
		rep(i, 0, min(v, SZ(tmp)) - 1) {
			lst = max(lst, a[tmp[i]].front().se);
			ans.pb(a[tmp[i]].front());
			a[tmp[i]].clear();
		}
		rep(i, 1, n) {
			while(SZ(a[i]) > 0 && a[i].front().fi <= lst) a[i].erase(a[i].begin());
		}
	}
	sort(all(ans), [&](pii u, pii v){return c[u.fi] < c[v.fi];});
	rep(i, 1, n) printf("%d %d\n", ans[i - 1].fi, ans[i - 1].se);
	return 0;
}