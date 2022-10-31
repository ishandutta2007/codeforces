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
ll fnd(ll x){
	if(x>=1000000000) return 1000000000;
	if(x>=100000000) return 100000000;
	if(x>=10000000) return 10000000;
	if(x>=1000000) return 1000000;
	if(x>=100000) return 100000;
	if(x>=10000) return 10000;
	if(x>=1000) return 1000;
	if(x>=100) return 100;
	if(x>=10) return 10;
	return 1;
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll s, n;
		cin >> s >> n;
		vector<ll> cs;
		cs.push_back(s);
		for(ll it = 1;it<n;it++){
			ll fs0=0;
			while(fs0<it && fnd(cs[fs0]) == cs[fs0]) fs0++;
			if(fs0==it){
				fs0=0;
				ll fx=inf;
				for(ll i = 0;i<it;i++){
					if(fnd(cs[i])>1){
						if(cs[i]<fx){
							fx=cs[i], fs0=i;
						}
					}
				}
				assert(fs0!=it);
				ll u  =fnd(cs[fs0]);
				u/=10;
				cs[fs0]-=u;
				cs.push_back(u);
			}else{
				ll u = fnd(cs[fs0]);
				cs[fs0]-=u;
				cs.push_back(u);
			}
		}
		for(auto i : cs) cout<<i<<' ';
		cout<<'\n';
	}
}