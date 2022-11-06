#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

const ll md = 998244353;

ll inv(ll a, ll b = md){
	return a>1 ? b - inv(b%a, a)*b/a : 1LL;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> facs(n+2,1);
	rep(i,1,n+2) facs[i] = facs[i-1] * i % md;

	vector<ll> dp(n+2);

	ll seen = 0;
	rrep(k,1,n+1){
		ll tot = facs[n] * inv(facs[k]) % md;
		dp[k] = (tot - seen) % md;
		seen = (seen + dp[k]) % md;
	}
	ll ans = 0;
	rep(k,1,n+1) ans = (ans + max(1, n-k) * dp[k]) % md;
	if(ans < 0) ans += md;
	cout << ans << endl;
}