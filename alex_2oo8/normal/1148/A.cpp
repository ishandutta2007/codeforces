#include <bits/stdc++.h>

using namespace std;

long long foo(long long ab, long long a, long long b) {
	long long res = 2 * ab;
	long long f = min(a, b);
	res += 2 * f;
	a -= f;
	b -= f;
	if (a > 0) res++;
	
	return res;
}

int main() {
	long long a, b, c;
	ignore = scanf("%lld %lld %lld", &a, &b, &c);
	
	printf("%lld\n", max(foo(c, a, b), foo(c, b, a)));
	
	return 0;
}