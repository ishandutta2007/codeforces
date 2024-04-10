#include <cstdio>
int n;
int main(){
	scanf("%d", &n);
	printf("%d\n", n / 2 + 1);
	int x = 1, y = 1;
	for (register int i = 1; i <= n; ++i){
		printf("%d %d\n", x, y);
		if (i & 1) ++y; else ++x;
	}
}