# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 505;
const int P = 998244353;
int n, m;
ll f[MAXN][MAXN];
int main(){
	scanf("%d%d", &n, &m);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			for (int k = 0; k < j; k++) f[i][j] += f[i - j][k];
			for (int k = i - j; k < i; k++) f[i][j] += f[k][j];
			f[i][j] %= P;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; i * j < m && j <= n; j++){
			ans = (ans + f[n][i] * f[n][j]) % P;
		}
	}
	printf("%lld\n", 2 * ans % P);
	return 0;
}