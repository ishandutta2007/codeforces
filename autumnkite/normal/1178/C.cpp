#include <cstdio>
#define P 998244353
int n, m, ans;
int main(){
	scanf("%d%d", &n, &m);
	ans = 1;
	for (register int i = 1; i <= n + m; ++i) ans = ans * 2 % P;
	printf("%d\n", ans);
}