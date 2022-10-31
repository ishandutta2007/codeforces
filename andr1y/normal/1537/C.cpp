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
const ll N = 2e5+18;
ll a[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		for(ll i = 0;i<n;i++){
			cin >> a[i];
		}
		sort(a, a+n);
		ll md = a[n-1]-a[0];
		for(ll i = 1;i<n;i++) md=min(md, a[i]-a[i-1]);
		ll fp = -1;
		for(ll i = 1;i<n;i++){
			if(a[i]-a[i-1]==md){
				fp=i;
				break;
			}
		}
		cout<<a[fp-1]<<' ';
		for(ll i = fp+1;i<n;i++){
			cout<<a[i]<<' ';
		}
		for(ll i = 0;i<fp-1;i++) cout<<a[i]<<' ';
		cout<<a[fp]<<'\n';
	}
}