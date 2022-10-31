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
		ll a, b;
		cin >> a >> b;
		ll hl = (a+b)/2, hb = a+b-hl;
		vector<ll> res;
		for(ll i = 0;i<=a+b;i++){
			//exactly i not on place
			// assume j, k: j+k = i, j a wins on b, k b wins on a
			// b = h1 - j + k, a = h2 - k + j
			// h1-h2 - 2j + 2k = b-a = h1-h2 - 2i + 4k = b-a
			// 4k = b-a - (h1-h2) + 2i
			if(

				(((b-a - (hl-hb) + 2*i) >= 0) && ((b-a - (hl-hb) + 2*i)%4 == 0) && ((b-a - (hl-hb) + 2*i)/4 <= i) && ((b-a - (hl-hb) + 2*i)/4 <= b) && (i-((b-a - (hl-hb) + 2*i)/4) <= a))  || 

				(((b-a - (hb-hl) + 2*i) >= 0) && ((b-a - (hb-hl) + 2*i)%4 == 0) && ((b-a - (hb-hl) + 2*i)/4 <= i) && ((b-a - (hb-hl) + 2*i)/4 <= b) && (i-((b-a - (hb-hl) + 2*i)/4) <= a))

				) res.push_back(i);
		}
		cout<<res.size()<<'\n';
		for(auto i : res) cout<<i<<' ';
		cout<<'\n';
	}
}