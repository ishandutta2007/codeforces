#include <iostream>
#define int long long
using namespace std;
 
const int N = 155;
const int inf = 1000 * 1000 * 1000 + 5;
 
int a[N];
long long dp[N][N][N];
long long mdp[N][N];
long long dp2[N][N][N];
long long maxdp[N][N];
int32_t main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == -1)
			a[i] = -inf;
	}
	string s;
	cin >> s;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i + j <= n; i++) {
			for (int k = 0; k <= n; k++) {
				dp[i][j][k] = -1ll * inf * inf;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		dp[i][0][1] = a[1];
		dp2[i][0][1] = a[1];
		maxdp[i][0] = a[1];
		mdp[i][0] = a[1];
	//	cout << "24 " << i << " " << 0 << " " << i << " " << dp[i][0][i] << endl;
	}
	for (int i = 0; i < n - 1; i++) {
		dp[i][1][1] = 2 * a[1];
		dp2[i][1][1] = max(2 * a[1], a[1]);
		if (s[i] == s[i + 1])
			dp[i][1][2] = a[2];
		else
			dp[i][1][2] = 1ll * -inf * inf;
		dp2[i][1][2] = dp[i][1][2];
		maxdp[i][1] = max(dp[i][1][1], dp[i][1][2]);
		mdp[i][1] = max(maxdp[i][1], 0ll);
	//	maxdp[i][1] = max(maxdp[i][1], 0ll);
	//	dp2[i][1][2] = dp[i][1][i + 1];
	}
 
	for (int j = 2; j < n; j++) {
		for (int i = 0; i + j < n; i++) {
			maxdp[i][j] = 1ll * -inf * inf;
			int l = i, r = i + j;
			for (int k = 1; k <= j + 1; k++) {
				dp[i][j][k] = 1ll * -inf * inf;
				for (int q = l; q < r; q++) {
				//	if (s[l] == s[q]) {
						dp[i][j][k] = max(dp[i][j][k], maxdp[i][q - i] + dp[q + 1][r - q - 1][k]);
						dp[i][j][k] = max(dp[i][j][k], dp[i][q - i][k] + maxdp[q + 1][r - q - 1]);
						dp2[i][j][k] = max(dp2[i][j][k], mdp[i][q - i] + dp2[q + 1][r - q - 1][k]);
						dp2[i][j][k] = max(dp2[i][j][k], dp2[i][q - i][k] + mdp[q + 1][r - q - 1]);
				//	}
				}
				
				if (k > 1 && s[i] == s[r]) {
					dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j - 2][k - 2] + a[k] - a[k - 2]);
					dp2[i][j][k] = max(dp2[i][j][k], dp[i][j][k]);
				}	
			//	cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
				maxdp[i][j] = max(maxdp[i][j], dp[i][j][k]);
				mdp[i][j] = max(mdp[i][j], dp2[i][j][k]);
			}
			if (s[l] == s[r]) {
				dp[i][j][2] = max(dp[i][j][2], maxdp[i + 1][j - 2] + a[2]);
				maxdp[i][j] = max(maxdp[i][j], dp[i][j][2]);
				dp2[i][j][2] = max(dp[i][j][2], dp2[i][j][2]);
				mdp[i][j] = max(mdp[i][j], dp2[i][j][2]);
			}
			mdp[i][j] = max(maxdp[i][j], mdp[i][j]);
			mdp[i][j] = max(mdp[i][j], mdp[i][j - 1]);
			mdp[i][j] = max(mdp[i][j], mdp[i + 1][j - 1]);
		//	for (int k = 1; k <= j + 1; k++) {
		//		cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
		//	}
			
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; i + j < n; j++) {
			ans = max(ans, mdp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}