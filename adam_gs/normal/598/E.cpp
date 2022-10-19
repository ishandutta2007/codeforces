#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7;
int dp[31][31][51];
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	cout << dp[n][m][k] << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	rep(i, 31) rep(j, 31) rep(l, 50) dp[i][j][l+1]=INF;
	for(int i=1; i<=30; ++i) for(int j=1; j<=30; ++j) for(int l=1; l<=50; ++l) {
		if(i*j==l) dp[i][j][l]=0;
		if(i*j<=l) continue;
		rep(k, i+1) rep(p, l+1) {
			dp[i][j][l]=min(dp[i][j][l], dp[k][j][p]+dp[i-k][j][l-p]+j*j);
		}
		rep(k, j+1) rep(p, l+1) {
			dp[i][j][l]=min(dp[i][j][l], dp[i][k][p]+dp[i][j-k][l-p]+i*i);
		}
	}
	int _;
	cin >> _;
	while(_--) solve();
}