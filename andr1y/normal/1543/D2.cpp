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
ll num[70], num2[2][70], num3[70];

signed main(){
	ll qqq;cin>>qqq;while(qqq--){
		ll n, k;
		cin >> n >> k;
		ll axn=0;
		memset(num, 0, sizeof num);
		memset(num2, 0, sizeof num2);
		memset(num3, 0, sizeof num3);
		//num == i, num2 == SUMA YGRYKIV
		for(ll i = 0;i<n;i++){
			ll x=0;
			for(ll j=0, e=1;j<70;j++){
				if(e>1000000000) {
					num3[j]=0;
					continue;
				}

				ll vj = ((i&1) ? k-num[j] : num[j])%k;
				ll va = ((i&1) ? num2[0][j] : k-num2[0][j])%k;
				ll vb = ((i&1) ? k-num2[1][j] : num2[1][j])%k;
				num3[j] = (vj+va+vb)%k;

				x+=num3[j]*e;
				e*=k;
			}
			cout<<x<<endl;
			ll r;cin>>r;
			if(r) break;
			else{
				for(ll j = 0;j<70;j++) num2[i&1][j] = (num2[i&1][j]+num3[j])%k;
			}
			num[0]++;
			ll j=0;while(num[j]==k){
				num[j+1]++;
				num[j]=0;
				j++;
			}
		}
	}
}