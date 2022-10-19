#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int sum = 0, mx = 0;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
		mx = max(mx, x);
	}
	printf("%d\n", max(mx, (2 * sum) / N + 1));
	return 0;
}