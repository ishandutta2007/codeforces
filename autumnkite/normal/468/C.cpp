#include <cstdio>
long long a, l, r, x;
int main(){
	scanf("%lld", &a);
	l = 0, r = 999999999999999999ll;
	for (register int i = 1; i <= 18; ++i)
		for (register int j = 1; j <= 45; ++j)
			x = (x + 100000000000000000ll) % a;
	x = a - x;
	printf("%lld %lld\n", l + x, r + x);
}