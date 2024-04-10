# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int xn = 5e2+10;
int a[xn], dp[xn][xn];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) dp[i][i+1] = 1;
	for (int k=2; k<=n; k++){
		for (int i=0; i<=n-k; i++){
			dp[i][i+k] = 1e9+10;
			for (int j=i; j<i+k-2; j++)
				if (a[i+k-1] == a[j]) dp[i][i+k] = min(dp[i][i+k], dp[i][j]+dp[j+1][i+k-1]);
			if (a[i+k-2] == a[i+k-1]) dp[i][i+k] = min(dp[i][i+k], dp[i][i+k-2]+1);
			dp[i][i+k] = min(dp[i][i+k], dp[i][i+k-1]+1);
		}
	}
	cout << dp[0][n] << endl;
	return 0;
}