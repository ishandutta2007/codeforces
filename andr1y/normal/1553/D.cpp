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
vector<ll> letters[26][2];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		for(ll i =0;i<26;i++) letters[i][0].clear(), letters[i][1].clear();
		string s, t;
		cin >> s >> t;
		ll n=s.length();
		// can remove prefix
		// can remove even block of s
		for(ll i = 0;i<n;i++){
			letters[s[i]-'a'][i&1].push_back(i);
		}
		ll res[2]={-1, -1};
		ll ev=0, od=1;
		for(auto i : t){
			auto it = upper_bound(letters[i-'a'][ev].begin(), letters[i-'a'][ev].end(), res[0]);
			if(it==letters[i-'a'][ev].end()) res[0]=n;
			else res[0]=*it;
			it = upper_bound(letters[i-'a'][od].begin(), letters[i-'a'][od].end(), res[1]);
			if(it==letters[i-'a'][od].end()) res[1]=n;
			else res[1]=*it;
			swap(ev, od);
		}
		if((res[0]<n && (n-res[0])&1)||(res[1]<n && (n-res[1])&1)) cout<<"YES\n";
		else cout<<"NO\n";
	}
}