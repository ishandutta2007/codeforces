#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1000005
int n, m, pos[N];
struct node{
	int x, y, w;
}p[N];
std :: vector< std :: pair<int, int> > a[N], b[N];
struct Segment_Tree{
	std :: pair<long long, int> mx[N << 2];
	long long lz[N << 2];
	void up(int u){
		mx[u] = std :: max(mx[u << 1], mx[u << 1 | 1]);
	}
	void add(int u, long long x){
		mx[u].first += x, lz[u] += x;
	}
	void down(int u){
		if (lz[u]) add(u << 1, lz[u]), add(u << 1 | 1, lz[u]), lz[u] = 0;
	}
	void build(int u, int l, int r){
		if (l == r) return mx[u] = std :: make_pair(0, l), void(0);
		int md = (l + r) >> 1;
		build(u << 1, l, md), build(u << 1 | 1, md + 1, r);
		up(u);
	}
	void modify(int u, int l, int r, int L, int R, long long x){
		if (L <= l && r <= R) return add(u, x), void(0);
		int md = (l + r) >> 1;
		down(u);
		if (L <= md) modify(u << 1, l, md, L, R, x);
		if (R > md) modify(u << 1 | 1, md + 1, r, L, R, x);
		up(u);
	}
	std :: pair<long long, int> query(int u, int l, int r, int L, int R){
		if (L <= l && r <= R) return mx[u];
		int md = (l + r) >> 1;
		down(u);
		if (R <= md) return query(u << 1, l, md, L, R);
		else if (L > md) return query(u << 1 | 1, md + 1, r, L, R);
		else return std :: max(query(u << 1, l, md, L, R), query(u << 1 | 1, md + 1, r, L, R));
	}
}T;
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i)
		pos[i] = p[i].x = read(), pos[i + n] = p[i].y = read(), p[i].w = read();
	std :: sort(pos + 1, pos + 1 + (n << 1));
	m = std :: unique(pos + 1, pos + 1 + (n << 1)) - pos - 1;
	for (register int i = 1; i <= n; ++i){
		p[i].x = std :: lower_bound(pos + 1, pos + 1 + m, p[i].x) - pos;
		p[i].y = std :: lower_bound(pos + 1, pos + 1 + m, p[i].y) - pos;
		a[p[i].x].push_back(std :: make_pair(p[i].y, p[i].w));
		b[p[i].y].push_back(std :: make_pair(p[i].x, p[i].w));
	}
	long long sum = 0, ans = 0;
	int ansl = 2e9, ansr = 2e9;
	T.build(1, 0, m), T.modify(1, 0, m, 0, 0, pos[1]);
	for (register int i = 1; i <= m; ++i){
		for (auto v : a[i]) T.modify(1, 0, m, v.first, m, -v.second), sum += v.first <= i ? v.second : 0;
		for (auto v : b[i]) T.modify(1, 0, m, v.first, m, -v.second), sum += v.first < i ? v.second : 0;
		std :: pair<long long, int> res = T.query(1, 0, m, 0, i - 1);
		res.first += sum - pos[i];
		if (res.first > ans) ans = res.first, ansl = pos[res.second + 1], ansr = pos[i];
		T.modify(1, 0, m, i, i, sum + pos[i + 1]);
	}
	printf("%lld\n%d %d %d %d\n", ans, ansl, ansl, ansr, ansr);
}