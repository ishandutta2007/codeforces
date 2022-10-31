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
const ll M = 1e9+7;
ll f[N], of[N];
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

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	f[0]=1;for(ll i = 1;i<N;i++) f[i]=(f[i-1]*i)%M;
	of[N-1]=bpm(f[N-1], M-2);
	for(ll i = N-2;i>=0;i--) of[i]=(of[i+1]*(i+1))%M;
	ll n, m;
	cin >> n >> m;
	ll res = bpm(m, n);
	for(ll i = 1;i<=n;i++){
		ll x1 = bpm(m, i);
		ll x2 = bpm(m-1, n-i);
		ll x3 = (f[n]*of[i-1])%M;
		ll x4 = of[n-i+1];
		ll s1 = (x1*x2)%M;
		ll s2 = (x3*x4)%M;
		ll s = (s1*s2)%M;
		res=(res+s)%M;
	}
	cout<<res;
}