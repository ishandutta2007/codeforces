#include <cstdio>
int n;
long long b[500005], a[500005];
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= (n >> 1); ++i) scanf("%lld", b + i);
	a[1] = 0, a[n] = b[1];
	for (register int i = 2, j = n - 1; i < j; ++i, --j){
		a[i] = a[i - 1], a[j] = b[i] - a[i];
		if (a[j] > a[j + 1]) a[i] += a[j] - a[j + 1], a[j] = a[j + 1];
	}
	for (register int i = 1; i <= n; ++i) printf("%lld ", a[i]);
}