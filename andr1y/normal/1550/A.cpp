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
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll s;
		cin>>s;
		ll n=1;--s;
		for(ll i = 3;s>=i;i+=2){
			s-=i, n++;
		}
		if(s){
			if(s&1){
				if(s==1) ++n;
				else n++;
			}else n++;
		}
		cout<<n<<'\n';
	}
}