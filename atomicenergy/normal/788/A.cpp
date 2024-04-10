#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll ma(vector<ll> v){
	ll t = 0;
	ll m = 0;
	for(ll i=0; i<v.size(); i++){
		t+=v[i];
		if(t<0) t = 0;
		if(t>m) m = t;
	}
	return m;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> v;
	vector<ll> a;
	vector<ll> b;
	for(ll i=0; i<n; i++){
		ll x;
		cin >> x;
		v.push_back(x);
	}
	for(ll i=0; i<n-1; i++){
		if(i%2==0){
			a.push_back(abs(v[i] - v[i+1]));
			b.push_back(-1*abs(v[i] - v[i+1]));
		}else{
			b.push_back(abs(v[i] - v[i+1]));
			a.push_back(-1*abs(v[i] - v[i+1]));
		}
	}
	cout << max(ma(a), ma(b)) << endl;
	
	return 0;
}