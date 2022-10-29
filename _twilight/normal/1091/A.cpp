#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int a, b, c;

int main() {
	scanf("%d%d%d", &a, &b, &c);
	int ans = 6;
	if (b >= a + 1 && c >= a + 2)
		ans = max(3 * a + 3, ans);
	if (a >= b - 1 && c >= b + 1)
		ans = max(3 * b, ans);
	if (a >= c - 2 && b >= c - 1)
		ans = max(3 * c - 3, ans);
	printf("%d\n", ans);
	return 0;
}