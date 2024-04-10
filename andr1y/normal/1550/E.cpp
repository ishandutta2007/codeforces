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
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll N = 2e5+18;
ll xx[17][N];
ll dp[1<<17];
ll n, k;
string s;
bool check(ll x){
	for(ll j = 0;j<k;j++){
		ll last = n;
		ll lnok=n;
		for(ll i = n-1;i>=0;i--){
			if(s[i]!='?'&&s[i]-'a'!=j) lnok=i;
			if(i+x<=lnok) last=i;
			xx[j][i]=last;
		}
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0]=0;
	for(ll fmask=0;fmask<(1<<k);fmask++){
		if(dp[fmask]>=n) continue;
		for(ll fup=0;fup<k;fup++){
			if(fmask&(1<<fup)) continue;
			ll nmask = fmask | (1<<fup);
			ll ntc = xx[fup][dp[fmask]]+x;
			if(ntc>n) continue;
			dp[nmask]=min(dp[nmask], ntc);
		}
	}
	return dp[(1<<k)-1]<=n;
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	cin >> n >> k;
	cin >> s;
	ll l = 0, r = n+1;
	while(r-l>1){
		ll m = (l+r)>>1;
		if(check(m)) l = m;
		else r=m;
	}
	cout<<l;
}