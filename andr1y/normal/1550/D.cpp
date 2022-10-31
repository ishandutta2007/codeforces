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
const ll N = 2e5+18;
const ll M = 1e9+7;
ll f[N], of[N];
ll bpm(ll a, ll b){
	a%=M;
	if(b==0) return 1;
	if(b==1) return a;
	if(b&1) return (a*bpm(a*a, b>>1))%M;
	else return bpm(a*a, b>>1);
}
inline ll c(ll n, ll k){
	if(k<0) return 0;
	return (((f[n]*of[k])%M)*of[n-k])%M;
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	f[0]=1;
	for(ll i = 1;i<N;i++) f[i]=(f[i-1]*i)%M;
	of[N-1]=bpm(f[N-1], M-2);
	for(ll i= N-2;i>=0;i--) of[i]=(of[i+1]*(i+1))%M;
	ll qqq;cin>>qqq;while(qqq--){
		ll n, l, r;
		cin >> n >> l >> r;
		ll res = 0;
		ll xxx = n/2;
		for(ll dx = r-xxx, it=xxx;dx>0;it=min(it+1, n), dx--){
			ll needl = -dx;
			ll xt = l-1-needl;
			ll ctb = min(n-xt, n);
			if(it==n && ctb<=0){
				ll mindx = n-l;
				dx=mindx+1;
				continue;
			}
			if(ctb<n/2) continue;
			if(ctb+it<n) continue;
			if(ctb==n&&it==n){
				res=(res + ((n&1) ? (c(n, n/2) + c(n, n/2+1)) : c(n, n/2))*dx)%M;
				break;
			}
			ll mid = ctb+it-n;
			ll onlya = it-mid, onlyb = ctb-mid;
			ll afmid = n/2-onlya;
			if(n&1){
				res+=c(mid, afmid) + c(mid, afmid+1);
			}else res+=c(mid, afmid);
			res%=M;
		}
		cout<<res<<'\n';
	}
}