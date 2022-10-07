#include <cstdio>
int b, g, n, ans;
int main(){
	scanf("%d%d%d", &b, &g, &n);
	for (register int i = 0; i <= b; ++i)
		if (n - i >= 0 && n - i <= g) ++ans;
	printf("%d\n", ans);
}