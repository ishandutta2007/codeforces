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
ll cnt[26], ocnt[26];
vector<ll> poss[26];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		memset(cnt, 0, sizeof cnt);
		memset(ocnt, 0, sizeof ocnt);
		for(ll i = 0;i<26;i++) poss[i].clear();
		string s;
		cin >> s;
		ll n = s.length();
		string del;
		for(ll i = n-1;i>=0;i--){
			if(!cnt[s[i]-'a']) del.push_back(s[i]);
			cnt[s[i]-'a']++;
		}
		// {n, n-1, n-2, ...}
		ll dn = del.length();
		bool ok=1;
		for(ll i = 0;i<dn;i++){
			if(cnt[del[i]-'a']%(dn-i)) ok=0;
			ocnt[del[i]-'a']=cnt[del[i]-'a']/(dn-i);
		}
		if(!ok){
			cout<<"-1\n";
			continue;
		}
		ll tp = 0, tn=dn;
		string xs;
		set<ll> nd;
		for(;tp<n&&tn&&ok;tp++){
			ocnt[s[tp]-'a']--;
			if(ocnt[s[tp]-'a']==0) tn--;
			if(ocnt[s[tp]-'a']<0) ok=0;
			xs.push_back(s[tp]);
			nd.insert(tp);
			poss[s[tp]-'a'].push_back(tp);
		}
		if(!ok || tn){
			cout<<"-1\n";
			continue;
		}
		ll xp=0;
		for(ll i = 0;i<dn;i++){
			for(auto j : nd){
				if(s[xp]==xs[j]) xp++;
				else ok=0;
			}
			if(!ok) break;
			for(auto j : poss[del[dn-i-1]-'a']) nd.erase(j);
		}
		if(!ok){
			cout<<"-1\n";
			continue;
		}else{
			reverse(del.begin(), del.end());
			cout<<xs<<' '<<del<<'\n';
		}
	}
}