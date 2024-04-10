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
		ll n, k;
		cin >> n >> k;
		ll p2 = 0, pc = 0;
		for(ll i = 1;;i++){
			if(p2 + i >= k) break;
			p2+=i;
			++pc;
		}

		ll p1 = n-1-pc-1, pp2 = n-(k-p2);
		for(ll i = 0;i<n;i++){
			if(i==p1||i==pp2) cout << 'b';
			else cout << 'a';
		}
		cout << '\n';
	}
}