#include <bits/stdc++.h>
using namespace std;

int main() {
	int y, b, r;
	scanf("%d%d%d", &y, &b, &r);
	printf("%d\n", 3 * min(min(y + 1, b), r - 1));
	return 0;
}