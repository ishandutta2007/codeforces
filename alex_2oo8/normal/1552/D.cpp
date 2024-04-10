#include <bits/stdc++.h>

using namespace std;

const int MX = 10;

int a[MX];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n;
		ignore = scanf("%d", &n);
		for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
		
		int mm = 1;
		for (int i = 0; i < n; i++) mm *= 3;
		
		int cnt = 0;
		for (int mask = 0; mask < mm; mask++) {
			int sum = 0, x = mask;
			for (int i = 0; i < n; i++, x /= 3) {
				sum += (x % 3 - 1) * a[i];
			}
			
			if (sum == 0) cnt++;
		}
		
		printf("%s\n", (cnt > 1 ? "YES" : "NO"));
	}
	
	return 0;
}