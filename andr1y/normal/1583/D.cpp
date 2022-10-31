//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ld inf = 0x3fff3fff3fff3fff;
const ll N = 105;
ll a[N], temp[N];

signed main(){
	ll n;
	cin >> n;
	ll maxnow = n;
	for(ll get=n;get>0;get--){
		if(a[get]) continue;
		ll did=0;
		for(ll i = 1;i<n;i++){
			cout<<"? ";
			for(ll j = 1;j<=n;j++){
				if(get==j) cout<<i+1<<' ';
				else cout<<1<<' ';
			}
			cout<<endl;
			ll pos;
			cin >> pos;
			if(pos==0 || pos==get){
				break;
			}else temp[i]=pos, did=i;
		}
		ll th = maxnow - did;
		a[get]=th;
		maxnow = th-1;
		for(ll i = 1;i<=did;i++) a[temp[i]]=th+i;
	}
	cout<<"! ";
	for(ll i = 1;i<=n;i++) cout<<a[i]<<' ';
	cout<<endl;	
}