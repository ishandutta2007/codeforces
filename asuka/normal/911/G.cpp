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
#define M (N << 6)
int n, a[N], rt[105], tot, ls[M], rs[M];
void add(int &p, int l, int r, int pos) {
	if(!p) p = ++tot;
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(pos <= mid) add(ls[p], l, mid, pos);
	else add(rs[p], mid + 1, r, pos);
}
void split(int &u, int &v, int l, int r, int x, int y) {
	if(!u) return;
	if(x <= l && r <= y) {
		v = u;
		u = 0;
		return;
	}
	if(!v) v = ++tot;
	int mid = (l + r) >> 1;
	if(x <= mid) split(ls[u], ls[v], l, mid, x, y);
	if(y > mid) split(rs[u], rs[v], mid + 1, r, x, y);
}
int merge(int u, int v) {
	if(!u || !v) return u | v;
	ls[u] = merge(ls[u], ls[v]);
	rs[u] = merge(rs[u], rs[v]);
	return u;
}
int ans[N];
void get(int p, int l, int r, int v) {
	if(!p) return;
	if(l == r) return ans[l] = v, void();
	int mid = (l + r) >> 1;
	get(ls[p], l, mid, v);
	get(rs[p], mid + 1, r, v);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]), add(rt[a[i]], 1, n, i);
	int q;
	scanf("%d", &q);
	while(q--) {
		int l, r, x, y, u = 0;
		scanf("%d%d%d%d", &l, &r, &x, &y);
		split(rt[x], u, 1, n, l, r);
		rt[y] = merge(rt[y], u);
	}
	rep(i, 1, 100) get(rt[i], 1, n, i);
	rep(i, 1, n) printf("%d ", ans[i]);
	return 0;
}