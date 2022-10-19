#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
void solve() {
	int n;
	cin >> n;
	ll A[n], B[n], dp[n][2];
	rep(i, n) cin >> A[i];
	rep(i, n) cin >> B[i];
	dp[0][0]=dp[0][1]=0;
	rep(i, n-1) rep(j, 2) {
		dp[i+1][j]=INF;
		rep(l, 2) {
			if(l==j) dp[i+1][j]=min(dp[i+1][j], dp[i][l]+abs(A[i]-A[i+1])+abs(B[i]-B[i+1]));
			else dp[i+1][j]=min(dp[i+1][j], dp[i][l]+abs(A[i]-B[i+1])+abs(B[i]-A[i+1]));
		}
	}
	cout << min(dp[n-1][0], dp[n-1][1]) << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}