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
const ll N = 6006;
ll cnt[2][2];
pll a[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++){
		cin >> a[i].x >> a[i].y;
		a[i].x/=2;
		a[i].y/=2;
	}
	for(ll i = 0;i<n;i++){
		cnt[a[i].x&1][a[i].y&1]++;
	}
	ll res=0;
	for(ll ax =0;ax<2;ax++){
		for(ll ay=0;ay<2;ay++){
			if(cnt[ax][ay]<3) continue;
			ll x = (cnt[ax][ay]*(cnt[ax][ay]-1)*(cnt[ax][ay]-2))/6;
			res=(res+x);
		}
	}
	for(ll ax =0;ax<2;ax++){
		for(ll ay=0;ay<2;ay++){
			for(ll bx =0;bx<2;bx++){
				for(ll by=0;by<2;by++){
					if(cnt[ax][ay]<2 || (ax==bx&&ay==by)) continue;
					ll x = (cnt[ax][ay]*cnt[ax][ay]-cnt[ax][ay])/2;
					x=(x*cnt[bx][by]);
					res=(res+x);
				}
			}
		}
	}
	cout<<res<<'\n';
}