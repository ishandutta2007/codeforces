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
const ll N = 3e5+18;
ll a[N];
ll oa[N];


signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	for(ll x, i = 1;i<=n;i++){
		cin >> x;
		oa[i]=x;
		x^=1;
		a[i]=x+a[i-1];
	}
	ll mxr=0, ms=0, mr=-1;
	for(ll i = 0;i<=n;i++){
		ll v = i-(lower_bound(a, a+n, a[i]-k)-a);
		if(v>mxr){
			mxr=v, ms=i-v+1, mr=i;
		}
	}
	cout<<mxr<<'\n';
	for(ll i = 1;i<=n;i++){
		ll u = oa[i];
		if(i>=ms&&i<=mr) u=1;
		cout<<u<<' ';
	}
}