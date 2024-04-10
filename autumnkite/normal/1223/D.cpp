#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 300005
int n, l[N], r[N], m;
struct node{
	int x, l, r;
	bool operator < (const node &rhs) const {
		return x < rhs.x;
	}
}a[N];
void solve(){
	n = read(), m = 0;
	for (register int i = 1; i <= n; ++i) l[i] = n + 1, r[i] = 0;
	for (register int i = 1, x; i <= n; ++i)
		x = read(), l[x] = std :: min(l[x], i), r[x] = std :: max(r[x], i);
	for (register int i = 1; i <= n; ++i)
		if (l[i] <= r[i]) a[++m] = (node){i, l[i], r[i]};
	std :: sort(a + 1, a + 1 + m);
	int s = 1, ans = 1;
	for (register int i = 2; i <= m; ++i)
		if (a[i - 1].r < a[i].l) ++s, ans = std :: max(ans, s);
		else s = 1;
	printf("%d\n", m - ans);
}
int main(){
	int T = read();
	while (T--) solve();
}