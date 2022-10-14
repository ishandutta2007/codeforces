#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define MAXN 100087

void solve() {
	int n;
	cin >> n;
	int hei[n], cost[n];
	fop (i,0,n) cin >> hei[i] >> cost[i];
	lli dp[n][3];
	fop (i,0,n) {
		fop (j,0,3) {
			if (i) {
				lli minn = LLONG_MAX;
				fop (k,0,3) {
					if (hei[i] + j == hei[i-1] + k) continue;
					minn = min(minn, dp[i-1][k] + cost[i] * j);
				}
				dp[i][j] = minn;
			} else {
				dp[i][j] = cost[i] * j;
			}
		}
	}
	cout << min({dp[n-1][2], dp[n-1][1], dp[n-1][0]}) << endl;
}


int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}