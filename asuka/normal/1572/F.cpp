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
int n, q;
namespace BIT {
	ll D1[N], D2[N];
	void clear() {memset(D1, 0, sizeof D1); memset(D2, 0, sizeof D2);}
	void add(int p, int v) {
		int vv = v * p;
		for(; p <= n; p += lowbit(p)) D1[p] += v, D2[p] += vv;
	}
	ll query(ll *D, int p) {
		ll res = 0;
		for(; p; p -= lowbit(p)) res += D[p];
		return res;
	}
	void Add(int l, int r, int v) {
		add(l, v); add(r + 1, -v);
	}
	ll Query(int l, int r) {
		l = max(l, 1);
		return (ll) (r + 1) * query(D1, r) - (ll) l * query(D1, l - 1) - (query(D2, r) - query(D2, l - 1));
	}
}
using namespace BIT;

namespace segBeats {
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	int Max[N << 2], cMax[N << 2], oMax[N << 2];
	void pushup(int p) {
		Max[p] = max(Max[ls], Max[rs]);
		assert(Max[p] > 0);
		cMax[p] = (Max[ls] == Max[p] ? cMax[ls] : 0) + (Max[rs] == Max[p] ? cMax[rs] : 0);
		oMax[p] = Max[ls] == Max[rs] ? max(oMax[ls], oMax[rs]) : max(min(Max[ls], Max[rs]), max(oMax[ls], oMax[rs]));
	}
	void pushdown(int p);
	void down(int p, int v) {
		if(v >= Max[p]) return;
		if(v > oMax[p]) {
			Max[p] = v;
		} else {
			pushdown(p);
			down(ls, v); down(rs, v);
			pushup(p);
		}
	}
	void pushdown(int p) {
		down(ls, Max[p]);
		down(rs, Max[p]);
	}
	void down0(int p, int v) {
		if(v >= Max[p]) return;
		if(v > oMax[p]) {
			Add(v + 1, Max[p], -cMax[p]);
			Max[p] = v;
		} else {
			pushdown(p);
			down0(ls, v); down0(rs, v);
			pushup(p);
		}
	}
	void cmin(int p, int l, int r, int x, int y, int v) {
		if(x <= l && r <= y) return down0(p, v);
		pushdown(p);
		int mid = (l + r) >> 1;
		if(x <= mid) cmin(ls, l, mid, x, y, v);
		if(y > mid) cmin(rs, mid + 1, r, x, y, v);
		pushup(p);
	}
	void modify(int p, int l, int r, int pos, int val) {
		if(l == r) {
			if(~Max[p]) Add(1, Max[p], -1);
			Max[p] = val; cMax[p] = 1; oMax[p] = -1;
			Add(1, Max[p], 1);
			return;
		}
		pushdown(p);
		int mid = (l + r) >> 1;
		if(pos <= mid) modify(ls, l, mid, pos, val);
		else modify(rs, mid + 1, r, pos, val);
		pushup(p);
	}
}
using namespace segBeats;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(Max, -1, sizeof Max);
	scanf("%d%d", &n, &q);
	rep(i, 1, n) modify(1, 1, n, i, i);
	rep(i, 2, n) Add(1, i - 1, -1);
	while(q--) {
		int opt, x, y;
		scanf("%d%d%d", &opt, &x, &y);
		if(opt == 1) {
			if(x > 1) cmin(1, 1, n, 1, x - 1, x - 1);
			modify(1, 1, n, x, y);
		} else {
			printf("%lld\n", Query(x, y));
		}
	}
	return 0;
}