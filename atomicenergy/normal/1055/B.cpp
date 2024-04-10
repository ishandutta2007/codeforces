#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n, m, l;
	cin >> n >> m >> l;
	vector<ll> v;
	ll segs = 0;
	for(ll i=0; i<n; i++){
		ll x;
		cin >> x;
		v.push_back(x);
		if(x > l && (i == 0 || v[i-1] <= l)){
			segs++;
		}
	}
	
	for(ll j=0; j<m; j++){
		ll x;
		cin >> x;
		if(x == 0){
			if(n==1){
				if(v[0] > l){
					cout << 1 << endl;
				}else{
					cout << 0 << endl;
				}
			}
			else{
			
				cout << segs << endl;	
			}
		}
		else{
			
			ll y, z;
			cin >> y >> z;
			v[y-1] += z;
			if(n==1) continue;
			if(v[y-1] > l && v[y-1]-z <= l){
				if(y == 1 ){
					if(v[1] <= l)
						segs++;
				}
				else if(y == n ){
					if(v[n-2] <= l)
						segs++;
				}
				else if(v[y-2] <=l && v[y] <= l){
					segs++;
				}else if(v[y-2] >l && v[y] > l){
					segs--;
				}
			}
		}
	}
}