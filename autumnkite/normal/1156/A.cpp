#include <cstdio>
int n, a[105], ans;
int main(){
	scanf("%d%d", &n, &a[1]);
	for (register int i = 2; i <= n; ++i){
		scanf("%d", &a[i]);
		if (i > 2 && a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2) ans += 2;
		else if (a[i - 1] == 1 && a[i] == 3 || a[i - 1] == 3 && a[i] == 1) ans += 4;
		else if (a[i - 1] == 1 && a[i] == 2 || a[i - 1] == 2 && a[i] == 1) ans += 3;
		else if (a[i - 1] == 2 && a[i] == 3 || a[i - 1] == 3 && a[i] == 2) return printf("Infinite\n"), 0;
	}
	printf("Finite\n");
	printf("%d\n", ans);
}