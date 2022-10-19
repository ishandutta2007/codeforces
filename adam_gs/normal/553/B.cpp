#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7, LIM=57;
ll dp[LIM];
vector<int>solve(ll n, ll k) {
	vector<int>ans, V;
	if(!n) return ans;
	if(k<=dp[n-1]) {
		ans.pb(1);
		V=solve(n-1, k);
		rep(i, V.size()) ans.pb(V[i]+1);
		return ans;
	}
	ans.pb(2);
	ans.pb(1);
	V=solve(n-2, k-dp[n-1]);
	rep(i, V.size()) ans.pb(V[i]+2);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	dp[0]=dp[1]=1;
	for(ll i=2; i<LIM; ++i) dp[i]=dp[i-1]+dp[i-2];
	ll n, k;
	cin >> n >> k;
	vector<int>ans=solve(n, k);
	for(auto i : ans) cout << i << " ";
	cout << '\n';
}