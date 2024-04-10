#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <set>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, q, a[N], m;
std :: set<int> pos[N];
struct Segment_Tree{
	struct node{
		int lm, rm, mx, mn, ans;
		node operator + (const node &rhs) const {
			node res;
			if (mn < rhs.mn) res.lm = lm, res.rm = std :: max(rm, rhs.mx), res.ans = ans;
			else if (mn > rhs.mn) res.lm = std :: max(mx, rhs.lm), res.rm = rhs.rm, res.ans = rhs.ans;
			else res.lm = lm, res.rm = rhs.rm, res.ans = ans + rhs.ans + std :: max(rm, rhs.lm);
			res.mx = std :: max(mx, rhs.mx);
			res.mn = std :: min(mn, rhs.mn);
			return res;
		}
	}data[N << 2];
	int lz[N << 2];
	void up(int u){
		data[u] = data[u << 1] + data[u << 1 | 1];
	}
	void add(int u, int x){
		data[u].mn += x, lz[u] += x;
	}
	void down(int u){
		if (lz[u]) add(u << 1, lz[u]), add(u << 1 | 1, lz[u]), lz[u] = 0;
	}
	void modify1(int u, int l, int r, int L, int R, int x){
		if (L > R) return;
		if (L <= l && r <= R) return add(u, x), void(0);
		int md = (l + r) >> 1;
		down(u);
		if (L <= md) modify1(u << 1, l, md, L, R, x);
		if (R > md) modify1(u << 1 | 1, md + 1, r, L, R, x);
		up(u);
	}
	void modify2(int u, int l, int r, int x, int y){
		if (l == r) return data[u].mx = data[u].ans = y, void(0);
		int md = (l + r) >> 1;
		down(u);
		if (x <= md) modify2(u << 1, l, md, x, y);
		else modify2(u << 1 | 1, md + 1, r, x, y);
		up(u);
	}
	// void print(int u, int l, int r){
	// 	printf("%d [%d,%d] : %d %d %d\n", u, l, r, data[u].ans, data[u].lm, data[u].rm);
	// 	if (l == r) return;
	// 	int md = (l + r) >> 1;
	// 	print(u << 1, l, md), print(u << 1 | 1, md + 1, r);
	// }
	int query(){
		return data[1].ans + data[1].lm + data[1].rm;
	}
}T;
void add(int x){
	if (pos[x].empty()) return;
	T.modify1(1, 1, n, *pos[x].begin(), *pos[x].rbegin() - 1, 1);
	T.modify2(1, 1, n, *pos[x].begin(), pos[x].size());
}
void del(int x){
	if (pos[x].empty()) return;
	T.modify1(1, 1, n, *pos[x].begin(), *pos[x].rbegin() - 1, -1);
	T.modify2(1, 1, n, *pos[x].begin(), 0);
}
void insert(int x, int y){
	del(y), pos[y].insert(x), add(y);
}
void erase(int x, int y){
	del(y), pos[y].erase(x), add(y);
}
int main(){
	n = read(), q = read();
	for (register int i = 1; i <= n; ++i) a[i] = read(), pos[a[i]].insert(i), m = std :: max(m, a[i]);
	for (register int i = 1; i <= m; ++i) add(i);
	printf("%d\n", n - T.query());
	while (q--){
		int x = read(), y = read();
		erase(x, a[x]), insert(x, y), a[x] = y;
		printf("%d\n", n - T.query());
	}
}