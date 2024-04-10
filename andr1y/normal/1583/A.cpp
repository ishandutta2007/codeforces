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
const ll N = 20005;
bool is[N];
ll a[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	for(ll i = 2;i<N;i++){
		if(!is[i]){
			for(ll j = i+i;j<N;j+=i) is[j]=1;
		}
	}
	ll q;
	cin >> q;
	while(q--){
		ll n, s=0;
		cin >> n;
		for(ll i = 0;i<n;i++){
			cin >> a[i];
			s+=a[i];
		}
		if(is[s]){
			cout<<n<<'\n';
			for(ll i =0;i<n;i++) cout<<i+1<<' ';
			cout<<'\n';
			continue;
		}
		bool f=0;
		for(ll i = 0;i<n;i++){
			if(is[s-a[i]]){
				cout<<n-1<<'\n';
				f=1;
				for(ll j=0;j<n;j++){
					if(i==j) continue;
					cout<<j+1<<' ';
				}
				cout<<'\n';
				break;
			}
		}
		if(f) continue;
		for(ll i = 0;i<n&&!f;i++){
			for(ll j = 0;j<i;j++){
				if(is[s-a[i]-a[j]]){
					cout<<n-2<<'\n';
					f=1;
					for(ll k = 0;k<n;k++){
						if(i==k || j==k) continue;
						cout<<j+1<<' ';
					}
					cout<<'\n';
					break;
				}
			}
		}
		if(f) continue;
		for(ll i = 0;i<n&&!f;i++){
			for(ll j = 0;j<i&&!f;j++){
				for(ll k = 0;k<j;k++){
					if(is[s-a[i]-a[j]-a[k]]){
						cout<<n-3<<'\n';
						f=1;
						for(ll z = 0;z<n;z++){
							if(i==z || j==z || k==z) continue;
							cout<<j+1<<' ';
						}
						cout<<'\n';
						break;
					}
				}
			}
		}
		if(!f) cout<<"0\n";
	}
}