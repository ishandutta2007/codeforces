#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		
		int n;
		ignore = scanf("%d", &n);
		
		int mn = 1e9 + 42, mx = -1;
		for (int i = 0, x; i < n; i++) {
			ignore = scanf("%d", &x);
			mn = min(mn, x);
			mx = max(mx, x);
		}
		
		printf("%d\n", mn == mx ? n : 1);
	}
	
	return 0;
}