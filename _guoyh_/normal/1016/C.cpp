# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 300051;
int n;
ll ans;
ll g[NR];
ll a[2][NR];
ll f[2][2][NR];
ll s[2][2][NR];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < 2; i++){
		for (int j = 1; j <= n; j++) scanf("%lld", a[i] + j);
	}
	for (int i = 1; i <= n; i++){
		if (i & 1) g[i] = g[i - 1] + a[0][i] * (2 * i - 2) + a[1][i] * (2 * i - 1);
		else g[i] = g[i - 1] + a[1][i] * (2 * i - 2) + a[0][i] * (2 * i - 1);
		// printf("%lld ", g[i]);
	}
	// putchar('\n');
	for (int i = 1; i <= n; i++){
		s[0][0][i] = s[0][0][i - 1] + a[0][i];
		s[1][1][i] = s[1][1][i - 1] + a[1][i];
		f[0][0][i] = f[0][0][i - 1] + a[0][i] * (i - 1);
		f[1][1][i] = f[1][1][i - 1] + a[1][i] * (i - 1);
	}
	s[0][1][n] = s[0][0][n] + a[1][n];
	s[1][0][n] = s[1][1][n] + a[0][n];
	f[0][1][n] = f[0][0][n] + a[1][n] * n;
	f[1][0][n] = f[1][1][n] + a[0][n] * n;
	for (int i = n - 1; i >= 1; i--){
		s[0][1][i] = s[0][1][i + 1] + a[1][i];
		s[1][0][i] = s[1][0][i + 1] + a[0][i];
		f[0][1][i] = f[0][1][i + 1] + a[1][i] * (2 * n - i);
		f[1][0][i] = f[1][0][i + 1] + a[0][i] * (2 * n - i);
	}
	// for (int i = 1; i <= n; i++) printf("%3lld ", f[0][0][i]);
	// putchar('\n');
	// for (int i = 1; i <= n; i++) printf("%3lld ", f[0][1][i]);
	// putchar('\n');
	ll lnm = 0;
	for (int i = 0; i < n; i++){
		ll nw = g[i] + f[i & 1][!(i & 1)][i + 1] - f[i & 1][i & 1][i] + i * (s[i & 1][!(i & 1)][i + 1] - s[i & 1][i & 1][i]);
		// printf("in %d %lld %lld %lld\n", i, nw, f[i & 1][!(i & 1)][i + 1], f[i & 1][i & 1][i]);
		ans = max(ans, nw);
	}
	ans = max(ans, g[n]);
	printf("%lld\n", ans);
	return 0;
}