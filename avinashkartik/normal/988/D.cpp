#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  2e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test=1, n, a[N], f = 0;
set <int> s;

void solve(){
	vll res;
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i], s.insert(a[i]);
	for(int i = 1; i <= n; i++){
		ll x = 1;
		for(int j = 0; j <= 30; j++){
			ll y = a[i]-x;
			ll y2 = a[i]+x;
			if(s.count(y) and s.count(y2)){
				deb1(3)
				deb3(a[i],y,y2)
				return;
			}
			if(f == 0){
				if(s.count(y)){
					res.pb(a[i]);
					res.pb(y);
					f = 1;
				}
				if(s.count(y2)){
					res.pb(a[i]);
					res.pb(y2);
					f = 1;
				}
			}
			x *= 2;
		}
	}
	if(res.size()){
		deb1(2)
		deb2(res[0],res[1])
	}
	else{
		deb1(1)
		deb1(a[1])
	}
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}