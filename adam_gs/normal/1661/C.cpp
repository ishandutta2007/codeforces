#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
const ll INF=1e18+7;
ll T[LIM], P[LIM], n;
bool f(ll x, ll p) {
	ll ile1=(x+1)/2, ile2=x-ile1;
	rep(i, n) {
		P[i]=p-T[i];
		if(P[i]%2==1) {
			--ile1;
			--P[i];
		}
	}
	if(ile1<0) return false;
	ile2+=ile1/2;
	rep(i, n) {
		ile2-=P[i]/2;
		if(ile2<0) return false;
	}
	return true;
}
void solve() {
	cin >> n;
	ll ma=0;
	rep(i, n) {
		cin >> T[i];
		ma=max(ma, T[i]);
	}
	ll ans=INF;
	rep(i, 5) {
		ll p=0, k=1000000000000000000;
		while(p<k) {
			ll sr=(p+k)/2;
			if(f(sr, ma+i)) k=sr; else p=sr+1;
		}
		ans=min(ans, p);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}