# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 5051;
const int P = 998244353;
int n;
ll ans;
int a[MAXN];
int bx[MAXN];
ll s[MAXN][MAXN];
ll f[MAXN][MAXN];
int inv[MAXN];
ll pwr(ll x, ll y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) inv[i] = pwr(i, P - 2);
	for (int i = 1; i <= n; i++) bx[a[i]]++;
	for (int i = n; i >= 1; i--){
		for (int j = 1; j <= n; j++){
			s[i][j] = s[i][j - 1];
			if (!bx[j]) continue;
			if (i + bx[j] - 1 > n) continue;
			f[i][j] = (bx[j] - 1 + s[i + 1][n] - s[i + 1][j]) * inv[n - i] % P;
			s[i][j] = (s[i][j - 1] + f[i][j] * bx[j]) % P;
			if (i == 1) ans = (ans + f[i][j] * bx[j] % P * inv[n]) % P;
			// printf("f %d %d %d\n", i, j, (f[i][j] + P) % P);
			// printf("s %d %d %d\n", i, j, (s[i][j] + P) % P);
		}
	}
	printf("%lld\n", (ans + P) % P);
	return 0;
}