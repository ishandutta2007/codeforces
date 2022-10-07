#include <cstdio>
long long n, p, a, b, x, y;
int main(){
	scanf("%lld%lld%lld%lld", &n, &p, &a, &b);
	while (y < a && (p - 1ll * b * y) % a) ++y;
	if (y == a) return puts("-1"), 0;
	x = (p - 1ll * b * y) / a;
	if (x < 0 || x + y > n) return puts("-1"), 0;
	printf("%lld %lld %lld\n", x, y, n - x - y);
}