#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1;
ll x1,y11,x2,y2;
ll x3,y3,x4,y4;
ll x5,y5,x6,y6;

void solve(){
	cin>>x1>>y11>>x2>>y2;
	cin>>x3>>y3>>x4>>y4;
	cin>>x5>>y5>>x6>>y6;
 
	if((x3<=x1 && y3<=y11) && (x4>=x2 && y4>=y2)){
		cout<<"NO";
		return;
	}
	if((x5<=x1 && y5<=y11) && (x6>=x2 && y6>=y2)){
		cout<<"NO";
		return;
	}
 
	if( (x3<=x1 && y3<=y11) && (x6>=x2 && y6>=y2) &&(x3<=x1 && y4>=y2) &&(x6>=x2 && y11>=y5) && (x5<=x4) ){
		cout<<"NO";
		return;
	}
	if( (x5<=x1 && y5<=y11) && (x4>=x2 && y4>=y2) &&(x5<=x1 && y6>=y2) &&(x4>=x2 && y11>=y3) && (x3<=x6) ){
		cout<<"NO";
		return;
	}
 
	if( (x5<=x1 && y5<=y11) && (x4>=x2 && y4>=y2) &&(x3<=x1 && y4>=y2) &&(x6>=x2 && y11>=y5) && (y3<=y6) ){
		cout<<"NO";
		return;
	}
	if( (x3<=x1 && y3<=y11) && (x6>=x2 && y6>=y2) &&(x5<=x1 && y6>=y2) &&(x4>=x2 && y11>=y3) && (y5<=y4) ){
		cout<<"NO";
		return;
	}
	cout<<"YES";
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