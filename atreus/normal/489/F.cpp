#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 2000 + 10;
const int inf = 1e9;

int mod;
int a[510], dp[510][510];

int Choose(int n, int r = 2){
	return (1ll * n * (n - 1) / 2) % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> mod;
	for (int i = 0; i < m; i++){
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				a[j] ++;
	}
	int A = 0, B = 0;
	for (int j = 0; j < n; j++){
		if (a[j] == 0)
			A ++;
		else if (a[j] == 1)
			B ++;
	}
	dp[0][0] = 1;
	for (int i = 0; i <= 500; i++){
		for (int j = 0; j <= 500; j++){
			if ((2 * i + j) & 1)
				continue;
			// 2 - 2
			if (i >= 2)
				dp[i][j] = (dp[i][j] + 1ll * Choose(i, 2) * dp[i - 2][j + 2]) % mod;
			
			// 2 - 1
			if (i >= 1 and j >= 1)	
				dp[i][j] = (dp[i][j] + 1ll * i * j * dp[i - 1][j]) % mod;

			// 1 - 1
			if (j >= 2)
				dp[i][j] = (dp[i][j] + 1ll * Choose(j, 2) * dp[i][j - 2]) % mod;
		}
	}
	cout << dp[A][B] << '\n';
}