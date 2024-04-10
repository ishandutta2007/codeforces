#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const ll MOD=1e9+7;
ll nwd(ll a, ll b) {
	if(!a) return b;
	return nwd(b%a, a);
}
void solve() {
	ll n;
	cin >> n;
	ll akt=1, ans=n%MOD;
	for(ll i=1; akt<=n; ++i) {
		akt=akt/nwd(akt, i)*i;
		ans+=n/akt;
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