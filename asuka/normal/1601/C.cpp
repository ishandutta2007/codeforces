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
int Min[N << 2], lazy[N << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
void pushup(int p) {
	Min[p] = min(Min[ls], Min[rs]);
}
void down(int p, int v) {
	lazy[p] += v;
	Min[p] += v;
}
void pushdown(int p) {
	if(lazy[p]) {
		down(ls, lazy[p]);
		down(rs, lazy[p]);
		lazy[p] = 0;
	}
}
int query(int p, int l, int r, int x, int y) {
	if(x <= l && r <= y) return Min[p];
	pushdown(p);
	int mid = (l + r) >> 1;
	int res = inf;
	if(x <= mid) res = min(res, query(ls, l, mid, x, y));
	if(y > mid) res = min(res, query(rs, mid + 1, r, x, y));
	return res;
}
void upd(int p, int l, int r, int x, int y, int v) {
	if(x <= l && r <= y) return down(p, v);
	pushdown(p);
	int mid = (l + r) >> 1;
	if(x <= mid) upd(ls, l, mid, x, y, v);
	if(y > mid) upd(rs, mid + 1, r, x, y, v);
	pushup(p);
}
int n, m, a[N], b[N],aa[N];
vector<pii> vec;
VI num;
int D[N];
void add(int p) {for(; p <= n; p += lowbit(p)) D[p]++;}
ll query(int p) {ll res = 0; for(; p; p -= lowbit(p)) res += D[p]; return res;}
ll nxd() {
	num.clear();
	ll res = 0;
	rep(i ,1, n) num.pb(a[i]);
	sort(all(num));
	num.erase(unique(all(num)), num.end());
	rep(i, 1, n) aa[i] = lower_bound(all(num), a[i]) - num.begin() + 1;
	rep(i, 1, n) D[i] = 0;
	rep(i, 1, n) {
		res += query(n) - query(aa[i]);
		add(aa[i]);
	}
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		vec.clear();
		scanf("%d%d", &n, &m);
		rep(i, 1, (n + 1) * 4) Min[i] = lazy[i] = 0;
		rep(i, 1, n) scanf("%d", &a[i]), vec.pb(mp(a[i], i)), upd(1, 1, n + 1, i + 1, n + 1, 1);
		rep(i, 1, m) scanf("%d", &b[i]);
		sort(b + 1, b + m + 1);
		sort(all(vec));
		int ptr = 0;
		ll ans = 0;
		rep(i, 1, m) {
			while(ptr < SZ(vec) && vec[ptr].fi < b[i]) {
				int pos = vec[ptr].se;
				if(i == 1 || vec[ptr].fi != b[i - 1]) upd(1, 1, n + 1, pos + 1, n + 1, -1);
				upd(1, 1, n + 1, 1, pos, 1);
				ptr++;
			}
			if(i == 1 || b[i] != b[i - 1]) {
				int nptr = ptr;
				while(nptr < SZ(vec) && vec[nptr].fi == b[i]) {
					int pos = vec[nptr].se;
					upd(1, 1, n + 1, pos + 1, n + 1, -1);
					nptr++;
				}
			}
			ans += query(1, 1, n + 1, 1, n + 1);
			// printf("%d\n", query(1, 1, n + 1, 1, n + 1));
		}
		ans += nxd();
		printf("%lld\n", ans);
	}
	return 0;
}