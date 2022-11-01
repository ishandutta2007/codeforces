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
ll fg[11];
ll tres[20];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		string s;
		ll k;
		cin >> s >> k;
		ll n = s.length();
		ll minv=inf;
		for(ll mask=2;mask<1024;mask++){
			if(__builtin_popcount(mask)>k) continue;
			fg[10]=-1;
			for(ll j = 9;j>=0;j--){
				if((1<<j)&mask) fg[j]=j;
				else fg[j]=fg[j+1];
			}
			bool alg=0, bad=0;
			for(ll i=0;i<n;i++){
				ll x = s[i]-'0';
				if(alg){
					tres[i]=fg[0];
				}else{
					if((1<<x)&mask){
						tres[i]=x;
					}else{
						ll u = fg[x];
						if(u==-1){
							bool ff=0;
							for(ll j = i-1;j>=0;j--){
								u = fg[tres[j]+1];
								if(u==-1) tres[j]=fg[0];
								else{tres[j]=u; ff=1; break;}
							}
							if(ff) alg=1, tres[i]=fg[0];
							else {bad=1;break;}
						}else{
							alg=1;
							tres[i]=u;
						}
					}
				}
			}
			if(bad){
				ll xx=fg[1];
				for(ll i = 0;i<n;i++) xx=(xx*10LL+fg[0]);
				minv=min(minv, xx);
			}else{
				ll xx=tres[0];
				for(ll i = 1;i<n;i++) xx=(xx*10LL+tres[i]);
				minv=min(minv, xx);
			}
		}
		cout<<minv<<'\n';;
	}
}