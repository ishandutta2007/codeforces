#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, k, p[N], posp[N], q[N], cnt;
char s[N];
struct node{
	int l, r;
	bool operator < (const node &rhs) const {
		return l < rhs.l || (l == rhs.l && r < rhs.r);
	}
}a[N << 1];
int main(){
	n = read(), k = read();
	for (register int i = 1; i <= n; ++i) p[i] = read(), posp[p[i]] = i;
	for (register int i = 1; i <= n; ++i) q[i] = posp[read()];
	for (register int i = 1; i <= n; ++i) a[++cnt] = (node){i, i};
	for (register int i = 1; i < n; ++i)
		if (q[i] > q[i + 1]) a[++cnt] = (node){q[i + 1], q[i]};
	std :: sort(a + 1, a + 1 + cnt);
	int m = 1;
	for (register int i = 2; i <= cnt; ++i)
		if (a[i].l > a[m].r) a[++m] = a[i];
		else a[m].r = std :: max(a[m].r, a[i].r);
	if (k > m) return puts("NO"), 0;
	for (register int i = 1; i <= m; ++i)
		for (register int j = a[i].l; j <= a[i].r; ++j)
			s[p[j]] = std :: min(26, i) + 'a' - 1;
	printf("YES\n%s\n", s + 1);
}