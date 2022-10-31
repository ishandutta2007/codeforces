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
const ld inf = 1e9+3;
const ll N = 5e5+18;
pll a[N];
pair<ld, ll> op[N];
ll cnt[N], sc=0;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++){
		cin >> a[i].x >> a[i].y;
	}
	ld l = 0, r = 1e9+5;
	for(ll IT = 0;IT<200;IT++){
		ld m = (l+r)/2;
		bool did=0;
		ld last = -1e30;
		for(ll i = 0;i<n;i++){
			ld x = a[i].y;
			x*=m;
			x+=a[i].x;
			if(a[i].y > 0){
				last=max(last, x);
			}else{
				if(x < last) did=1;
			}
		}
		if(did) r=m;
		else l=m;
	}
	if(r<inf) cout<<fixed<<setprecision(16)<<r;
	else cout<<-1;
}