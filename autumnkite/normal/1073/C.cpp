#include <cstdio>
#include <cstring>
int n, x, y;
const int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char a[200005];
int abs(int x){ return x > 0 ? x : -x; }
int check(int len){
	int x1 = 0, y1 = 0;
	for (register int i = len; i < n; ++i) x1 += d[a[i]][0], y1 += d[a[i]][1];
	for (register int i = 0, j = len; j <= n; ++i, ++j){
		if (len >= abs(x - x1) + abs(y - y1) && !((len - abs(x - x1) - abs(y - y1)) & 1)) return 1;
		x1 += d[a[i]][0], y1 += d[a[i]][1], x1 -= d[a[j]][0], y1 -= d[a[j]][1];
	}
	return 0;
}
int main(){
	scanf("%d%s%d%d", &n, a, &x, &y);
	if (abs(x) + abs(y) > n) return printf("-1"), 0;
	for (register int i = 0; i < n; ++i){
		if (a[i] == 'U') a[i] = 0;
		if (a[i] == 'D') a[i] = 1;
		if (a[i] == 'L') a[i] = 2;
		if (a[i] == 'R') a[i] = 3; 
	}
	int l = 0, r = n, mid, ans = -1;
	while (l <= r) check(mid = l + r >> 1) ? ans = mid, r = mid - 1 : l = mid + 1;
	printf("%d\n", ans);
}