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
const int LIM=5e6+7;
vector<int>dziel[LIM];
ll T[LIM], ile[LIM], dp[LIM];
void solve() {
	int n;
	cin >> n;
	rep(i, n) {
		int a;
		cin >> a;
		++T[a];
	}
	for(int i=2; i<LIM; ++i) {
		if(dziel[i].size()) continue;
		for(int j=i; j<LIM; j+=i) dziel[j].pb(j/i);
	}
	for(int i=1; i<LIM; ++i) {
		for(int j=i; j<LIM; j+=i) ile[i]+=T[j];
	}
	ll ans=0;
	for(ll i=1; i<LIM; ++i) {
		for(auto j : dziel[i]) dp[i]=max(dp[i], dp[j]-ile[i]*j);
		dp[i]+=i*ile[i];
		ans=max(ans, dp[i]);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}