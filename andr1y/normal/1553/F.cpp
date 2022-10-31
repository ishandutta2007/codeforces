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
ll a[N], fwt[2][N];
void fwinc(ll t, ll a, ll d=0){
	for(;a<N;a+=a&-a) fwt[t][a]+=d;
}
ll fwres(ll t, ll r, ll s=0){
	if(r==0) return 0;
	for(;r;r-=r&-r) s+=fwt[t][r];
		return s;
}
ll p[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, sai=0;
	cin >> n;
	for(ll i = 0;i<n;i++){
		cin >> a[i];
		sai+=a[i];
	}
	p[0]=0;
	cout<<0<<' ';
	ll sum=a[0];
	fwinc(0, a[0], 1);
	for(ll j = 1;a[0]*j<N;j++){
		fwinc(1, a[0]*j, a[0]);
	}
	for(ll i = 1;i<n;i++){
		ll x = sum;
		for(ll j = 1;a[i]*j<N;j++){
			x-=(i-fwres(0, j*a[i]-1))*a[i];
			fwinc(1, a[i]*j, a[i]);
		}
		ll y = (i+1)*a[i] - fwres(1, a[i]);
		sum+=a[i];
		fwinc(0, a[i], 1);
		p[i]=p[i-1]+x+y;
		cout<<p[i]<<' ';
	}
}