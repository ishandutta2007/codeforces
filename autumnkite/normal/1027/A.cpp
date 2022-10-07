#include <cstdio>
#include <cstring>
int T, n;
char a[105];
int abs(int a){
	return a > 0 ? a : -a;
}
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d%s", &n, a + 1);
		int flag = 1;
		for (register int i = 1, j; i <= n / 2; ++i)
			if (a[i] != a[j = n - i + 1] && abs(a[i] - a[j]) != 2) { flag = 0; break; }
		if (flag) printf("YES\n"); else printf("NO\n");
	}
}