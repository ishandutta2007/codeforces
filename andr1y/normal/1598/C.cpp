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
ll a[N];
map<ll,ll> cn;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cn.clear();
		cin >> n;
		ll s= 0;
		for(ll i = 0;i<n;i++){
			cin >> a[i];
			s+=a[i];
		}
		/* 
		 s / n = (s-a-b) / (n-2)
		 s*(n-2)-(s-a-b)*n / (n)(n-2) = 0
		 sn - 2s -sn + an + bn = 0
		 an + bn - 2s = 0
		 n(a+b) = 2s
		*/
		ll x = (s+s);
		if(x%n){
			cout<<"0\n";
		}else{
			x/=n;
			ll res=0;
			for(ll i = 0;i<n;i++){
				res+=cn[x-a[i]];
				cn[a[i]]++;
			}
			cout<<res<<'\n';
		}
	}	
}