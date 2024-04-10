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
ll p[N][20];
ll h[N];
ll a[N], c[N];

ll up(ll v, ll hme){
	for(ll L = 19;L>=0;L--){
		if((1<<L)<=hme){
			hme-=(1<<L);
			v=p[v][L];
		}
	}
	return v;
}

ll next_to(ll v, ll u){
	if(h[v]>=h[u]) return -1;
	return up(u, h[u]-h[v]-1);
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q >> a[0] >> c[0];
	for(ll i = 1;i<=q;i++){
		ll type;
		cin >> type;
		if(type==1){
			cin >> p[i][0] >> a[i] >> c[i];
			h[i]=h[p[i][0]]+1;
			for(ll L = 1;L<20;L++) p[i][L] = p[p[i][L-1]][L-1];
		}else{
			ll v, nd, rs=0;
			cin >> v >> nd;
			ll fnz = v, bgh=0;
			for(ll L = 19;L>=0;L--){
				if(p[fnz][L] && a[p[fnz][L]]) fnz=p[fnz][L];
			}
			if(a[0]) fnz=0;
			while(fnz!=-1 && nd){
				ll th = min(nd, a[fnz]);
				bgh+=th;
				a[fnz]-=th;
				nd-=th;
				rs+=th*c[fnz];
				fnz=next_to(fnz, v);
			}
			cout<<bgh<<' '<<rs<<endl;
		}
	}
}