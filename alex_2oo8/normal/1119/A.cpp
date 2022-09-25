#include <bits/stdc++.h>

using namespace std;

const int MX = 300000;

int a[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
	
	int x = 0;
	while (a[x] == a[0]) x++;
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == a[0]) ans = max(ans, abs(i - x));
		else ans = max(ans, i);
	}
	
	printf("%d\n", ans);
	
	return 0;
}