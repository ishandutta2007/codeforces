#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7;
void solve() {
	int n;
	cin >> n;
	ll T[n], ile[31];
	rep(i, 31) ile[i]=0;
	rep(i, n) {
		cin >> T[i];
		rep(j, 31) if(T[i]&(1<<j)) ++ile[j];
	}
	ll dobre=0;
	rep(i, n) {
		bool ok=true;
		rep(j, 31) if(ile[j]<n && (T[i]&(1<<j))) ok=false;
		if(ok) ++dobre;
	}
	ll ans=(dobre*(dobre-1))%MOD;
	for(ll i=1; i<=n-2; ++i) {
		ans=(ans*i)%MOD;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}