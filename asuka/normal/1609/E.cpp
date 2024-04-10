#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
int n, q;
char s[N];
namespace seg {
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	int ab[N << 2], bc[N << 2], ans[N << 2], tag[N << 2][3];
	void pushup(int p) {
		ab[p] = min(ab[ls], ab[rs]);
		bc[p] = min(bc[ls], bc[rs]);
		ans[p] = min({ans[ls], ans[rs], ab[ls] + bc[rs]});
	}
	void down(int p, int v, int typ) {
		if(typ == 0) ab[p] += v, ans[p] += v;
		if(typ == 1) ab[p] -= v, bc[p] += v;
		if(typ == 2) bc[p] -= v, ans[p] -= v;
		tag[p][typ] += v;
	}
	void pushdown(int p) {
		rep(q, 0, 2) {
			down(ls, tag[p][q], q);
			down(rs, tag[p][q], q);
			tag[p][q] = 0;
		}
	}
	void add(int p, int l, int r, int x, int y, int typ, int v) {
		if(x <= l && r <= y) return down(p, v, typ);
		pushdown(p);
		int mid = (l + r) >> 1;
		if(x <= mid) add(ls, l, mid, x, y, typ, v);
		if(y > mid) add(rs, mid + 1, r, x, y, typ, v);
		pushup(p);
	}
	int query() {return ans[1];}
	void out(int p, int l, int r) {
		printf("[%d %d] %d %d %d\n", l, r, ab[p], bc[p], ans[p]);
		if(l == r) return;
		int mid = (l + r) >> 1;
		pushdown(p);
		out(ls, l, mid);
		out(rs, mid + 1, r);
		pushup(p);
	}
}
using namespace seg;
int totc = 0;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	rep(i, 1, n) add(1, 0, n, i, n, s[i] - 'a', 1), totc += s[i] == 'c';
	while(q--) {
		int pos;
		char c[3];
		scanf("%d%s", &pos, c + 1);
		totc -= s[pos] == 'c';
		add(1, 0, n, pos, n, s[pos] - 'a', -1);
		s[pos] = c[1];
		totc += s[pos] == 'c';
		add(1, 0, n, pos, n, s[pos] - 'a', 1);
		printf("%d\n", query() + totc);		
	}
	return 0;
}