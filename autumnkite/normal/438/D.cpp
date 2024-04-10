#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
void print(long long x, char ch = '\n'){
	if (x == 0) return putchar('0'), putchar(ch), void(0);
	int cnt = 0, num[25];
	for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num[++cnt] = x % 10;
	while (cnt) putchar(num[cnt] ^ '0'), --cnt;
	putchar(ch);
}
const int N = 100005;
int n, q, a[N];
struct node{
	int mx;
	long long sum;
	node(){}
	node(int x){ mx = sum = x; }
	node(int _mx, long long _sum){ mx = _mx, sum = _sum; }
	node operator + (const node &rhs) const {
		return node(std::max(mx, rhs.mx), sum + rhs.sum);
	}
};
struct Segment_Tree{
	node val[N << 2];
	void build(int u, int l, int r){
		if (l == r) return val[u] = node(a[l]), void(0);
		int md = (l + r) >> 1;
		build(u << 1, l, md), build(u << 1 | 1, md + 1, r);
		val[u] = val[u << 1] + val[u << 1 | 1];
	}
	void mod(int u, int l, int r, int L, int R, int x){
		if (l == r) return val[u].mx %= x, val[u].sum %= x, void(0);
		int md = (l + r) >> 1;
		if (L <= md && val[u << 1].mx >= x) mod(u << 1, l, md, L, R, x);
		if (R > md && val[u << 1 | 1].mx >= x) mod(u << 1 | 1, md + 1, r, L, R, x);
		val[u] = val[u << 1] + val[u << 1 | 1];
	}
	void modify(int u, int l, int r, int x, int y){
		if (l == r) return val[u] = node(y), void(0);
		int md = (l + r) >> 1;
		if (x <= md) modify(u << 1, l, md, x, y);
		else modify(u << 1 | 1, md + 1, r, x, y);
		val[u] = val[u << 1] + val[u << 1 | 1];
	}
	node query(int u, int l, int r, int L, int R){
		if (L <= l && r <= R) return val[u];
		int md = (l + r) >> 1;
		if (R <= md) return query(u << 1, l, md, L, R);
		if (L > md) return query(u << 1 | 1, md + 1, r, L, R);
		return query(u << 1, l, md, L, R) + query(u << 1 | 1, md + 1, r, L, R);
	}
}T;
int main(){
	n = read(), q = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	T.build(1, 1, n);
	while (q--){
		int op = read(), l, r, x;
		if (op == 1) l = read(), r = read(), print(T.query(1, 1, n, l, r).sum);
		if (op == 2) l = read(), r = read(), x = read(), T.mod(1, 1, n, l, r, x);
		if (op == 3) l = read(), x = read(), T.modify(1, 1, n, l, x);
	}
}