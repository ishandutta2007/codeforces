#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n, x;
	cin >> n;
	int T[n];
	vector<int>V[n];
	rep(i, n) cin >> T[i];
	cin >> x;
	rep(i, n-1) if(T[i]+T[i+1]<2*x) V[i+1].pb(0);
	rep(i, n-2) if(T[i]+T[i+1]+T[i+2]<3*x) V[i+2].pb(1);
	int dp[n][2];
	rep(i, n) rep(j, 2) dp[i][j]=0;
	dp[0][1]=1;
	for(int i=1; i<n; ++i) {
		dp[i][1]=min(dp[i-1][0], dp[i-1][1])+1;
		if(!V[i].size()) {
			dp[i][0]=min(dp[i-1][0], dp[i-1][1]);
		} else if(V[i][0]==1) {
			dp[i][0]=min(dp[i-1][1], dp[i-2][1]);
		} else dp[i][0]=dp[i-1][1];
	}
	cout << n-min(dp[n-1][0], dp[n-1][1]) << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}