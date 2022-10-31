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
		ll h1=0;
		for(auto i : s){
			if(i=='1' || i=='4' || i=='6'||i=='8'||i=='9') h1=i-'0'; 
		}
		if(h1){
			cout<<"1\n"<<h1<<'\n';
		}else{
			string ans="";
			for(ll i = 0;i<n&&ans.empty();i++){
				for(ll j = i+1;j<n&&ans.empty();j++){
					if(
						(s[i]=='2' && s[j]=='3') || 
						(s[i]=='5' && s[j]=='3') || 
						(s[i]=='7' && s[j]=='3') || 
						(s[i]=='3' && s[j]=='7')
						) continue;
					ans.push_back(s[i]);
					ans.push_back(s[j]);
				}
			}
			cout<<"2\n"<<ans<<'\n';
		}
	}
}