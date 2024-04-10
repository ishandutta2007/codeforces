#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
using namespace std;
const int N = 200015;
int n, m, q, a[N];

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

struct Data {
	int [6], o;
	Data operator + (const Data &rhs) const {
		if(o == -1) return rhs;
		Data res;
		rep(i, 0, m) res.[i] = [rhs.[i]];
		res.o = [rhs.o];
		return res;
	}
} ori[N << 2][2];

bool cur[N << 2], rev[N << 2];

void pushup(int p) {
	rep(o, 0, 1) ori[p][cur[p] ^ o] = ori[ls][cur[ls] ^ o] + ori[rs][cur[rs] ^ o];
}

void build(int p, int l, int r) {
	rep(o, 0, 1) rep(j, 0, m) {
		auto calc = [&](int lst) {
			per(i, l, r) {
				if(i + m < lst && (a[i] ^ o) == 1) lst = i;
			}
			return lst;
		};
		ori[p][o].[j] = min(m, calc(r + j + 1) - l);
		ori[p][o].o = min(m, calc((a[r] ^ o) == 0 ? r + m : r) - l);
	}
	if(l == r) return;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}

void down(int p) {
	rev[p] ^= 1; cur[p] ^= 1;
}

void pushdown(int p) {
	if(rev[p]) down(ls), down(rs);
	rev[p] = 0;
}

void modify(int p, int l, int r, int x, int y) {
	if(x <= l && r <= y) return down(p);
	pushdown(p);
	if(x <= mid) modify(ls, l, mid, x, y);
	if(y > mid) modify(rs, mid + 1, r, x, y);
	pushup(p);
}
Data query(int p, int l, int r, int x, int y) {
	if(x <= l && r <= y) return ori[p][cur[p]];
	pushdown(p);
	Data res;
	res.o = -1;
	if(x <= mid) res = res + query(ls, l, mid, x, y);
	if(y > mid) res = res + query(rs, mid + 1, r, x, y);
	return res;
}

int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &q);
	rep(i, 1, n) {
		ll x;
		scanf("%lld", &x);
		a[i] = x & 1;		
	}
	build(1, 1, n);
	rep(_, 1, q) {
		int opt, l, r;
		ll x;
		scanf("%d%d%d", &opt, &l, &r);
		if(opt == 1) {
			scanf("%lld", &x);
			if(x & 1) modify(1, 1, n, l, r);
		} else {
			Data res = query(1, 1, n, l, r);
			puts(res.o == 0 ? "2" : "1");
		}
	}
	return 0;
}