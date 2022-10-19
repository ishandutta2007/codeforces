#include<bits/stdc++.h>
#define ll long long
#define N 305
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
int T, n, m, a[N * N], b[N * N], vis[N][N];
map<int, int> l, r, st, ed;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		l.clear();
		r.clear();
		st.clear();
		ed.clear();
		scanf("%d%d", &n, &m);
		rep(i, 1, n * m) scanf("%d", &a[i]), b[i] = a[i];
		rep(i, 1, n) rep(j, 1, m) vis[i][j] = 0;
		sort(b + 1, b + n * m + 1);
		rep(i, 1, n * m) {
			l[a[i]] = lower_bound(b + 1, b + n * m + 1, a[i]) - b;
			r[a[i]] = upper_bound(b + 1, b + n * m + 1, a[i]) - b - 1;
			st[a[i]] = l[a[i]];
			ed[a[i]] = r[a[i]];
		}
		rep(i, 1, n * m) {
			while(st[a[i]] <= r[a[i]] && st[a[i]] % m != 0) st[a[i]]++;
			while(ed[a[i]] >= l[a[i]] && ed[a[i]] % m != 0) ed[a[i]]--;
		}
		int ans = 0;
		rep(i, 1, n * m) {
			int u, x, y;
			u = st[a[i]];
			x = (u + m - 1) / m;
			y = u - (x - 1) * m;
			if(r[a[i]] >= u && u >= l[a[i]] && !vis[x][y]) {
				rep(j, 1, y) ans += vis[x][j];
				vis[x][y] = 1;
				st[a[i]]--;
			} else {
				u = ed[a[i]];
				x = (u + m - 1) / m;
				y = u - (x - 1) * m;
				if(r[a[i]] >= u && u >= l[a[i]] && !vis[x][y]) {
					rep(j, 1, y) ans += vis[x][j];
					vis[x][y] = 1;
					ed[a[i]]--;
				} else {
					u = r[a[i]];
					x = (u + m - 1) / m;
					y = u - (x - 1) * m;
					rep(j, 1, y) ans += vis[x][j];
					vis[x][y] = 1;
					r[a[i]]--;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}