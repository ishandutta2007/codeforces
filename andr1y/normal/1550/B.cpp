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
		ll n, a, b;string s;
		cin >> n >> a >> b >> s;
		ll res = a*n;
		if(b>=0) res+=b*n;
		else{
			ll zb=0, ob=0, nb=0, nc=-1;
			for(ll i = 0;i<n;i++){
				if(s[i]=='0'){
					if(nc==0) nb++;
					else{
						if(nb) ob++;
						nb=1, nc=0;
					}
				}else{
					if(nc==1) nb++;
					else{
						if(nb) zb++;
						nb=1, nc=1;
					}
				}
			}
			if(nb){
				if(nc) ob++;
				else zb++;
			}
			res+=(min(zb, ob)+1)*b;
		}
		cout<<res<<'\n';
	}
}