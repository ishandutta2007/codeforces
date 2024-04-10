#include<bits/stdc++.h>

using namespace std;

int a[1000000];

int main() {
	int m;
	scanf("%d", &m);
	
	int n = 0;
	for (int k = 1; k < 10 * m; k++) {
		int p = 0, x = k;
		while (x) {
			x /= 5;
			p += x;
		}
		
		if (p == m) a[n++] = k;
	}
	
	printf("%d\n", n);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}