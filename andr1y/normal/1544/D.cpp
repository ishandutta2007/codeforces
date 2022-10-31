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
ll a[N], b[N], td[N];
vector<ll> wants[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;cin>>n;
		for(ll i = 1;i<=n;i++) wants[i].clear();
		set<ll> un1, un2;
		for(ll i = 1;i<=n;i++){
			cin >> a[i];
			wants[a[i]].push_back(i);
			b[i]=-1;
			un1.insert(i);
			un2.insert(i);
		}
		ll res=0;
		pll last={-1, -1};
		for(ll i = 1;i<=n;i++){
			if(wants[i].size()){
				b[wants[i][0]]=i, res++;
				un1.erase(wants[i][0]);
				un2.erase(i);
				last={wants[i][0], i};
			}
		}
		if(un1.size()==1&&un2.size()==1&&*un1.begin()==*un2.begin()){
			bool fnd=0;
			for(ll i = 1;i<=n;i++){
				if(wants[i].size()>1){
					un1.insert(wants[i][0]);
					b[wants[i][1]]=i;
					un1.erase(wants[i][1]);
					fnd=1;
					break;
				}
			}
			if(!fnd){
				un1.insert(last.x);
				un2.insert(last.y);
				b[last.x]=-1;
				--res;
			}
		}
		set<ll> obs;
		for(ll i = 1;i<=n;i++){
			auto it1 = un1.find(i);
			auto it2 = un2.find(i);
			if(it1!=un1.end()&&it2!=un2.end()){
				un1.erase(it1), un2.erase(it2);
				obs.insert(i);
			}
		}
		last = {-1,-1};
		for(auto i : un1){
			b[i]=*un2.begin();
			un2.erase(un2.begin());
			last = {i, b[i]};
		}
		if(obs.size()==1){
			ll x = *obs.begin();
			b[x] = last.y;
			b[last.x] = x;
		}else{
			ll tc=0;
			for(auto i : obs) td[tc++]=i;
			if(tc&1){
				b[td[0]]=td[1];
				b[td[1]]=td[2];
				b[td[2]]=td[0];
				for(ll i = 4;i<tc;i+=2){
					b[td[i-1]]=td[i];
					b[td[i]]=td[i-1];
				}
			}else{
				for(ll i = 1;i<tc;i+=2){
					b[td[i-1]]=td[i];
					b[td[i]]=td[i-1];
				}
			}
		}
		cout<<res<<'\n';
		for(ll i = 1;i<=n;i++) cout<<b[i]<<' ';
		cout<<'\n';
	}
}