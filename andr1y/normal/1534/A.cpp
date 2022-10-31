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
const ll inf = 0x3fff3fff3fff3ff;
const ll N = 1e5+18;


signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n, m;
		cin >> n >> m;
		char ev = 'R', od = 'W';
		bool fix=0, ok=1;
		for(ll i = 0;i<n;i++){
			for(ll j = 0;j<m;j++){
				char c;cin>>c;
				if(c=='.') continue;
				if((i+j)&1){
					if(c==od) fix=1;
					else{if(fix)ok=0;else{swap(ev, od);fix=1;}}
				}else{
					if(c==ev) fix=1;
					else{if(fix)ok=0;else{swap(ev, od);fix=1;}}
				}
			}
		}
		if(ok){
			cout<<"YES\n";
			for(ll i = 0;i<n;i++){
				for(ll j = 0;j<m;j++){
					if((i+j)&1) cout<<od;
					else cout<<ev;
				}
				cout<<'\n';
			}
		}else cout<<"NO\n";
	}
}