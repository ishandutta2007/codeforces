# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 300051;
int n, m, k;
int a[MAXN];
ll s[MAXN], f[MAXN];
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		s[i] = s[i - 1] + a[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		f[i] = -1e18;
		if (i > m) f[i] = f[i - m] - k;
		for (int j = 1; j <= m; j++) f[i] = max(f[i], -s[i - j] - 1ll * k * ((j + m - 1) / m));
		// printf("f %d %lld\n", i, f[i]);
		ans = max(ans, s[i] + f[i]);
	}
	printf("%lld\n", ans);
	return 0;
}