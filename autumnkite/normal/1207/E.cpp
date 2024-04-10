#include <cstdio>
int a[100], x;
int query(int a[]){
	putchar('?');
	for (register int i = 0; i < 100; ++i) printf(" %d", a[i]);
	putchar('\n'), fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}
int main(){
	for (register int i = 0; i < 100; ++i) a[i] = (i + 1) << 7;
	x = query(a) & ((1 << 7) - 1);
	for (register int i = 0; i < 100; ++i) a[i] = i + 1;
	x |= query(a) >> 7 << 7;
	printf("! %d\n", x), fflush(stdout);
}