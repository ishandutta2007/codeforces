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
ll a[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		bool f1=0, l0=0;
		ll x01p = -1;
		for(ll i = 0;i<n;i++){
			cin >> a[i];
			if(i==0 && a[i] == 1) f1=1;
			if(i==n-1 && a[i] == 0) l0=1;
			if(i && a[i-1]==0 && a[i]==1) x01p = i-1;
		}
		if(f1){
			cout<<n+1<<' ';
			for(ll i = 1;i<=n;i++) cout<<i<<' ';
			cout<<'\n';
		}else if(l0){
			for(ll i = 1;i<=n+1;i++) cout<<i<<' ';
			cout<<'\n';
		}else if(x01p!=-1){
			for(ll i = 0;i<=x01p;i++) cout<<i+1<<' ';
			cout<<n+1<<' ';
			for(ll i = x01p+1;i<n;i++) cout<<i+1<<' ';
			cout<<'\n';
		}else cout<<"-1\n";
	}
}