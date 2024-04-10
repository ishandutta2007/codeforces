#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ '0');
	return f ? x : -x;
}
const int N = 100005;
int L, R, n, m, l[N], r[N], b[N], k, cnt, p[N << 2], n1, n2;
std :: vector<int> E[N], num[N];
struct node{
	int x, l, r, v;
	bool operator < (const node &rhs) const { return x < rhs.x; }
}a[N * 6];
void GG(){ puts("IMPOSSIBLE"), exit(0); }
void push(int x1, int y1, int x2, int y2, int v){
	if (x1 > x2 || y1 > y2) return;
	a[++m] = (node){x1, y1, y2, v};
	a[++m] = (node){x2 + 1, y1, y2, -v};
}
struct rec{
	int l0, r0, l1, r1;
	void init(){ l0 = l1 = 0, r0 = r1 = 0x3f3f3f3f; }
	void upd(int l, int r, int d){
		if (d == 0) l0 = std :: max(l0, l), r0 = std :: min(r0, r);
		else l1 = std :: max(l1, l), r1 = std :: min(r1, r);
	}
	void work(){
		if (l0 > r0 || l1 > r1) GG();
		push(l0, l1, r0, r1, 1);
		push(l1, l0, r1, r0, 1);
		push(std :: max(l0, l1), std :: max(l0, l1), std :: min(r0, r1), std :: min(r0, r1), -1);
		p[++cnt] = l0, p[++cnt] = l1, p[++cnt] = r0, p[++cnt] = r1;
	}
	bool contain(int x, int y){
		return l0 <= x && x <= r0 && l1 <= y && y <= r1;
	}
}s[N];
void dfs(int u, int d){
	s[k].upd(l[u], r[u], d), num[k].push_back(u), b[u] = d, d ^= 1;
	for (int v : E[u]) if (b[v] == -1) dfs(v, d); else if (b[v] != d) GG();
}
namespace segt{
	struct node{
		int v, p;
	}a[N << 4];
	int lz[N << 4];
	node operator + (const node &a, const node &b){
		if (a.v > b.v) return a; else return b;
	}
	void add(int u, int v){ a[u].v += v, lz[u] += v; }
	void down(int u){
		if (lz[u]) add(u << 1, lz[u]), add(u << 1 | 1, lz[u]), lz[u] = 0;
	}
	void build(int u, int l, int r){
		if (l == r) return a[u].p = l, void(0);
		int md = (l + r) >> 1;
		build(u << 1, l, md), build(u << 1 | 1, md + 1, r);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}
	void modify(int u, int l, int r, int L, int R, int v){
		if (L <= l && r <= R) return add(u, v), void(0);
		int md = (l + r) >> 1;
		down(u);
		if (L <= md) modify(u << 1, l, md, L, R, v);
		if (R > md) modify(u << 1 | 1, md + 1, r, L, R, v);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}
	node query(int u, int l, int r, int L, int R){
		if (L <= l && r <= R) return a[u];
		int md = (l + r) >> 1;
		down(u);
		if (R <= md) return query(u << 1, l, md, L, R);
		else if (L > md) return query(u << 1 | 1, md + 1, r, L, R);
		return query(u << 1, l, md, L, R) + query(u << 1 | 1, md + 1, r, L, R);
	}
}
int main(){
	L = read(), R = read();
	n = read(), m = read();
	for (register int i = 1; i <= n; ++i) l[i] = read(), r[i] = read();
	for (register int i = 1, u, v; i <= m; ++i)
		u = read(), v = read(), E[u].push_back(v), E[v].push_back(u);
	memset(b, -1, sizeof b), m = 0;
	for (register int i = 1; i <= n; ++i)
		if (b[i] == -1) s[++k].init(), dfs(i, 0), s[k].work();
	std :: sort(a + 1, a + 1 + m);
	std :: sort(p + 1, p + 1 + cnt);
	cnt = std :: unique(p + 1, p + 1 + cnt) - p - 1;
	bool flag = 0;
	segt :: build(1, 1, cnt);
	a[m + 1].x = 0x3f3f3f3f;
	for (register int i = 1; i <= m; ++i){
		a[i].l = std :: lower_bound(p + 1, p + 1 + cnt, a[i].l) - p;
		a[i].r = std :: lower_bound(p + 1, p + 1 + cnt, a[i].r) - p;
		segt :: modify(1, 1, cnt, a[i].l, a[i].r, a[i].v);
		if (i == m || a[i].x < a[i + 1].x){
			int l = std :: lower_bound(p + 1, p + 1 + cnt, L - a[i + 1].x + 1) - p;
			int r = std :: upper_bound(p + 1, p + 1 + cnt, R - a[i].x) - p - 1;
			if (l > r) continue;
			segt :: node tmp = segt :: query(1, 1, cnt, l, r);
			if (tmp.v < k) continue;
			n2 = p[tmp.p];
			if (L - n2 < a[i].x) n1 = a[i].x;
			else n1 = L - n2;
			flag = 1; break;
		}
	}
	if (!flag) GG();
	for (register int i = 1; i <= k; ++i)
		if (!s[i].contain(n1, n2)) for (int j : num[i]) b[j] ^= 1;
	puts("POSSIBLE"), printf("%d %d\n", n1, n2);
	for (register int i = 1; i <= n; ++i) putchar(b[i] + '1');
}