#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;


int main() {
	int ans = 0, x;
	putchar('?');
	for (int i = 1; i <= 100; i++) {
		printf(" %d", i << 7);
	}
	putchar('\n');
	fflush(stdout);
	scanf("%d", &x);
	ans = x & 127;
	putchar('?');
	for (int i = 1; i <= 100; i++) {
		printf(" %d", i);
	}
	putchar('\n');
	fflush(stdout);
	scanf("%d", &x);
	ans |= (x >> 7) << 7;
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}