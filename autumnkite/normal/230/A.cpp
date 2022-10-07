#include <cstdio>
#include <cstring>
#include <algorithm>
int s, n;
struct node{
	int x, y;
	bool operator < (const node &res) const {
		return x < res.x;
	}
}a[1005];
int main(){
	scanf("%d%d", &s, &n);
	for (register int i = 1; i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
	std :: sort(a + 1, a + 1 + n);
	for (register int i = 1; i <= n; ++i)
		if (s <= a[i].x) return printf("NO\n"), 0; else s += a[i].y;
	printf("YES\n");
}