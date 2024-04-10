#include <cstdio>
long long n, m, k, g, x, y;
long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}
int main(){
	scanf("%lld%lld%lld", &n, &m, &k);
	g = gcd(n * m, k);
	if (k / g > 2) return printf("NO"), 0;
	x = n, y = m;
	g = gcd(x, k), x /= g, k /= g, g = gcd(y, k), y /= g, k /= g;
	if (k == 1) if (2 * x <= n) x <<= 1; else y <<= 1;
	printf("YES\n");
	printf("0 0\n");
	printf("%lld 0\n", x);
	printf("0 %lld\n", y);
}