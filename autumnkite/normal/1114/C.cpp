#include <cstdio>
#include <cstring>
#include <algorithm>
long long n, b, t, ans = 1000000000000000000ll;
long long getans(long long n, long long x, long long y){
	long long res = 0;
	while (n) res += n /= x;
	return res / y;
}
int main(){
	scanf("%lld%lld", &n, &b), t = b;
	for (register int i = 2; 1ll * i * i <= b; ++i){
		long long s = 0;
		while (t % i == 0) t /= i, ++s;
		if (s) ans = std :: min(ans, getans(n, i, s));
	}
	if (t > 1) ans = std :: min(ans, getans(n, t, 1));
	printf("%lld", ans);
}