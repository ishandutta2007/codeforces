#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		long long n;
		ignore = scanf("%lld", &n);
		
		bool ok = n >= 15 && 1 <= n % 14 && n % 14 <= 6;
		printf("%s\n", ok ? "YES" : "NO");
	}
	
	return 0;
}