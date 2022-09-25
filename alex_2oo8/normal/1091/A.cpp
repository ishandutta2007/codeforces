#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	ignore = scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", min(min(a, b - 1), c - 2) * 3 + 3);
	
	return 0;
}