#include <bits/stdc++.h>

using namespace std;

const int MX = 100;

int x[MX], y[MX];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n;
		ignore = scanf("%d", &n);
		for (int i = 0; i < n; i++) ignore = scanf("%d", x + i);
		for (int i = 0; i < n; i++) ignore = scanf("%d", y + i);
		
		sort(x, x + n);
		sort(y, y + n);
		
		for (int i = 0; i < n; i++) printf("%d ", x[i]);
		printf("\n");
		
		for (int i = 0; i < n; i++) printf("%d ", y[i]);
		printf("\n");
	}
	
	return 0;
}