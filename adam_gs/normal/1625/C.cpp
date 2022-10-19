#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=507, INF=1e9+7;
int dp[LIM][LIM], D[LIM], A[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, l, k;
	cin >> n >> l >> k;
	rep(i, n) cin >> D[i];
	D[n]=l;
	rep(i, n) cin >> A[i];
	for(int i=n-1; i>=0; --i) rep(j, k+1) {
		dp[i][j]=INF;
		for(int t=0; i+t<n && t<=j; ++t) {
			dp[i][j]=min(dp[i][j], (D[i+t+1]-D[i])*A[i]+dp[i+t+1][j-t]);
		}
	}
	cout << dp[0][k] << '\n';
}