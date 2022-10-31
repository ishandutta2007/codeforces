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
pll a[N];
ll bana[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n,sai=0;cin>>n;
	for(ll i = 0;i<n;i++){
		cin >> a[i].x >> a[i].y;
		sai+=a[i].x;
	}
	sort(a, a+n, [](pll a, pll b){
		return a.y < b.y;
	});
	ll l = -1, r = sai;
	while(r-l>1){
		ll m = (l+r)>>1;
		ll om=m;
		for(ll i = n-1;i>=0;i--){
			bana[i]=min(a[i].x, om);
			om-=bana[i];
		}
		bool ok = 1;
		ll ab = m;
		for(ll i = 0;i<n;i++){
			if(ab<a[i].y){ok=0;break;}
			else ab+=a[i].x;
		}
		if(ok) r=m;
		else l=m;
	}
	cout<<r+sai;
}