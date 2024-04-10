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
		ll n = s.length();
		ll gol1=0, gol2=0, mx1=0, mx2=0, mn1=0, mn2=0;
		ll can1=5, can2=5;
		ll res=10;
		for(ll i =0;i<n&&res==10;i++){
			if(i&1) can2--;
			else can1--;
			if(s[i]=='1'){
				if(i&1) gol2++, mx2++, mn2++;
				else gol1++, mx1++, mn1++;
			}else if(s[i]=='?'){
				if(i&1) mx2++;
				else mx1++;
			}
			if(mx1 > mn2 + can2) res=i+1;
			if(mx2 > mn1 + can1) res=i+1;
		}
		cout<<res<<'\n';
	}
}