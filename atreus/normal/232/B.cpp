#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 100 + 10;
const int mod = 1e9 + 7;

int fac[maxn], revfac[maxn], dp[maxn * maxn];
int C[maxn][2];

int power(int a, ll b){
	b %= (mod - 1);
	if (b == 0)
		return 1;
	int ret = power(a, b / 2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

ll Choose(int n, int r){
	return 1ll * fac[n] * revfac[r] % mod * revfac[n - r] % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	ll m;
	cin >> n >> m >> k;
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	revfac[n] = power(fac[n], mod - 2);
	for (int i = n - 1; i >= 0; i--)
		revfac[i] = 1ll * revfac[i + 1] * (i + 1) % mod; 
	
	for (int i = 1; i <= n; i++){
		C[i][0] = power(Choose(n, i), m / n);
		C[i][1] = power(Choose(n, i), (m + n) / n);
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = min((i + 1) * n, k); j >= 0; j--){
			for (int k = 1; k <= min(n, j); k++){
				dp[j] = (dp[j] + 1ll * dp[j - k] * C[k][(m % n) > i]) % mod;
			}
		}
	}
	cout << dp[k] << endl;
}