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
ll a[N], b[N];
ll sp[N][20];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		for(ll i = 0;i<n;i++){
			cin >> a[i];
		}
		b[0]=1;
		for(ll i = 1;i<n;i++) b[i]=abs(a[i]-a[i-1]);
		for(ll i = 0;i<n;i++) sp[i][0]=b[i];
		for(ll L = 1;L<20;L++){
			for(ll i = 0;i<n;i++){
				sp[i][L] = __gcd(sp[i][L-1], sp[(i + (1<<(L-1)))%n][L-1]);
			}
		}
		ll res=0;
		for(ll i = 0;i<n;i++){
			ll cf = (i+1)%n, tx=1;
			ll ag = 0;
			for(ll L = 19;L>=0;L--){
				if(__gcd(sp[cf][L], ag)>1){
					ag=__gcd(sp[cf][L], ag);
					cf += (1<<L);
					cf%=n;
					tx+=(1<<L);
				}
			}
			tx=min(tx, n);
			res=max(res, tx);
		}
		cout<<res<<'\n';
	}
}