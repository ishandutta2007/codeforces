#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, q, a[N], cnt, l[N], sz[N], vis[N], tot, ans;
struct node{
	int x, y, w;
	bool operator < (const node &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
}b[N];
int main(){
	n = read(), q = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	for (register int i = n; i; --i) l[a[i]] = i, ++sz[a[i]];
	for (register int i = n; i; --i)
		if(!vis[a[i]]) b[++tot] = (node){l[a[i]], i, sz[a[i]]}, vis[a[i]] = 1;
	std :: sort(b + 1, b + 1 + tot);
	int ls = 0, mx = 0;
	for (register int i = 1; i <= tot; ++i)
		if (b[i].x > ls) ls = b[i].y, ans += mx, mx = b[i].w;
		else ls = std :: max(ls, b[i].y), mx = std :: max(mx, b[i].w);
	ans += mx;
	printf("%d\n", n - ans);
}