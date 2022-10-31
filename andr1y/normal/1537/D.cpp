//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 1e5+18;
bool is_win[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	/*for(ll i = 2;i<N;i++){
		bool tol=0;
		for(ll j = 2;j*j<=i;j++){
			if(i%j) continue;
			tol |= !is_win[i-j];
			tol |= !is_win[i-i/j];
			if(tol) break;
		}
		is_win[i]=tol;
	}*/
	/*for(ll i = 1, fs=0;i<N, fs<100;i++){
		if(is_win[i]) cout<<i<<'\n', fs++;
	}*/
	/*bool myc=1;
	for(ll i = 2;i<N;i+=2){
		ll L = 0;
		while((1LL<<L)<=i) L++;
		--L;
		if((1LL<<L)==i && (L&1)) continue;
		myc&=is_win[i];
	}
	cout<<myc;*/
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		bool iw=1;
		if(n&1) iw=0;
		else{
			ll L = 0;
			while((1LL<<L)<=n) L++;
			--L;
			if((1LL<<L)==n && (L&1)) iw=0;
		}
		if(iw) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}