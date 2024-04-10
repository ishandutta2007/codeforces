#include <cstdio>
int n, q;
bool odd(int x){
	return x & 1;
}
int main(){
	scanf("%d%d", &n, &q);
	while (q--){
		int x, y;
		long long ans = 0;
		scanf("%d%d", &x, &y);
		if (odd(x) && odd(y)) ans = 1ll * ((x - 1) >> 1) * n + ((y + 1) >> 1);
		if (!odd(x) && !odd(y)) ans = 1ll * (x >> 1) * n - (n >> 1) + (y >> 1);
		if (odd(x) && !odd(y)) ans = ((1ll * n * n + 1) >> 1) + 1ll * ((x - 1) >> 1) * n + (y >> 1);
		if (!odd(x) && odd(y)) ans = ((1ll * n * n + 1) >> 1) + 1ll * (x >> 1) * n - ((n + 1) >> 1) + ((y + 1) >> 1);
		printf("%I64d\n", ans);
	}
}