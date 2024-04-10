# include <bits/stdc++.h>

using namespace std;

const int xn = 3e5+10;
const int xk = 5e3+10;
long long a[xn],dp[xk][xk];

int main(){
	long long n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a,a+n);
	for (int i=0; i<=k; i++)
		for (int j=0; j<=k; j++) dp[i][j] = 1e18+10;
	dp[0][0] = 0;
	long long x, y, p;
	x = n/k, y = (n + k -1) / k;
	for (int i=0; i<=k; i++){
		for (int j=0; j<=k; j++){
			if (i == 0 and j == 0) continue;
			p = i*x+j*y-1;
			if (p >= n) break;
			if (i == 0 ) dp[i][j] = a[p]-a[p-y+1]+dp[i][j-1];
			else if (j == 0) dp[i][j] = a[p]-a[p-x+1]+dp[i-1][j];
			else dp[i][j] = min(a[p]-a[p-x+1]+dp[i-1][j],a[p]-a[p-y+1]+dp[i][j-1]);
		}
	}
	cout << dp[k-n%k][(n%k)] << endl;
	return 0;
}