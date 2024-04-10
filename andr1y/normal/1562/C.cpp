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


signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		string s;
		cin >> n >> s;
		ll mbf = n/2;
		bool ans=1;
		for(ll i =mbf;i<n&&ans;i++) if(s[i]=='0'){
			ans=0;
			cout<<"1 "<<i+1<<' '<<"1" <<' '<<i<<'\n';
		}
		if(!ans) continue;
		for(ll i = 0;i<mbf&&ans;i++) if(s[i]=='0'){
			ans=0;
			cout<<i+1<<' '<<n<<' '<<i+2<<' '<<n<<'\n';
		}
		if(!ans) continue;
		cout<<"1"<<' '<<mbf<<' '<<"2"<<' '<<mbf+1<<'\n';
	}
}