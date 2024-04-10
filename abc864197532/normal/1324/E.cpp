#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	int input[n];
	fop (i,0,n) cin >> input[i];
	int a[n][n+1], dp[n][n+1];
	int now = 0;
	fop (i,0,n) {
		now += input[i];
		fop (j,0,i+2) {
			if (l <= (now - j + h) % h and (now - j + h) % h <= r) {
				a[i][j] = 1;
			} else {
				a[i][j] = 0;
			}
		}
	}
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	fop (i,1,n) {
	    fop (j,0,i+2) {
	        if (j == 0) dp[i][j] = dp[i-1][j] + a[i][j];
	        else if (j < i + 1) dp[i][j] = max(dp[i-1][j] + a[i][j], dp[i-1][j-1] + a[i][j]);
	        else dp[i][j] = dp[i-1][j-1] + a[i][j];
	    }
	}
	
	int ans = 0;
	fop (i,0,n+1) ans = max(ans, dp[n-1][i]);
	cout << ans << endl;
}