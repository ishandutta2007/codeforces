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
ll a[N], b[N], cnta[101], cntb[101];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;cin>>n;
		memset(cnta, 0, sizeof cnta);
		memset(cntb, 0, sizeof cntb);
		for(ll i = 1;i<=n;i++) cin >> a[i];
		for(ll i = 1;i<=n;i++) cin >> b[i];
		ll u =0,crm=0;
		ll res=-1;
		for(ll i = 1;i<=5*n;i++){
			ll adda = (i<=n ? a[i] : 100);
			ll addb = (i<=n ? b[i] : 0);
			u+=adda-addb;
			cnta[adda]++, cntb[addb]++;
			if(i%4==0) crm++;
			ll rma =0, rmb=0, tra=0, trb=0;
			for(ll j = 0;j<=100;j++){
				ll ta = min(crm-tra, cnta[j]);
				tra+=ta, rma += ta*j;
				ll tb = min(crm-trb, cntb[j]);
				trb+=tb, rmb += tb*j;
			}
			if(i>=n && u-rma+rmb >= 0) {
				res=i-n;
				break;
			}
		}
		cout<<res<<'\n';
	}
}