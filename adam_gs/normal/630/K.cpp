#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
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
const int LIM=11;
int cp[LIM];
vector<int>pi;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(ll i=2; i<LIM; ++i) {
		if(cp[i]) continue;
		pi.pb(i);
		for(ll j=2*i; j<LIM; j+=i) cp[j]=1;
	}
	ll n;
	cin >> n;
	ll ans=0;
	rep(i, 1<<pi.size()) {
		ll akt=1;
		rep(j, pi.size()) if(i&(1<<j)) akt*=pi[j];
		if(__builtin_popcount(i)%2==1) {
			ans-=n/akt;
		} else {
			ans+=n/akt;
		}
	}
	cout << ans << '\n';
}