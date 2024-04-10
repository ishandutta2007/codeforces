#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, y, z, t1, t2, t3;
	ignore = scanf("%d %d %d %d %d %d", &x, &y, &z, &t1, &t2, &t3);
	
	int a = abs(x - y) * t1;
	int b = (abs(x - z) + abs(x - y)) * t2 + 3 * t3;
	
	printf("%s\n", a < b ? "NO" : "YES");
	
	return 0;
}