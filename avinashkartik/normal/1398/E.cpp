#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

#define  ordered_set    tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll test = 1, n, l = 0, f = 0, ans = 0, d = 0;
ordered_set s, fs;

ll find_last(){
	int idx = (f == 0)? 1:f; 
	auto it1 = s.find_by_order(idx);
	if(f == 0) return *it1;
	auto it2 = fs.end(); it2--;
	if(*it2 < *it1) return *it2;
	return *it1;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		ll x, y; cin >> x >> y;
		if(x == 0){
			if(y > 0){
				if(l){
					ll x = find_last();
					if(y > x) d += y-x;
				}
				s.insert(y);
				fs.insert(y);
				f++;
				ans += y;
			} else {
				if(l) ll x = find_last();
				s.erase(-y);
				fs.erase(-y);
				f--;
				ans += y;
				if(l and x <= -y){
					d += y;
					if(f){
						x = find_last();
						if(x != INF) d += x;
					}
				}
			}
		} else {
			if(y > 0){
				ll x1 = -1;
				if(l and l+f > 1) x1 = find_last();
				s.insert(y);
				l++;
				if(l+f > 1){
					ll x = find_last();
					if(x == x1) d += y;
					else d += x;
				}
				ans += y;
			} else {
				ll x = find_last();
				d -= x;
				s.erase(-y);
				l--;
				ans += y;
				if(x <= -y){
					d += y;
					if(l+f > 1){
						x = find_last();
						d += max(y,x);
					}
				}
			}
		}
		deb1(ans+d)
	}
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}