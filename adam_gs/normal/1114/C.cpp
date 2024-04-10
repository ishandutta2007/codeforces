#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
ll sprawdz(__int128 p, __int128 x) {
	__int128 akt=x;
	ll ans=0;
	while(akt<=p) {
		ans+=p/akt;
		akt*=x;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, b;
	cin >> n >> b;
	vector<pair<ll,ll>>V;
	for(ll i=2; i*i<=b; ++i) {
		ll akt=0;
		while(b%i==0) {
			b/=i;
			++akt;
		}
		if(akt) V.pb({i, akt});
	}
	if(b>1) V.pb({b, 1});
	ll ans=sprawdz(n, V[0].st)/V[0].nd;
	for(auto i : V) ans=min(ans, sprawdz(n, i.st)/i.nd);
	cout << ans << '\n';
}