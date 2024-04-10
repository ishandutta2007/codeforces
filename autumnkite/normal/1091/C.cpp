#include <cstdio>
#include <algorithm>
int n, cnt;
long long ans[100005];
long long calc(int k){
	int x = n / k;
	return 1ll * k * x * (x - 1) / 2 + x;
}
int main(){
	scanf("%d", &n);
	for (register int i = 1; i * i <= n; ++i)
		if (n % i == 0) ans[++cnt] = calc(i), ans[++cnt] = calc(n / i);
	std :: sort(ans + 1, ans + 1 + cnt);
	cnt = std :: unique(ans + 1, ans + 1 + cnt) - ans - 1;
	for (register int i = 1; i <= cnt; ++i) printf("%lld ", ans[i]);
}