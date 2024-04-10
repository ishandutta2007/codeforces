#include <cstdio>
#include <algorithm>
int n, a[300005];
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i) scanf("%d", a + i);
	if (a[1] != a[n]) return printf("%d\n", n - 1), 0;
	int x = 2, y = n - 1;
	while (a[x] == a[x - 1]) ++x;
	while (a[y] == a[y + 1]) --y;
	printf("%d\n", std :: max(y - 1, n - x));
}