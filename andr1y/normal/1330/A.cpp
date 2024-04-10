//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
		ll n, x;
		cin >> n >> x;
		map<ll, bool> mp;
		for(ll a, i =0;i<n;i++){
			cin >> a;
			mp[a] = 1;
		}
		ll c = 1;
		while(x){
			if(mp[c]) ++c;
			else{
				x--;
				c++;
			}
		}
		while(mp[c]) c++;
		cout << c-1 << '\n';
	}
}