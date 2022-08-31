#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;             
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,k,a[N],val[N],ct[N];
vll ans[N];

void solve(){
	cin>>n>>k;
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int i = 1; i <= k; i++) cin>>val[i];
	sort(a,a+n);
	for(int i = 0; i < n; i++) ct[a[i]]++;
	for(int i = k-1; i > 0; i--){
		ct[i] += ct[i+1];
	}
	ll t = 0;
	for(int i = 1; i <= k; i++){
		ll x = ceil((ld)ct[i]/val[i]);
		t = max(t,x);
		//deb3(ct[i],val[i],x);
	}
	ll ind = 0;
	for(int i = 0; i < n; i++){
		ans[ind].pb(a[i]);
		ind = (ind+1)%t;
	}
	cout<<t<<endl;
	for(int i = 0; i < t; i++){
		cout<<ans[i].size()<<" ";
		for(auto it : ans[i]) cout<<it<<" ";
		cout<<endl;
	}
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}