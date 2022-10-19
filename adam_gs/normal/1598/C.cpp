#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	ll n;
	cin >> n;
	ll T[n], sum=0;
	rep(i, n) {
		cin >> T[i];
		T[i]*=2;
		sum+=T[i];
	}
	if(sum%n!=0) {
		cout << 0 << '\n';
		return;
	}
	rep(i, n) T[i]/=2;
	sum/=n;
	map<ll,ll>mp;
	ll ans=0; 
	rep(i, n) {
		ans+=mp[sum-T[i]];
		++mp[T[i]];
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}