#include <stdio.h>
int main() {
	char x, y;
	int n, a, b;
	scanf("%c %c", &x, &y);
	scanf("%d", &n);
	if (x == 118) a = 0;
	else if (x == 60) a = 1;
	else if (x == 94) a = 2;
	else a = 3;
	if (y == 118) b = 0;
	else if (y == 60) b = 1;
	else if (y == 94) b = 2;
	else b = 3;
	if ((4 + b - a) % 2 == 1) {
		if ((4 + b - a + n) % 4 == 2) printf("cw");
		else printf("ccw");
	}
	else printf("undefined");
}