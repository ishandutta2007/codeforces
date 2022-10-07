#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
const int N = 105;
int n, m, p[N * 3], f[N][N * 3], pre[N * 3], suf[N * 3];
struct node{
	int x, l, r;
	bool operator < (const node &rhs) const { return x < rhs.x; }
}a[N];
void chkmx(int &a, int b){ b > a ? a = b : 0; }
int main(){
	n = read();
	for (register int i = 1, t; i <= n; ++i){
		a[i].x = read(), t = read(), a[i].l = a[i].x - t, a[i].r = a[i].x + t;
		p[++m] = a[i].x, p[++m] = a[i].l, p[++m] = a[i].r;
	}
	std :: sort(a + 1, a + 1 + n);
	std :: sort(p + 1, p + 1 + m);
	m = std :: unique(p + 1, p + 1 + m) - p - 1;
	for (register int i = 1; i <= n; ++i){
		a[i].x = std :: lower_bound(p + 1, p + 1 + m, a[i].x) - p;
		a[i].l = std :: lower_bound(p + 1, p + 1 + m, a[i].l) - p;
		a[i].r = std :: lower_bound(p + 1, p + 1 + m, a[i].r) - p;
	}
	f[n][a[n].l] = f[n][a[n].x] = p[a[n].r] - p[a[n].x];
	for (register int i = n; i > 1; --i){
		for (register int j = 1; j <= m; ++j){
			chkmx(f[i - 1][j], f[i][j]);
			chkmx(f[i - 1][a[i - 1].l], f[i][j] + p[std :: min(a[i - 1].x, j)] - p[a[i - 1].l]);
		}
		pre[0] = suf[m + 1] = 0;
		for (register int j = 1; j <= m; ++j) pre[j] = std :: max(pre[j - 1], f[i][j] + p[j]);
		for (register int j = m; j; --j) suf[j] = std :: max(suf[j + 1], f[i][j]);
		int mn = 1e9;
		for (register int j = i - 1; j; --j){
			int l = std :: min(a[j].x, mn);
			chkmx(f[j][l], suf[a[j].r] + p[a[j].r] - p[l]);
			chkmx(f[j][l], pre[a[j].r] - p[l]);
			mn = std :: min(mn, a[j].l);
		}
	}
	int ans = 0;
	for (register int i = 1; i <= m; ++i) chkmx(ans, f[1][i]);
	printf("%d\n", ans);
}