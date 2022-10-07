#include <cstdio>
#include <algorithm>
int n;
struct node{
	int x, y;
	bool operator < (const node &res) const {
		return x < res.x || x == res.x && y < res.y;
	}
}a[1005], b[1005], c[1005];
bool check(){
	for (register int i = 1; i <= n; ++i)
		if (a[i].x != c[i].x || a[i].y != c[i].y) return 0;
	return 1;
}
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
	std :: sort(a + 1, a + 1 + n);
	for (register int i = 1; i <= n; ++i) scanf("%d%d", &b[i].x, &b[i].y);
	for (register int i = 1; i <= n; ++i){
		int x = a[1].x + b[i].x, y = a[1].y + b[i].y;
		for (register int j = 1; j <= n; ++j)
			c[j].x = x - b[j].x, c[j].y = y - b[j].y;
// 		printf("%d %d\n", x, y);
// 		for (register int j = 1; j <= n; ++j) printf("%d %d\n", c[j].x, c[j].y);
		std :: sort(c + 1, c + 1 + n);
		if (check()) return printf("%d %d\n", x, y), 0;
	}
}