#include <cstdio>
#include <algorithm>
int n, a[1005];
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i) scanf("%d", a + i);
	std :: sort(a + 1, a + 1 + n);
	printf("%d", a[n] - a[1] + 1 - n);
}