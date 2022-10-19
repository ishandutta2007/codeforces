#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7;
const int LIM=1e5+7;
vector<int>V[10*LIM];
ll dp[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=1; i<LIM; ++i) {
		for(int j=i; j<10*LIM; j+=i) V[j].pb(i);
	}
	rep(i, 10*LIM) reverse(all(V[i]));
	dp[0]=1;
	int n;
	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		for(auto i : V[a]) dp[i]=(dp[i]+dp[i-1])%MOD;
	}
	ll ans=0;
	rep(i, LIM-1) ans=(ans+dp[i+1])%MOD;
	cout << ans << '\n';
}