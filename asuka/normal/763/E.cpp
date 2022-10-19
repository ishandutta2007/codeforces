#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int n, m, q, k;
VI e[N];
vector<pii> que[N];
int fa[N], siz[N], pa[N][5], ans[N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v) return;
	fa[u] = v;
}
namespace SMALL {
	int fa[12];
	void init() {rep(i, 1, 10) fa[i] = i;}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	void uni(int u, int v) {
		u = find(u);
		v = find(v);
		if(u == v) return;
		fa[u] = v;
	}
}
void calc(int mid, int l, int r, int id) {
	// printf("FGHJKLKJHGFDSDFGHJKLKJHGFD\n");
	int vl[5], vr[5];
	VI vec;
	vec.clear();
	rep(j, 0, 4) {
		if(mid - j >= l) vec.pb(pa[l][j]);
	}
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	rep(j, 0, 4) {
		if(mid - j >= l) vl[j] = lower_bound(all(vec), pa[l][j]) - vec.begin() + 1;
	}
	vec.clear();
	rep(j, 0, 4) {
		if(mid + 1 + j <= r) vec.pb(pa[r][j]);
	}
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	rep(j, 0, 4) {
		if(mid + 1 + j <= r) vr[j] = lower_bound(all(vec), pa[r][j]) - vec.begin() + 6;
	}
	ans[id] = siz[l] + siz[r];
	// printf("%d %d\n", siz[l], siz[r]);
	SMALL::init();
	rep(j, 0, 4) {
		if(mid - j >= l) {
			for(auto v : e[mid - j]) {
				if(mid < v && v <= r) {
					if(SMALL::find(vl[j]) != SMALL::find(vr[v - mid - 1])) {
						SMALL::uni(vl[j], vr[v - mid - 1]);
						ans[id]--;
					}
				}
			}
		} 
	}
}
void solve(int l, int r) {
	if(l == r) {
		for(auto x : que[l]) {
			if(x.fi == r) ans[x.se] = 1;
		}
		return;
	}
	rep(i, l, r) fa[i] = i, siz[i] = 0;
	int mid = (l + r) >> 1;
	per(i, l, mid) {
		if(i < mid) siz[i] = siz[i + 1];
		siz[i]++;
		for(auto v : e[i]) {
			if(i <= v && v <= mid) {
				if(find(i) != find(v)) {
					uni(i, v);
					siz[i]--;
				}
			}
		}
		rep(j, 0, 4) {
			if(mid - j >= l) pa[i][j] = find(mid - j);
		}
	}
	rep(i, mid + 1, r) {
		if(i > mid + 1) siz[i] = siz[i - 1];
		siz[i]++;
		for(auto v : e[i]) {
			if(mid < v && v <= i) {
				if(find(i) != find(v)) {
					uni(i, v);
					siz[i]--;
				}
			}
		}
		rep(j, 0, 4) if(mid + 1 + j <= r) pa[i][j] = find(mid + 1 + j);
	}
	rep(i, l, mid) {
		while(SZ(que[i]) > 0 && que[i].back().fi > mid) {
			calc(mid, i, que[i].back().fi, que[i].back().se);
			que[i].pop_back();
		}
	}
	solve(l, mid);
	solve(mid + 1, r);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &k);
	scanf("%d", &m);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	scanf("%d", &q);
	rep(_, 1, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		que[l].pb(mp(r, _));
	}
	rep(i, 1, n) sort(all(que[i]));
	solve(1, n);
	rep(i, 1, q) printf("%d\n", ans[i]);
	return 0;
}