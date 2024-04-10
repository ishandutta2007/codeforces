#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1005
int n, m, pr[N], pc[N];
char s[N];
int abs(int x){
	return x > 0 ? x : -x;
}
long long solve(int n, int m, int *a){
	long long res = 0;
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= n; ++j)
			res += 1ll * abs(i - j) * (m - (a[i] > 0)) * (m - (a[j] > 0));
	for (register int i = 1; i <= n; ++i)
		if (a[i] > 0){
			res += (a[i] - 1) * (m - a[i]) * 4;
			for (register int j = i - 1; j >= 1 && a[j] > a[j + 1]; --j) res += (a[i] - 1) * (m - a[j]) * 4;
			for (register int j = i + 1; j <= n && a[j] > a[j - 1]; ++j) res += (a[i] - 1) * (m - a[j]) * 4;
		}
	return res;
}
int main(){
	scanf("%d%d", &n, &m);
	int tot = 0;
	for (register int i = 1; i <= n; ++i){
		scanf("%s", s + 1);
		for (register int j = 1; j <= m; ++j)
			if (s[j] == 'X') pr[i] = j, pc[j] = i;
			else ++tot;
	}
	printf("%.12lf\n", 1.0 * (solve(n, m, pr) + solve(m, n, pc)) / (1ll * tot * tot));
}