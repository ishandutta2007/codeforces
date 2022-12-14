/**
 *    author:  Atreus
 *    created: 21.01.2019
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 4e3 + 10;
int c[maxn][maxn];
int dp[maxn][maxn], pd[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++){
		c[0][i] = 1;
		for (int j = 1; j <= i; j++)
			c[j][i] = (c[j - 1][i - 1] + c[j][i - 1]) % mod;
	}
	dp[0][0] = 1;
	pd[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			dp[i][j] = (dp[i - 1][j - 1] + 1ll * dp[i - 1][j] * j % mod) % mod;
			pd[i] = (pd[i] + dp[i][j]) % mod;
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++)
		answer = (answer + 1ll * c[i][n] * pd[n - i] % mod) % mod;
	cout << answer << endl;
}