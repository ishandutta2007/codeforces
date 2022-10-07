#include <cstdio>
#include <cmath>
#define N 150005
int n, a[N], b[N], cnt, p[N], ans = -1;
void work(int x){
	int k = sqrt(x) + 1;
	cnt = 0;
	for (register int i = 2; i <= k; ++i)
		if (x % i == 0){
			p[++cnt] = i;
			while (x % i == 0) x /= i;
		}
	if (x > 1) p[++cnt] = x;
	for (register int i = 1; i <= cnt; ++i){
		int flag = 1;
		for (register int j = 1; j <= n; ++j)
			if (a[j] % p[i] && b[j] % p[i]) { flag = 0; break; }
		if (flag) return ans = p[i], void(0);
	}
}
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i) scanf("%d%d", a + i, b + i);
	work(a[1]);
	if (ans == -1) work(b[1]);
	printf("%d", ans);
}