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
ll nwd(ll a, ll b) {
	if(!a) return b;
	return nwd(b%a, a);
}
void solve() {
	ll n;
	cin >> n;
	while(true) {
		ll x=n, p=0;
		while(x) {
			p+=x%10;
			x/=10;
		}
		if(nwd(n, p)>1) {
			cout << n << '\n';
			return;
		}
		++n;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}