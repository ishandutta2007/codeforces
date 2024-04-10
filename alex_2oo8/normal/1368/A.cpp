#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int a, b, n;
		ignore = scanf("%d %d %d", &a, &b, &n);
		
		int ans = 0;
		while (a <= n && b <= n) {
			if (a > b) swap(a, b);
			a += b;
			ans++;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}