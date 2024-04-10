#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x, y, z;
	scanf("%lld%lld%lld", &x, &y, &z);
	printf("%lld\n", (x + y) / z);
	x %= z;
	y %= z;
	if (x > y)
		swap(x, y);
	printf("%lld\n", x + y < z ? 0 : min(x, z - y));
	return 0;
}