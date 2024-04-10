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
ll ra[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll rows, n;
		cin >> rows >> n;
		for(ll i = 0;i<n;i++){
			cin >> a[i].x;
			a[i].y=i;
		}
		sort(a, a+n, [](pll a, pll b){
			if(a.x != b.x) return a.x < b.x;
			return a.y > b.y;
		});
		for(ll i = 0;i<n;i++) ra[a[i].y]=i;
		yree cnt;
		ll res=0;
		for(ll i = 0;i<n;i++){
			res+=cnt.order_of_key(ra[i]);
			cnt.insert(ra[i]);
		}
		cout<<res<<'\n';
	}
}