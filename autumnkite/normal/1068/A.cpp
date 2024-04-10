#include <cstdio>
long long n, m, k, l, x;
int main(){
	scanf("%lld%lld%lld%lld", &n, &m, &k, &l);
	x = (l + k - 1) / m + 1;
	if (m * x > n) printf("-1\n");
	else printf("%lld\n", x);
}