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
		ll k;
		cin >> k;
		ll blc=1;
		while(blc*blc<k) blc++;
		pll st = {1, blc};
		pll et = {blc, blc};
		ll stc = (blc-1)*(blc-1)+1;
		ll etc = stc+blc-1;
		if(k<=etc){
			cout<<st.x+k-stc<<' '<<st.y<<'\n';
		}else{
			cout<<et.x<<' '<<et.y-(k-etc)<<'\n';
		}
	}
}