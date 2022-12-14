#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 500 + 10;
const int mod = 998244353;

ll dp[maxn][maxn];
int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int len = 0; len <= n; len++){
		for (int l = 1; l + len - 1 <= n; l++){
			int r = l + len - 1;
			if (len <= 1){
				dp[l][r] = 1;
				continue;
			}
			int mnm = l;
			for (int x = l; x <= r; x++)
				if (a[x] < a[mnm])
					mnm = x;
			if (mnm == l){
				for (int x = l; x <= r; x++)
					dp[l][r] = (dp[l][r] + 1ll * dp[l+1][x] * dp[x + 1][r]) % mod;
				continue;
			}
			else if (mnm == r){
				for (int x = l - 1; x <= r - 1; x++)
					dp[l][r] = (dp[l][r] + 1ll * dp[l][x] * dp[x + 1][r-1]) % mod;
				continue;
			}
			ll presum = 2ll * dp[l][mnm - 1] % mod, sufsum = 2ll * dp[mnm + 1][r] % mod;
			for (int x = l; x < mnm - 1; x++)
				presum = (presum + 1ll * dp[l][x] * dp[x + 1][mnm - 1]) % mod;
			for (int x = mnm + 1; x < r; x++)
				sufsum = (sufsum + 1ll * dp[mnm + 1][x] * dp[x + 1][r]) % mod;
			dp[l][r] = 1ll * presum * sufsum % mod;
		}
	}
	cout << dp[1][n] << endl;
}