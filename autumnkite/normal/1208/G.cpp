#include <cstdio>
#include <algorithm>
#define N 1000005
int n, k;
int cnt, p[N], vis[N], phi[N];
void init(int n){
	phi[1] = 1;
	for (register int i = 2; i <= n; ++i){
		if (!vis[i]) p[++cnt] = i, phi[i] = i - 1;
		for (register int j = 1; j <= cnt && i * p[j] <= n; ++j){
			vis[i * p[j]] = 1;
			if (i % p[j]) phi[i * p[j]] = phi[i] * phi[p[j]];
			else{ phi[i * p[j]] = phi[i] * p[j]; break; }
		}
	}
}
int main(){
	scanf("%d%d", &n, &k);
	if (k == 1) return puts("3"), 0;
	init(n);
	std :: sort(phi + 1, phi + 1 + n);
	long long sum = 0;
	for (register int i = 1; i <= k + 2; ++i) sum += phi[i];
	printf("%lld\n", sum);
}