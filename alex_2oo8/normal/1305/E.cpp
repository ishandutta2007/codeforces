#include <bits/stdc++.h>

using namespace std;

const int MX = 5000, MV = 1e9;

int f(int n) {
	int res = 0;
	for (int k = 3; k <= n; k++) res += (k - 1) / 2;
	
	return res;
}

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	
	if (f(n) < m) {
		printf("%d\n", -1);
		return 0;
	}
	
	int N = n;
	
	while (n > 1 && f(n - 1) >= m) n--;
	
	for (int i = 1; i <= n - 1; i++) printf("%d ", i);
	
	m -= f(n - 1);

	printf("%d", n - 1 + n - 2 * m);
	
	for (int i = n; i < N; i++) printf(" %d", MV - 2 * n * (N - i));
	printf("\n");
	
	return 0;
}