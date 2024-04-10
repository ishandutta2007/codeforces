#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, d, h;
	scanf("%d %d %d", &n, &d, &h);
	
	if (d > 2 * h || (d == 1 && n > 2)) {
		printf("-1\n");
		
		return 0;
	}
	
	for (int i = 0; i < h; i++) printf("%d %d\n", i + 1, i + 2);
	
	if (h == d) {
		for (int i = h + 2; i <= n; i++) printf("2 %d\n", i);
		
		return 0;
	}
	
	int v = h + 1;
	while (v < n) {
		int k = min(d - h, n - v);
		
		printf("1 %d\n", v + 1);
		for (int i = 1; i < k; i++) printf("%d %d\n", v + i, v + i + 1);
		
		v += k;
	}
	
	return 0;
}