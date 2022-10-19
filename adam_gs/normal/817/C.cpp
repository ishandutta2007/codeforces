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
ll f(ll x) {
	ll ans=0;
	while(x) {
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, s;
	cin >> n >> s;
	ll ans=max(0ll, n-s-200+1);
	for(ll i=s; i<=n && i<s+200; ++i) {
		if(i-f(i)>=s) ++ans;
	}
	cout << ans << '\n';
}