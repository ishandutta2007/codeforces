#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 2e5 + 10;
const int maxk = 100 + 5;
const int mod = 998244353;

int a[maxn], last1[maxn], last2[maxn], dp[maxn][maxk], DP[maxn], par[maxn][maxk], PAR[maxn];;

int main(){
	ios_base::sync_with_stdio(false);
	int n, k, len;
	cin >> n >> k >> len;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int p1 = -1, p2 = -1;
	for (int i = 1; i <= n; i++){
		last1[i] = p1;
		last2[i] = p2;
		if (a[i] == -1)
			continue;
		if (p1 == -1 or a[p1] == a[i])
			p1 = i;
		else{
			p2 = p1;
			p1 = i;
		}
	}
	DP[0] = 1;
	PAR[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			if (a[i] != -1 and a[i] != j){
				par[i][j] = par[i - 1][j];
				continue;
			}
			int pre = -1;
			if (last1[i] != -1 and a[last1[i]] != j)
				pre = last1[i];
			if (pre == -1 and last2[i] != -1)
				pre = last2[i];
			if (pre == -1)
				pre = 0;

			pre = max(pre, i - len + 1);
			dp[i][j] += PAR[i - 1] - (pre == 0 ? 0 : PAR[pre - 1]);
			if (dp[i][j] >= mod)
				dp[i][j] -= mod;
			if (dp[i][j] < 0)
				dp[i][j] += mod;
		
			dp[i][j] -= (par[i - 1][j] - (pre == 0 ? 0 : par[pre - 1][j]));
			if (dp[i][j] >= mod)
				dp[i][j] -= mod;
			if (dp[i][j] < 0)
				dp[i][j] += mod;
			
			par[i][j] = par[i - 1][j] + dp[i][j];
			if (par[i][j] >= mod)
				par[i][j] -= mod;
			
			DP[i] += dp[i][j];
			if (DP[i] >= mod)
				DP[i] -= mod;
		}
		PAR[i] = PAR[i - 1] + DP[i];
		if (PAR[i] >= mod)
			PAR[i] -= mod;
	}
	cout << DP[n] << endl;
}