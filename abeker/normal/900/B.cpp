#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

int main() {
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	
	for (int i = 1; i < MAX; i++) {
		if (10 * A / B == C) {
			printf("%d\n", i);
			return 0;
		}
		A = 10 * A % B;
	}
	
	puts("-1");
	
	return 0;
}