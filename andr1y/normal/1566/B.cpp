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
		string s;
		cin >> s;
		ll lb = -1;
		ll bc0=0, bc1=0;
		for(auto i : s){
			if(i-'0' == lb) continue;
			if(lb==0) bc0++;
			if(lb==1) bc1++;
			lb=i-'0';
		}
		if(lb==0) bc0++;
		if(lb==1) bc1++;
		cout<<min(bc0, 2ll)<<'\n';
	}
}