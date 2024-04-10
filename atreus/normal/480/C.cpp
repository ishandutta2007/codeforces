#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 5000 + 10;
const int mod = 1e9 + 7;

int dp[2][maxn], par[2][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	for (int i = 1; i <= n; i++){
		dp[0][i] = 1;
		par[0][i] = par[0][i - 1] + dp[0][i];
	}
	for (int i = 1; i <= k; i++){
		int p = (i % 2);
		for (int j = 1; j <= n; j++){
			if (j == b)
				continue;
			int L, R;
			int dis = abs(j - b);
			if (j < b){
				L = max(j - dis + 1, 1);
				R = b - 1;
			}
			else{
				L = b + 1;
				R = min(j + dis - 1, n);
			}
			dp[p][j] = par[1 - p][R] - par[1 - p][L - 1];
			if (dp[p][j] < 0)
				dp[p][j] += mod;
			dp[p][j] -= dp[1 - p][j];
			if (dp[p][j] < 0)
				dp[p][j] += mod;
		}
		for (int j = 1; j <= n; j++){
			par[p][j] = par[p][j - 1] + dp[p][j];
			if (par[p][j] >= mod)
				par[p][j] -= mod;
		}
	}
	cout << dp[(k % 2)][a] << endl;
}