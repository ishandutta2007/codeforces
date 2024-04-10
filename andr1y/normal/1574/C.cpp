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
	ll n;
	cin >> n;
	ll s=0;
	for(ll i = 0;i<n;i++){
		cin >> a[i];
		s+=a[i];
	}
	sort(a, a+n);
	ll qqq;cin>>qqq;while(qqq--){
		ll x, y;
		cin >> x >> y;
		y=s-y;
		ll of=0;
		if(y<x){
			of+=x-y;
			y=x;
		}
		//ai >= x, ai <= y
		ll fg = upper_bound(a, a+n, y)-a;
		ll fl = lower_bound(a, a+n, x)-a;
		ll ans = LLONG_MAX;
		if(fg<n) ans = min(ans, of+a[fg]-y);
		if(fl<n && a[fl]>=x && a[fl]<=y) ans=min<ll>(ans, of);
		if(fl) ans=min(ans, max(x-a[fl-1], of));
		cout<<ans<<'\n';
	}
}