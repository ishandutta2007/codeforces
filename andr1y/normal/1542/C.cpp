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
const ll M = 1e9+7;


signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		ll res=2;
		__int128 nsk=1;
		for(ll i = 2;i<=n+1;i++){
			// diap [2;n]
			nsk = (nsk*(i-1))/__gcd<__int128>(nsk, i-1);
			__int128 nsk2 = (nsk*(i))/__gcd<__int128>(nsk, i);
			if(nsk>n){
				break;
			}
			ll xr = n/nsk - n/nsk2;
			if(nsk==1) xr--;
			if(nsk2==1) xr++;
			res+=(xr*i)%M;
			res%=M;
		}
		cout<<res<<'\n';
	}
}