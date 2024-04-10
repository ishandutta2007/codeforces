#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	
	long long ans = 0;
	for (int i = 0; i < k && n > 1; i++, n -= 2) ans += 2 * (n - 2) + 1;
	
	printf("%lld\n", ans);
	
	return 0;
}