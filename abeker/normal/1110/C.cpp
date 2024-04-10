#include <bits/stdc++.h>
using namespace std;

int f(int x) {
	int pot = 1;
	while (pot < x)
		pot = 2 * pot + 1;
	
	if (pot > x)
		return pot;
	
	for (int i = 2; i * i <= x; i++)
		if (!(x % i))
			return x / i;
	
	return 1;
}

int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int x;
		scanf("%d", &x);
		printf("%d\n", f(x));
	}
	return 0;
}