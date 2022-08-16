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

ll test=1,n,a[N],m=0,p=0,m2=0;
set <ll> s;

void solve(){
	cin>>n;
	for(int i = 0; i < n; i++){
		ll x;
		cin>>x;
		if(x < m){
			if(x > p || x < m2){
				deb1("no")
				return;
			}
			s.insert(i);
			if(s.find(i-1) != s.end()){
				s.erase(i-1);
				a[i] = a[i-1];
			}
			else a[i] = i;
		}
		if(x > m) m2 = p;
		m = max(m,x);
		p = x;
	}
	if(s.size() > 1)
		deb1("no")
	else if(s.size() == 1){
		deb1("yes")
		deb2(a[*s.begin()],*s.begin()+1)
	}
	else{
		deb1("yes")
		deb2(1,1)
	}
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}