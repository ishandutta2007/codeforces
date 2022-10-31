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
		ll a, b, c, m;
		cin >> a >> b >> c >> m;
		ll n = a+b+c;
		if(m>=n){
			cout<<"no\n";
			continue;
		}
		m = n-1-m;
		if(a<b) swap(a, b);
		if(b<c) swap(b, c);
		if(a<b) swap(a, b);
		ll mx = c+b+min(a, c+b+1)-1;
		ll mn = (c ? 2 : (b ? 1 : 0));
		if(m>=mn && m<=mx) cout<<"yes\n";
		else cout<<"no\n";
	}
}