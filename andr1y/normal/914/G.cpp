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
const ll N = 131072;
const ll M = 1e9+7;
ll cnt[N];
ll xr[4][N];
ll fib[N];

ll bpm(ll a, ll b){
	if(b==0) return 1;
	ll res=1;
	while(b){
		if(b&1) res=(res*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return res;
}

namespace FastTransforms{
	void zetaFT(ll *a, ll n){
		for(ll i = 0;i<n;i++){
			for(ll mask = 0;mask<(1<<n);mask++){
				if(mask & (1<<i)){
					a[mask]+=a[mask^(1<<i)];
					if(a[mask]>=M) a[mask]-=M;
				}
			}
		}
	}

	void mobiusFT(ll *a, ll n){
		for(ll i = 0;i<n;i++){
			for(ll mask = 0;mask<(1<<n);mask++){
				if(mask & (1<<i)){
					a[mask]+=M-a[mask^(1<<i)];
					if(a[mask]>=M) a[mask]-=M;
				}
			}
		}
	}

	ll _a[18][N], _b[18][N], _c[18][N];
	void subsetFT(ll *a, ll *b, ll *c, ll n){
		memset(_a, 0, sizeof _a);
		memset(_b, 0, sizeof _b);
		memset(_c, 0, sizeof _c);
		for(ll i = 0;i<(1<<n);i++) _a[__builtin_popcount(i)][i]=a[i];
		for(ll i = 0;i<(1<<n);i++) _b[__builtin_popcount(i)][i]=b[i];
		for(ll i = 0;i<=n;i++) zetaFT(_a[i], n);
		for(ll i = 0;i<=n;i++) zetaFT(_b[i], n);
		for(ll i = 0;i<=n;i++){
			for(ll j = 0;j<=i;j++){
				for(ll mask=0;mask<(1<<n);mask++){
					_c[i][mask]+=(_a[j][mask]*_b[i-j][mask])%M;
					if(_c[i][mask]>=M) _c[i][mask]-=M;
				}
			}
		}
		for(ll i = 0;i<=n;i++) mobiusFT(_c[i], n);
		for(ll i = 0;i<(1<<n);i++) c[i]=_c[__builtin_popcount(i)][i];
	}
	
	void xorFT(ll *a, ll n, bool invert){
		// [[1, 1], [1, -1]]
		for(ll len=1;len<n;len<<=1){
			for(ll i = 0;i<n;i+=len+len){
				for(ll j = 0;j<len;j++){
					ll u = a[i+j], v = a[i+j+len];
					a[i+j]=u+v;
					if(a[i+j]>=M) a[i+j]-=M;
					a[i+j+len]=(M+u-v);
					if(a[i+j+len]>=M) a[i+j+len]-=M;
				}
			}
		}
		if(invert){
			ll rn = bpm(n, M-2);
			for(ll i = 0;i<n;i++) a[i]=(a[i]*rn)%M;
		}
	}

	void andFT(ll *a, ll n, bool invert){
		for(ll len=1;len<n;len<<=1){
			for(ll i = 0;i<n;i+=len+len){
				for(ll j = 0;j<len;j++){
					ll u = a[i+j], v = a[i+j+len];
					if(invert){
						a[i+j] = (M-u+v);
						if(a[i+j]>=M) a[i+j]-=M;
						a[i+j+len] = u;
					}else{
						a[i+j] = v;
						a[i+j+len] = (u+v);
						if(a[i+j+len]>=M) a[i+j+len]-=M;
					}
				}
			}
		}
	}
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	fib[0]=0;
	fib[1]=1;
	for(ll i = 2;i<N;i++){
		fib[i]=(fib[i-1]+fib[i-2]);
		if(fib[i]>=M) fib[i]-=M;
	}
	ll n;
	cin >> n;
	for(ll a, i = 0;i<n;i++){
		cin >> a;
		cnt[a]++;
	}
	//count number of pairs such f(a)*g(b), a|b = i, a&b = 0
	FastTransforms::subsetFT(cnt, cnt, xr[0], 17);
	for(ll i = 0;i<N;i++) xr[1][i]=cnt[i], xr[2][i]=cnt[i];
	FastTransforms::xorFT(xr[1], N, 0);
	for(ll i = 0;i<N;i++) xr[1][i]=(xr[1][i]*xr[1][i])%M;
	FastTransforms::xorFT(xr[1], N, 1);
	for(ll i = 0;i<3;i++){
		for(ll j =0;j<N;j++) xr[i][j]=(xr[i][j]*fib[j])%M;
		FastTransforms::andFT(xr[i], N, 0);
	}
	for(ll j = 0;j<N;j++) xr[3][j]=(((xr[0][j]*xr[1][j])%M) * xr[2][j])%M;
	FastTransforms::andFT(xr[3], N, 1);
	ll res=0;
	for(ll i = 1;i<N;i<<=1) res=(res+xr[3][i]);
	res%=M;
	cout<<res;
}