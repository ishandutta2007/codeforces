#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, k;
	ignore = scanf("%lld %lld", &n, &k);
	
	printf("%lld\n", max((k - 1) / 2 - max(k - n, 1ll) + 1, 0ll));
	
	return 0;
}