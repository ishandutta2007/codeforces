//ulala
//code by 255
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 2e5+18;
ll a[N], p1[N], p2[N];

namespace ConvexHull{
	pair<pll, ll> st[N];
	ll stc=0;

	void init(ll x, ll b){
		st[0] = {{x, b}, -inf};
		stc=1;
	}

	void add(ll x, ll b){
		ll add_from = inf;
		while(stc){
			pair<pll, ll> top = st[stc-1];
			ll l = top.y;
			__int128 ov = ((__int128)top.x.x)*l + top.x.y;
			__int128 nv = ((__int128)x)*l + b;
			if(nv>=ov) {
				add_from = l;
				--stc;
			}else{
				ll int_top = (b - top.x.y);
				ll int_bot = (top.x.x - x);
				ll int_p = int_top/int_bot;
				if(int_top > 0 && int_p*int_bot < int_top) int_p++;
				add_from=min(add_from, int_p);
				break;
			}
		}
		if(add_from<inf) st[stc++] = {{x, b}, add_from};
	}

	ll get(ll x){
		ll l = 0, r = stc;
		while(r-l>1){
			ll m =(l+r)>>1;
			if(st[m].y <= x) l=m;
			else r=m;
		}
		return st[l].x.x*x + st[l].x.y;
	}
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;cin>>n;
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
		p1[i] = (a[i]+p1[i-1]);
		p2[i] = (i*a[i]+p2[i-1]);
	}
	ConvexHull::init(0, 0);
	ll res=0;
	for(ll r=1;r<=n;r++){
		res=max(res, ConvexHull::get(-p1[r]) + p2[r]);
		ConvexHull::add(r, r*p1[r]-p2[r]);
	}
	cout<<res;
}