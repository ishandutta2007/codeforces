/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 100 + 10;
const int maxm = 1000 + 10;

ld dp[3][maxn * maxm], par[3][maxn * maxm];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (m == 1){ // come onnnnn 
		for (int i = 1; i <= n; i++){
			int come_on;
			cin >> come_on;
		}
		cout << 1.000000000 << endl;
		return 0;
	}
	ld p = 1. / (m - 1);
	bool q = 0;
	for (int i = 0; i <= m * n; i++)
		par[q][i] = 1;
	dp[q][0] = 1;

	int sum = 0;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		q ^= 1;
		sum += x;
		for (int j = 1; j <= n * m; j++){
			if (j > m)
				dp[q][j] = par[1 - q][j - 1] - par[1 - q][j - m - 1];
			else
				dp[q][j] = par[1 - q][j - 1];
			
			if (j - x >= 0)
				dp[q][j] -= dp[1 - q][j - x];
			
			dp[q][j] *= p;
			
			par[q][0] = 0;
			dp[q][0] = 0;
			par[q][j] = par[q][j - 1] + dp[q][j];
		}
	}
	ld answer = 1;
	ld prob = 0;
	for (int i = 0; i < sum; i++)
		prob += dp[q][i];
	answer = prob * (m - 1) + 1;
	cout << fixed << setprecision(10) << answer << endl;
}