# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int xn = 3e1+1;
const int xk = 5e1+1;
const int xans = 4.1e4;
ll dp[xn][xn][xk];
ll ans[xans];

int main(){
	int t;
	cin >> t;
	for (int i=1; i<=30; i++){
		for (int j=1; j<=30; j++){
			for (int k=0; k<=50; k++){
				if (k == 0 or k == i*j) continue;
				else if (k > i*j){
					dp[i][j][k] = 1e9+10;
					continue;
				}
				dp[i][j][k] = 1e9+10;
				for (int l=1; l<=(i)/2; l++)
					for (int p=0; p<=k; p++) dp[i][j][k] = min(dp[i][j][k], j*j+dp[l][j][p]+dp[i-l][j][k-p]);
				for (int l=1; l<=(j)/2; l++)
					for (int p=0; p<=k; p++) dp[i][j][k] = min(dp[i][j][k], i*i+dp[i][l][p]+dp[i][j-l][k-p]);
			}
		}
	}
	for (int i=0; i<t; i++){
		int n, m, k;
		cin >> n >> m >> k;
		ans[i] = dp[n][m][k];
	}
	for (int i=0; i<t; i++) cout << ans[i] << endl;
	return 0;
}