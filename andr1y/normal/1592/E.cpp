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
const ll N = 1<<20;
ll maxto[N], a[N], xorval[N];
ll lxc[N], lc=0;
vector<ll> lastxor[N][2];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++){
		cin >> a[i];
	}
	ll res=0;
	for(ll L = 19;L>=0;L--){
		++lc;
		ll flag=0;
		for(ll i = 0;i<n;i++){
			xorval[i]<<=1;
			flag^=(a[i]>>(L+1))&1;
			xorval[i]|=flag;
		}
		maxto[0]=(a[0]>>L);
		for(ll i = 1;i<n;i++){
			if((a[i]>>L)&1) maxto[i]=maxto[i-1]+1;
			else maxto[i]=0;
		}
		lxc[0]=lc;
		lastxor[0][0].clear();
		lastxor[0][1].clear();
		lastxor[0][1].push_back(-1);
		for(ll i = 0;i<n;i++){
			ll tk = xorval[i];
			if(lxc[tk] < lc){
				lxc[tk]=lc;
				lastxor[tk][0].clear();
				lastxor[tk][1].clear();
			}
			auto it = lower_bound(lastxor[tk][i&1].begin(), lastxor[tk][i&1].end(), i-maxto[i]);
			if(it!=lastxor[tk][i&1].end()) res=max(res, i-*it);
			lastxor[tk][i&1].push_back(i);
		}
	}
	cout<<res;
}