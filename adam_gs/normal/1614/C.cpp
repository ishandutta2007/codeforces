#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(ll a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7;
void solve() {
	ll n, m;
	cin >> n >> m;
	ll sum[n+1][30], ile[30];
	rep(i, n+1) rep(j, 30) sum[i][j]=0;
	rep(i, 30) ile[i]=n;
	rep(i, m) {
		ll l, r, x;
		cin >> l >> r >> x; --l;
		rep(j, 30) if(!(x&(1ll<<j))) {
			++sum[l][j];
			--sum[r][j];
		}
	}
	rep(i, n) rep(j, 30) {
		sum[i+1][j]+=sum[i][j];
		if(sum[i][j]) --ile[j];
	}
	ll pot=1, ans=0;
	rep(i, n-1) pot=(2*pot)%MOD;
	rep(i, 30) if(ile[i]) {
		ans+=(1ll<<i)*pot;
		ans%=MOD;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}