//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ld inf = 0x3fff3fff3fff3fff;
const ll N = 1e5+18;
bool can[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
		ll n, m;
		cin >> n >> m;
		memset(can, 1, sizeof(can[0])*n);
		for(ll i = 0;i<m;i++){
			ll a, b, c;
			cin >> a >> b >> c;
			--a,b--, c--;
			can[b]=0;
		}
		ll root=0;
		for(ll i = 0;i<n;i++){
			if(can[i]){
				root=i;
				break;
			}
		}
		for(ll i = 0;i<n;i++){
			if(i==root) continue;
			cout<<root+1<<' '<<i+1<<'\n';
		}
	}
}