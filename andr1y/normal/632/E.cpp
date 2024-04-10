//ulala
//code by 255
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef int ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll N = (1<<20)+1;
ll a[N], res[N];
void karatsuba(ll *a, ll *b, ll *c, ll n){
	if(n<65){
		for(ll i = 0;i<n;i++){
			for(ll j = 0;j<n;j++){
				c[i+j]+=a[i]*b[j];
			}
		}
	}else{
		ll k = (n>>1);
		ll t1[k], t2[k], t[n] = {0};
		for(ll i = 0;i<k;i++){
			t1[i]=a[i]+a[i+k];
			t2[i]=b[i]+b[i+k];
		}
		karatsuba(t1, t2, t, k);
		karatsuba(a, b, c, k);
		karatsuba(a+k, b+k, c+n, k);
		for(ll i = 0;i<k;i++){
			ll vl = c[i+k] + t[i] - c[i] - c[n+i];
			ll vr = c[i+n] + t[i+k] - c[i+k] - c[n+k+i];
			c[i+k] = vl;
			c[i+n] = vr;
		}
	}
}
void meq(ll *a, ll *b, ll n){
	ll ax[n], bx[n];
	memcpy(ax, a, sizeof ax);
	memcpy(bx, b, sizeof bx);
	memset(a, 0, sizeof ax);
	karatsuba(ax, bx, a, n);
}
void bp(ll k){
	res[0]=1;
	ll n = 1024;
	while(k>1){
		if(k&1){
			meq(res, a, n);
		}
		meq(a, a, n);
		n<<=1;
		k>>=1;
	}
	meq(res, a, n);
}


signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	for(ll i = 0;i<n;i++) {ll aa;cin>>aa;a[aa]=1;}
	bp(k);
	for(ll i = k;i<N;i++){
		if(res[i]) cout<<i<<' ';
	}
}