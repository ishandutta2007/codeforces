#include <bits/stdc++.h>

using namespace std;

int main() {
	int b, k, s = 0;
	ignore = scanf("%d %d", &b, &k);
	while (k--) {
		int x;
		ignore = scanf("%d", &x);
		if (k > 0) s ^= (b & x) % 2;
		else s ^= x % 2;
	}
	
	printf("%s\n", s == 0 ? "even" : "odd");
	
	return 0;
}