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
ll a[N], b[N], pa[N], pb[N];
vector<pll> cp;	
vector<ll> inters;

ll gcdex(ll a, ll b, ll &x, ll &y){
	if(a==0){
		x=0, y=1;
		return a;
	}
	ll x1, y1;
	ll g = gcdex(b%a, a, x1, y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return g;
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, m, k;
	cin >> n >> m >> k;
	for(ll i = 0;i<n;i++){
		cin >> a[i];
		pa[a[i]]=i+1;
	}
	ll g = __gcd(n, m);
	ll period = n*m/g;
	ll okip = 0;
	for(ll i = 0;i<m;i++){
		cin >> b[i];
		pb[b[i]]=i+1;
		if(pa[b[i]] && (pa[b[i]]-1)%g == i%g) okip++, cp.push_back({pa[b[i]]-1, i});
	}
	ll bip = period-okip;
	ll fp = k/bip;
	k%=bip;
	if(k==0){
		fp--, k+=bip;
	}

	ll a, b;
	gcdex(n, m, a, b);

	ll a1=a, b1=b;
	// need b1<=0
	// kn = lm
	ll w = period/n, e = period/m;
	if(b1>0){
		ll nmb = (b1+e-1)/e;
		b1-=nmb*e;
		a1+=nmb*w;
	}
	b1=-b1;
	// now i have a1*n - b1*m = g

	ll a2=a, b2=b;
	// need a1<=0
	// kn = lm
	if(a2>0){
		ll nma = (a2+w-1)/w;
		a2-=nma*w;
		b2+=nma*e;
	}
	a2=-a2;
	// now i have b2*m - a2*n = g


	for(auto i : cp){
		// i.x + a*n - i.y - b*m = 0
		// i.x - i.y = b*m - a*n
		// i.y - i.x = a*n - b*m
		// a*n + b*m == g
		
		if(i.x >= i.y){
			ll rr = (i.x-i.y)/g;
			ll aa = a2*rr, bb = b2*rr;
			inters.push_back((bb*m+i.y)%(period));
		}else{
			ll rr = (i.y-i.x)/g;
			ll aa = a1*rr, bb = b1*rr;
			inters.push_back((aa*n+i.x)%(period));
		}
	}

	sort(begin(inters), end(inters));

	ll l = 0, r = period;
	while(r-l>1){
		ll mid = (l+r)>>1, bad=mid;
		for(auto i : inters){
			if(i>=mid) break;
			bad--;
		}
		if(bad<k) l=mid;
		else r=mid;
	}
	cout<<r+fp*period<<'\n';
}