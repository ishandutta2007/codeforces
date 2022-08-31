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

const ll   N     =  5e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, r, m = 3e4;
vll val[N];
vpll v;

void solve(){
	int ct = 0;
	cin>>n>>r;
    for(int i = 1; i <= n; i++){
        int u,v;
        cin>>u>>v;
        val[u].pb(v);
    }
    for(int i = 1; i <= m; i++){
    	if(i > r) break;
        sort(val[i].begin(), val[i].end());
    	while(val[i].size() and val[i].back() > 0){
    		r += val[i].back();
    		val[i].pop_back();
    		ct++;
    	}
    }
    for(int i = min(m,r); i >= 1; i--){
    	for(auto it : val[i]){
    		v.pb({it+i,it});
    	}
    }
    sort(v.rbegin(), v.rend());
    for(auto it : v){
    	ll x = it.f-it.s;
    	if(x > r) continue;
    	r += it.s;
    	ct++;
    }
    if(r >= 0 and ct == n) deb1("YES")
    else deb1("NO")
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