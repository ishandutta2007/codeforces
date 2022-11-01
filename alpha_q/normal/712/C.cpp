#include <bits/stdc++.h>

using namespace std;

int x, y;

int main (int argc, char const *argv[]) {
	scanf("%d %d", &x, &y);

	int a = y, b = y, c = y, tmp, steps = 0;

	while (1) {
		tmp = min(b + c - 1, x);
		a = b, b = c, c = tmp;
		++steps;
		if (a == x and b == x and c == x) break;
	}

	printf("%d\n", steps);
	return 0;
}