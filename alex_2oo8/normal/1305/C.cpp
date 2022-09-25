#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

int a[MX];

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	
	if (n > m) {
		printf("%d\n", 0);
		return 0;
	}
	
	for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
	
	int ans = 1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans = ans * 1LL * abs(a[i] - a[j]) % m;
	
	printf("%d\n", ans);
	
	return 0;
}