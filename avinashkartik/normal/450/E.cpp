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
 
const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, vis[N], spf[N];
vpll ans;

void solve(){
	cin>>n;
	for(int i = 2; i*i < N; i++){
		if(spf[i] == 0){
			for(int j = i*i; j <= N; j += i)
				if(spf[j] == 0) spf[j] = i;
		}
	}
	for(int i = n/2; i > 1; i--){
		if(spf[i] == 0){
			set <ll> s;
			for(int j = i; j <= n; j += i){
				if(vis[j] == 0) s.insert(j), vis[j] = 1;
			}
			if(s.size()&1) s.erase(2*i), vis[2*i] = 0;
			int p = -1;
			for(auto it : s){
				if(p == -1) p = it;
				else{
					ans.pb({it,p});
					p = -1;
				}
			}
		}
	}
	deb1(ans.size())
	for(auto it : ans) deb2(it.f,it.s)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}