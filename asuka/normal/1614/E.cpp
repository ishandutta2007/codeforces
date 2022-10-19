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
namespace seg {
	const int M = N << 6;
	int rt, Max[M], Min[M], tag[M], ls[M], rs[M], tot;
	void down(int &p, int val) {
		if(!p) p = ++tot;
		tag[p] += val;
		Max[p] += val;
		Min[p] += val;
	}
	void pushdown(int p) {
		if(tag[p]) {
			down(ls[p], tag[p]);
			down(rs[p], tag[p]);
			tag[p] = 0;
		}
	}
	void pushup(int p) {
		Max[p] = Max[rs[p]];
		Min[p] = Min[ls[p]];
	}
	void add(int &p, int l, int r, int x, int y, int val) {
		if(!p) p = ++tot;
		if(x <= l && r <= y) return down(p, val);
		int mid = (l + r) >> 1;
		pushdown(p);
		if(x <= mid) add(ls[p], l, mid, x, y, val);
		if(y > mid) add(rs[p], mid + 1, r, x, y, val);
		pushup(p);
	}
	int query(int p, int l, int r, int pos) {
		if(!p) return pos;
		if(l == r) return pos + Max[p];
		int mid = (l + r) >> 1;
		pushdown(p);
		if(pos <= mid) return query(ls[p], l, mid, pos);
		else return query(rs[p], mid + 1, r, pos);
	}
	int pre(int p, int l, int r, int v) { // < v
			if(l == r) return (l + Max[p] < v) ? l : -1;
		if(!p) return (l <= v - 1 && v - 1 <= r) ? v - 1 : -1;
		pushdown(p);
		int mid = (l + r) >> 1;
		if(mid + 1 + Min[rs[p]] >= v) return pre(ls[p], l, mid, v);
		else return pre(rs[p], mid + 1, r, v);
	}
	int suc(int p, int l, int r, int v) {
		if(l == r) return (l + Max[p] > v) ? l : -1;
		if(!p) return (l <= v + 1 && v + 1 <= r) ? v + 1 : -1;
		pushdown(p);
		int mid = (l + r) >> 1;
		if(mid + Max[ls[p]] <= v) return suc(rs[p], mid + 1, r, v);
		else return suc(ls[p], l, mid, v);
	}
}
using namespace seg;
int n;
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	int lans = 0;
	rep(i, 1, n) {
		int t, k, x;
		scanf("%d", &t);
		int l = pre(rt, 0, 1000000000, t), r = suc(rt, 0, 1000000000, t);
		// printf("[0 %d] [%d inf]\n", l, r);
		if(~l) add(rt, 0, 1000000000, 0, l, 1);
		if(~r) add(rt, 0, 1000000000, r, 1000000000, -1);
		scanf("%d", &k);
		rep(_, 1, k) {
			scanf("%d", &x);
			x = (x + lans) % (1000000000 + 1);
			printf("%d\n", lans = query(rt, 0, 1000000000, x));
		}
	}
	return 0;
}