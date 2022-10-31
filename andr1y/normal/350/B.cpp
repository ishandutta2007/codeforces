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
ll type[N], cf[N];
vector<ll> d[N];
ll can[N];


signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i = 1;i<=n;i++) cin>>type[i];
	for(ll i = 1;i<=n;i++){
		cin >> cf[i];
		if(cf[i]) can[cf[i]]++;
	}
	for(ll i = 1;i<=n;i++){
		if(cf[i] && can[cf[i]]<2) d[i].push_back(cf[i]);
	}
	ll mxl=0;
	vector<ll> steps;
	for(ll i = 1;i<=n;i++){
		if(type[i]){
			ll ml=0;
			vector<ll> ms;
			ll ii = i;
			while(d[ii].size()==1){
				ms.push_back(ii);
				ii=d[ii][0];
				++ml;
			}
			if(d[ii].size()==0) {
				ms.push_back(ii);
				++ml;
			}
			if(ml>mxl){
				mxl=ml;
				steps.clear();
				steps=ms;
				reverse(steps.begin(), steps.end());
			}
		}
	}
	cout<<mxl<<'\n';
	for(auto i: steps) cout<<i<<' ';
}