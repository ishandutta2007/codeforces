#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if (a == b) {
		printf("%d %d\n", a * 100, a * 100 + 1);
		return 0;
	}
	if (a + 1 == b) {
		printf("%d %d\n", a, b);
		return 0;
	}
	if (a == 9 && b == 1) {
		printf("%d %d\n", 9, 10);
		return 0;
	}
	puts("-1");
	return 0;
}