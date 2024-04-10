#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,int>
#define X first
#define Y second
#define MAXN 100087

int main () {
	int n;
	cin >> n;
	int in[n+1], dp[n+1][n+1][2], need = 0; // odd
	fop (i,1,n+1) cin >> in[i];
	fop (i,0,n+1) fop (j,0,n+1) fop (k,0,2) dp[i][j][k] = 1 << 30;
	dp[0][0][0] = dp[0][0][1] = 0;
	fop (i,1,n+1) {
		if (in[i] & 1) need++;
	}
	need = (n + 1) / 2 - need;
	fop (i,1,n+1) {
		fop (j,0,need+1) {
			if (in[i] == 0) {
				dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1] + 1);
				if (j) dp[i][j][1] = min(dp[i-1][j-1][0] + 1, dp[i-1][j-1][1]);
			} else {
				int k = in[i] & 1;
				dp[i][j][k] = min(dp[i-1][j][k^1] + 1, dp[i-1][j][k]);
			}
			//cout << i << ' ' << j << ':' << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
		}
	}
	cout << min(dp[n][need][0], dp[n][need][1]) << endl;
}