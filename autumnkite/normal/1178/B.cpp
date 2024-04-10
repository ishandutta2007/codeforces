#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000005
int n, f[N], g[N];
char a[N];
long long ans;
void solve(int *f){
	int s = 0, sum = 0;
	for (register int i = 1; i <= n; ++i)
		if (a[i] == 'o'){
			if (s) sum += s - 1;
			f[i] = sum, s = 0;
		}
		else ++s;
}
int main(){
	scanf("%s", a + 1), n = strlen(a + 1);
	solve(f), std :: reverse(a + 1, a + 1 + n), solve(g);
	for (register int i = 1; i <= n; ++i)
		if (a[i] == 'o') ans += 1ll * f[n - i + 1] * g[i];
	printf("%lld", ans);
}