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
const int N = 100015;
int n, k, s[N];
VI add[N], del[N];
int sum[N << 2];
bool rev[N << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
void pushup(int p) {sum[p] = sum[ls] + sum[rs];}
void down(int p, int l, int r) {
	sum[p] = (r - l + 1) - sum[p];
	rev[p] ^= 1;
}
void pushdown(int p, int l, int r) {
	if (rev[p]) down(ls, l, mid), down(rs, mid + 1, r);
	rev[p] = 0;
}
void flip(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return down(p, l, r);
	pushdown(p, l, r);
	if(x <= mid) flip(ls, l, mid, x, y);
	if(y > mid) flip(rs, mid + 1, r, x, y);
	pushup(p);
}
int query(int p, int l, int r, int x, int y) {
	if(x > y) return 0;
	if(x <= l && r <= y) return sum[p];
	pushdown(p, l, r);
	int res = 0;
	if(x <= mid) res += query(ls, l, mid, x, y);
	if(y > mid) res += query(rs, mid + 1, r, x, y);
	return res;
}
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &s[i]);
	sort(s + 1, s + n + 1);
	rep(i, 1, k) {
		int l, r;
		scanf("%d%d", &l, &r);
		l = lower_bound(s + 1, s + n + 1, l) - s;
		r = upper_bound(s + 1, s + n + 1, r) - s - 1;
		if (l < r) {
			add[l].pb(r);
			del[r].pb(l);
		}
	}
	ll ans = (ll) n * (n - 1) * (n - 2) / 6;
	rep(i, 1, n) {
		for(int x : add[i]) flip(1, 1, n, i, x);
		int d = (i - 1) - query(1, 1, n, 1, i - 1) + query(1, 1, n, i + 1, n);
		ans -= (ll) d * (d - 1) / 2;
		for(int x : del[i]) flip(1, 1, n, x, i);
	}
	printf("%lld\n", ans);
	return 0;
}