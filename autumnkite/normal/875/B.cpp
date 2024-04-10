#include <cstdio>
#include <cctype>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int n, a[300005];
int main(){
	n = read();
	printf("1 ");
	for (register int i = 1; i <= n; ++i){
		int x = read();
		a[x] = 1;
		while (a[n]) --n, --i;
		printf("%d ", i + 1);
	}
	return 0;
}