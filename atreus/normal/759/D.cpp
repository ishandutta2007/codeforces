#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 5000 + 10;
const int mod = 1e9 + 7;

int dp[maxn][maxn];
int last[30];
int fac[maxn], rev[maxn];

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b/2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

int C(int n, int r){
	return 1ll * fac[n] * rev[r] % mod * rev[n-r] % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++){
		memset(last, -1, sizeof last);
		for (int j = 0; j < n; j++){
			int k = (int)(s[j] - 'a');
			if (i - 1 <= j){
				if (i == 1)
					dp[i][j] = (last[k] == -1);
				else{
					if (last[k] == -1)
						dp[i][j] = dp[i-1][j-1];
						else 
						dp[i][j] = (dp[i-1][j-1] - dp[i-1][last[k]] + mod) % mod;
				}
			}
			if (j > 0)
				dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
			last[k] = j;
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	rev[n] = power(fac[n], mod-2);
	for (int i = n-1; i >= 0; i--)
		rev[i] = 1ll * rev[i + 1] * (i + 1) % mod;
	int answer = 0;
	for (int i = 1; i <= n; i++)
		answer = (answer + 1ll * dp[i][n-1] * C(n - 1, i - 1)) % mod;
	cout << answer << endl;
}