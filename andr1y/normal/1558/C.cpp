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
const ll N = 2050;
ll a[N];
void rev(ll p, vector<ll> &res, ll &pi, ll &pi1){
	res.push_back(p);
	if(pi<=p) pi=p-pi+1;
	if(pi1<=p) pi1=p-pi1+1;
	for(ll i = 1;i<p-i;i++){
		swap(a[i], a[p-i+1]);
	}
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		bool ok=1;
		for(ll i = 1;i<=n;i++){
			cin >> a[i];
			if((a[i]^i)&1) ok=0;
		}
		if(!ok){
			cout<<"-1\n";
			continue;
		}
		vector<ll> res;
		for(ll i = n;i>1;i-=2){
			ll pi, pi1;
			for(ll j = 1;j<=i;j++){
				if(a[j]==i) pi=j;
				if(a[j]==i-1) pi1=j;
			}
			if(pi1<pi){
				rev(pi, res, pi, pi1);
				if(pi1!=2){
					rev(pi1-1, res, pi, pi1);
					rev(pi1+1, res, pi, pi1);
					rev(3, res, pi, pi1);
				}
			}else if(pi1>pi && pi1!=2){
				rev(pi, res, pi, pi1);
				rev(pi1-1, res, pi, pi1);
				rev(pi1+1, res, pi, pi1);
				rev(3, res, pi, pi1);
			}
			rev(i, res, pi, pi1);
		}
		cout<<res.size()<<'\n';
		for(auto i : res) cout<<i<<' ';
		cout<<'\n';
	}
}