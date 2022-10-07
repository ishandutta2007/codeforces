#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
void print(int x, char ch = '\n'){
	if (x == 0) return putchar('0'), putchar(ch), void(0);
	int cnt = 0, num[25];
	for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num[++cnt] = x % 10;
	while (cnt) putchar(num[cnt] ^ '0'), --cnt;
	putchar(ch);
}
#define N 150005
int n, q, p, A[N];
namespace segt{
	struct node{
		int cnt, val[5], hp[5];
		void init(int v, int x){ cnt = 1, val[0] = v, hp[0] = x; }
	}a[N << 2];
	int lz[N << 2];
	node operator + (const node &a, const node &b){
		node c = a;
		for (register int i = 0; i < b.cnt; ++i){
			bool flag = 1;
			for (register int j = 0; j < c.cnt; ++j)
				if (c.val[j] == b.val[i]){ c.hp[j] += b.hp[i], flag = 0; break; }
			if (!flag) continue;
			if (c.cnt < p){ c.val[c.cnt] = b.val[i], c.hp[c.cnt] = b.hp[i], ++c.cnt; continue; }
			int mn = b.hp[i];
			for (register int j = 0; j < c.cnt; ++j) mn = std :: min(mn, c.hp[j]);
			int k = 0;
			for (register int j = 0; j < c.cnt; ++j)
				if (c.hp[j] > mn) c.val[k] = c.val[j], c.hp[k] = c.hp[j] - mn, ++k;
			if (b.hp[i] > mn) c.val[k] = b.val[i], c.hp[k] = b.hp[i] - mn, ++k;
			c.cnt = k;
		}
		return c;
	}
	void build(int u, int l, int r){
		if (l == r) return a[u].init(A[l], 1), void(0);
		int md = (l + r) >> 1;
		build(u << 1, l, md), build(u << 1 | 1, md + 1, r);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}
	void cover(int u, int v, int len){
		a[u].init(v, len), lz[u] = v;
	}
	void down(int u, int l, int r, int md){
		if (lz[u]) cover(u << 1, lz[u], md - l + 1), cover(u << 1 | 1, lz[u], r - md), lz[u] = 0;
	}
	void modify(int u, int l, int r, int L, int R, int v){
		if (L <= l && r <= R) return cover(u, v, r - l + 1), void(0);
		int md = (l + r) >> 1;
		down(u, l, r, md);
		if (L <= md) modify(u << 1, l, md, L, R, v);
		if (R > md) modify(u << 1 | 1, md + 1, r, L, R, v);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}
	node query(int u, int l, int r, int L, int R){
		if (L <= l && r <= R) return a[u];
		int md = (l + r) >> 1;
		down(u, l, r, md);
		if (R <= md) return query(u << 1, l, md, L, R);
		else if (L > md) return query(u << 1 | 1, md + 1, r, L, R);
		else return query(u << 1, l, md, L, R) + query(u << 1 | 1, md + 1, r, L, R);
	}
}
int main(){
	n = read(), q = read(), p = 100 / read();
	for (register int i = 1; i <= n; ++i) A[i] = read();
	segt :: build(1, 1, n);
	while (q--){
		int op = read(), l = read(), r = read();
		if (op == 1) segt :: modify(1, 1, n, l, r, read());
		else{
			segt :: node tmp = segt :: query(1, 1, n, l, r);
			print(tmp.cnt, ' ');
			for (register int i = 0; i < tmp.cnt; ++i)
				print(tmp.val[i], ' ');
			putchar('\n');
		}
	}
}