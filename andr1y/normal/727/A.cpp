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
const ll N = 1e5+18;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll a, b;
	cin >> a >> b;
	vector<ll> ops;
	bool ok=0;
	while(b>=a){
		ops.push_back(b);
		if(b==a) {ok=1;break;}
		if(b&1){
			if(b%10==1)b/=10;
			else break;
		}else{
			b/=2;
		}
	}
	if(ok){
		cout<<"YES\n";
		cout<<ops.size()<<'\n';
		for(ll i = ops.size()-1;i>=0;i--) cout<<ops[i]<<' ';
	}else cout<<"NO\n";
}