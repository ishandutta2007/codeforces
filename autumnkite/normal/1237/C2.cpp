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
#define N 50005
int n, vis[N];
struct node{
	int x, y, z, id;
	void init(int i){
		x = read(), y = read(), z = read(), id = i;
	}
	bool operator < (const node &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y) || (x == rhs.x && y == rhs.y && z < rhs.z);
	}
}a[N];
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i].init(i);
	std :: sort(a + 1, a + 1 + n);
	for (register int i = 1, j = 0; i <= n; ++i)
		if (!j || a[j].x != a[i].x || a[j].y != a[i].y) j = i;
		else printf("%d %d\n", a[i].id, a[j].id), vis[i] = vis[j] = 1, j = 0;
	for (register int i = 1, j = 0; i <= n; ++i)
		if (!vis[i])
			if (!j || a[j].x != a[i].x) j = i;
			else printf("%d %d\n", a[i].id, a[j].id), vis[i] = vis[j] = 1, j = 0;
	for (register int i = 1, j = 0; i <= n; ++i)
		if (!vis[i])
			if (!j) j = i;
			else printf("%d %d\n", a[i].id, a[j].id), vis[i] = vis[j] = 1, j = 0;
}