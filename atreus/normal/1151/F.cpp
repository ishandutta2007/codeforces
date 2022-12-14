#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
 
const int maxn = 200 + 10;
const int mod = 1e9 + 7;

int n, a[maxn], fac[maxn];

struct matrix{
	int dp[maxn][maxn];

	void mul(matrix oth){
		int pd[maxn][maxn];
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= n; j++){
				pd[i][j] = 0;
				for (int k = 0; k <= n; k++)
					pd[i][j] = (pd[i][j] + 1ll * dp[i][k] * oth.dp[k][j] % mod) % mod;
			}
		}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				dp[i][j] = pd[i][j];
	}
};

matrix base;

matrix power(matrix a, int b){
	if (b == 1)
		return a;
	matrix ret = power(a, b / 2);
	ret.mul(ret);
	if (b & 1)
		ret.mul(base);
	return ret;
}

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b / 2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		return 1ll * ret * a % mod;
	return ret;
}

int Choose(int n, int r){
	return 1ll * fac[n] * power(fac[r], mod - 2) % mod * power(fac[n - r], mod - 2) % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	fac[0] = 1;
	for (int i = 1; i <= 120; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	int k;
	cin >> n >> k;
	int num = 0, bad = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		num += (a[i] == 0);
	}
	bad = num;
	for (int i = 1; i <= num; i++)
		bad -= (a[i] == 0);
	
	for (int i = 0; i <= num; i++){
		for (int j = 0; j <= num; j++){
			ll pl = 1ll * (n - num - i) * (num - i) % mod;
			ll mn = 1ll * i * i % mod;
			ll tt = Choose(n, 2);
			if (i == j){
				ll tmp = (tt - pl + mod) % mod;
				tmp = (tmp - mn + mod) % mod;
				base.dp[i][j] = tmp * power(tt, mod - 2) % mod;
			}
			else if (j == i + 1)
				base.dp[i][j] = pl * power(tt, mod - 2) % mod;
			else if (j == i - 1)
				base.dp[i][j] = mn * power(tt, mod - 2) % mod;
		}
	}
	n = num;
	matrix x = power(base, k);
	cout << x.dp[bad][0] << endl;
}