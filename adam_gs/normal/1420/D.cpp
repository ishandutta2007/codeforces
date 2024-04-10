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
const ll MOD=998244353;
ll sil[LIM], osil[LIM];
ll pot(ll a, ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%MOD;
		b/=2;
		a=(a*a)%MOD;
	}
	return ans;
}
ll c(ll n, ll k) {
	if(k>n) return 0;
	return (((sil[n]*osil[k])%MOD)*osil[n-k])%MOD;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	sil[0]=1;
	for(ll i=1; i<LIM; ++i) sil[i]=(sil[i-1]*i)%MOD;
	osil[LIM-1]=pot(sil[LIM-1], MOD-2);
	for(ll i=LIM-2; i>=0; --i) osil[i]=(osil[i+1]*(i+1))%MOD;
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>>V;
	rep(i, n) {
		int l, r;
		cin >> l >> r;
		V.pb({l, 1});
		V.pb({r+1, -1});
	}
	ll ans=0, akt=0;
	sort(all(V));
	for(auto i : V) {
		if(i.nd==-1) --akt;
		else {
			ans=(ans+c(akt, k-1))%MOD;
			++akt;
		}
	}
	cout << ans << '\n';
}