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
const int LIM=1e5+7, K=450;
const ll INF=1e18+7;
ll dp[LIM][K], T[LIM];
void solve() {
	int n;
	cin >> n;
	rep(i, n) {
		cin >> T[i];
		if(i) T[i]+=T[i-1];
	}
	int k=1;
	while(k*(k+1)/2<=n) ++k;
	rep(i, n+1) rep(j, k) dp[i][j+1]=-INF;
	rep(i, n+1) dp[i][0]=INF;
	for(int i=n-1; i>=0; --i) {
		for(int j=1; j<k; ++j) {
			dp[i][j]=dp[i+1][j];
			if(i+j-1>=n) continue;
			if(T[i+j-1]-(i?T[i-1]:0)<dp[i+j][j-1]) dp[i][j]=max(dp[i][j], T[i+j-1]-(i?T[i-1]:0));
		}
	}
	int ans=1;
	while(dp[0][ans]>0) ++ans;
	cout << ans-1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}