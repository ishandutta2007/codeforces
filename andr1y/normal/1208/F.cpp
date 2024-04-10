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
const ll N = 1e6+18;
pll max2[1<<21];
ll val2[1<<21];
ll a[N];

void upd(pll &a, ll b){
	if(a.x < b){
		a.y = a.x;
		a.x = b;
	}else if(a.x > b && a.y < b){
		a.y = b;
	}
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	memset(max2, 255, sizeof max2);
	for(ll i = 0;i<n;i++){
		cin >> a[i];
	}
	for(ll i = n-1;i>=0;i--){
		if(max2[a[i]].x==-1){
			max2[a[i]].x = i;
		}else if(max2[a[i]].y==-1){
			max2[a[i]].y = i;
		}
	}
	for(ll mask = (1<<21)-1;mask>=0;mask--){
		for(ll i =0;i<21;i++){
			if((mask>>i)&1) continue;
			upd(max2[mask], max2[mask|(1<<i)].x);
			upd(max2[mask], max2[mask|(1<<i)].y);
		}
		val2[mask]=max2[mask].y;
	}
	ll res=0;
	for(ll i = 0;i<n;i++){
		ll nd = ((1<<21)-1)^a[i];
		if(val2[0]>i){
			ll took = 0;
			for(ll j = 20;j>=0;j--){
				if((nd>>j)&1){
					ll tt = (took^(1<<j));
					if(val2[tt]>i){
						took = tt;
					}
				}
			}
			res=max(res,took|a[i]);
		}
	}
	cout<<res;
}