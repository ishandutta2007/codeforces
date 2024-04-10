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
pll a[N];
/*struct line{
	ll a, b, c;
	pll mid;
	line (ll a, ll b, ll c) : a(a), b(b), c(c) {};
	line (pll da, pll db){
		mid = {(da.x+db.x)/2, (da.y+db.y)/2};
		a = db.y-da.y;
		b = da.x-db.x;
		c = -da.x*(db.y-da.y)-da.y*(da.x-db.x);
	}
	void norm(){
		if(a<0 || (a==0 && b<0)){
			a=-a;
			b=-b;
			c=-c;
		}
		ll g = __gcd(abs(a), __gcd(abs(b), abs(c)));
		a/=g;
		b/=g;
		c/=g;
	}
	line perp(){
		return line{-b, a, b*mid.x - a*mid.y};
	}
	bool operator<(const line d) const {
		return (a==d.a ? (b == d.b ? c < d.c : b < d.b) : a<d.a);
	}
};*/ 
map<pll, ll> cont;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++){
		cin >> a[i].x >> a[i].y;
		a[i].x<<=1;
		a[i].y<<=1;
	}
	ll res=0;
	for(ll i = 1;i<n;i++){
		for(ll j = 0;j<i;j++){
			pll mid = {(a[i].x+a[j].x)/2, (a[i].y+a[j].y)/2};
			res+=cont[mid];
			cont[mid]++;
		}
	}
	cout<<res;
}