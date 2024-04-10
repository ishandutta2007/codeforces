#include <bits/stdc++.h>

using namespace std;

main() {
	int a, b, x, y; scanf("%d %d", &a, &b);
	x = min(a, b); y = abs(a - b)/2;
	printf("%d %d\n", x, y);
}