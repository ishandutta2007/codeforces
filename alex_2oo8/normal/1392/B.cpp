#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

int a[MX];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n;
		long long k;
		ignore = scanf("%d %lld", &n, &k);
		for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
		
		if (k > 10) {
			k = k % 2 == 0 ? 10 : 11;
		}
		
		while (k--) {
			int d = *max_element(a, a + n);
			for (int i = 0; i < n; i++) a[i] = d - a[i];
		}
	
		for (int i = 0; i < n; i++) printf("%d ", a[i]);
		printf("\n");
	}
	
	return 0;
}