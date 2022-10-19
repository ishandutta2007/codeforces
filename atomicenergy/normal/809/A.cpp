#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll mod = 1e9+7;

ll twos(ll a){
	if(a==0) return 1;	
	ll z = twos(a/2);
	if(a%2==0) return (z*z)%mod;
	return ((z*z)%mod*2)%mod;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> a;
	for(ll i=0; i<n; i++){
		ll x;
		cin >> x;
		a.push_back(x);
	}
	ll ans = 0;
	sort(a.begin(), a.end());
	for(ll i=0; i<n; i++){
		ans+=((a[i] * twos(i))%mod);
		ans%=mod;
		ans-=((a[i] * twos(n-1-i))%mod);
		ans+=mod;
		ans%=mod;
	}	
	cout << ans << endl;
	
}