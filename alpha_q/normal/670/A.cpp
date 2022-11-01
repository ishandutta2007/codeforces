#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);

	int n; scanf("%d", &n);
	int y = 2 * (n/7) + min(2, n % 7);
	int x = 2 * (n/7) + (n % 7 == 6);
	printf("%d %d\n", x, y);
	return 0;
}