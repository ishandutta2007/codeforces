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
ll cnt[30];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		memset(cnt, 0, sizeof cnt);
		string s;cin>>s;
		for(auto i : s) cnt[i-'a']++;
		ll smc=0;
		ll diff=0, dl=0;
		ll sm1=-1;
		for(ll i = 0;i<26;i++){
			if(cnt[i]){
				smc=i;break;
			}
		}
		for(ll i = 0;i<26;i++){
			if(cnt[i]) diff++;
			if(cnt[i]==1){
				if(sm1==-1) sm1=i;
			}
		}
		if(diff==1){
			cout<<s<<'\n';
			continue;
		}
		if(cnt[smc]>1 && sm1!=-1){
			cout<<char('a'+sm1);
			for(ll i = 0;i<26;i++){
				if(i==sm1) continue;
				for(ll j = 0;j<cnt[i];j++) cout<<char('a'+i);
			}
			cout<<'\n';
			continue;
		}
		if(cnt[smc]<3){
			for(ll i = 0;i<26;i++){
				for(ll j = 0;j<cnt[i];j++) cout<<char('a'+i);
			}
			cout<<'\n';
			continue;
		}
		ll oth = (s.length()-cnt[smc]);
		if(oth+2>=cnt[smc]){
			cout<<char('a'+smc);
			cout<<char('a'+smc);
			ll left = cnt[smc]-2;
			for(ll i = smc+1;i<26;i++){
				for(ll j = 0;j<cnt[i];j++){
					cout<<char('a'+i);
					if(left){
						cout<<char('a'+smc);
						left--;
					}
				}
			}
			cout<<'\n';
			continue;
		}else if(diff>=3){
			ll second=0, third=0;
			for(ll i = smc+1;i<26;i++) if(cnt[i]){second=i;break;}
			for(ll i = second+1;i<26;i++) if(cnt[i]){third=i;break;}
			cout<<char('a'+smc);
			cout<<char('a'+second);
			for(ll i = 1;i<cnt[smc];i++) cout<<char('a'+smc);
			cout<<char('a'+third);
			cnt[second]--;
			cnt[third]--;
			for(ll i = second;i<26;i++){
				for(ll j = 0;j<cnt[i];j++) cout<<char('a'+i);
			}
			cout<<'\n';
			continue;
		}else{
			cout<<char('a'+smc);
			for(ll i = smc+1;i<26;i++){
				for(ll j = 0;j<cnt[i];j++) cout<<char('a'+i);
			}
			for(ll j = 1;j<cnt[smc];j++) cout<<char('a'+smc);
			cout<<'\n';
			continue;
		}
	}
}