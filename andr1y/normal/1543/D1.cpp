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


signed main(){
	ll qqq;cin>>qqq;while(qqq--){
		ll n, k;
		cin >> n >> k;
		ll axn=0;
		for(ll i = 0;i<n;i++){
			cout<<(i^axn)<<endl;
			ll r;cin>>r;
			if(r) break;
			else axn^=(i^axn);
		}
	}
}