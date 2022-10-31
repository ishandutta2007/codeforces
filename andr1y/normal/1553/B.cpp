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
		string s, t;
		cin >> s >> t;
		ll n = s.length(), tn = t.length();
		bool can=0;
		for(ll i = 0;i<n;i++){
			for(ll j = i;j<n;j++){
				if(s[j]!=t[j-i]) break;
				bool ok2=1, ok3=(j-i==tn-1);
				for(ll k = j-i+1, u=j-1;u>=0&&k<tn;k++, u--){
					if(s[u]!=t[k]) {ok2=0;break;}
					else if(k==tn-1) ok3=1;
				}
				if(ok2&&ok3) can=1;
			}
		}
		if(can) cout<<"yes\n";
		else cout<<"no\n";
	}
}