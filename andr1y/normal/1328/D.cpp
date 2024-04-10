//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		ll dc = 0;
		for(ll i =0;i<n;i++){
			cin >> a[i];
			if(i) dc+=a[i]!=a[i-1];
		}
		dc+=a[n-1]!=a[0];
		if(dc == 0){
			cout << 1 << '\n';
			for(ll i =0;i<n;i++) cout << 1 << ' ';
			cout << '\n';
			continue;
		}
		if(dc!=n){
			cout << 2 << '\n';
			bool c1 = dc&1;
			ll color = 1;
			for(ll i = 0;i<n;i++){
				ll bf = (n+i-1)%n;
				if(a[bf]==a[i]){
					if(c1){
						color&=1;
						color++;
						c1 = 0;
					}
				}else{
					color&=1;
					color++;
				}
				cout << color << ' ';
			}
			cout << '\n';
			continue;
		}
		if(dc == n){
			if(n&1){
				cout << 3 << '\n';
				ll color = 3;
				for(ll i = 0;i<n;i++){
					ll bf = (n+i-1)%n;
					if(a[bf]!=a[i] && i){
						color = (color&1)+1;
					}
					cout << color << ' ';
				}
				cout << '\n';
			}else{
				cout << 2 << '\n';
				ll color = 1;
				for(ll i = 0;i<n;i++){
					ll bf = (n+i-1)%n;
					if(a[bf]!=a[i]){
						color = (color&1)+1;
					}
					cout << color << ' ';
				}
				cout << '\n';
			}
		}
	}
}