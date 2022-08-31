#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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

int test=1, n, m, k, ct[N], f[N];
multiset <int> val[N];

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++){
    	int ai,fi;
    	cin>>ai>>fi;
    	ct[ai]++;
    	f[ai] += fi^1;
    }
    for(int i = 1; i <= n; i++){
    	if(ct[i] == 0) continue;
    	val[ct[i]].insert(f[i]);
    }
    ll tot = 0, mn = 0;
    for(int i = n; i >= 0; i--){
    	if(val[i].size() == 0) continue;
    	tot += i;
    	mn += *val[i].begin();
    	val[i].erase(val[i].begin());
    	for(auto it : val[i]){
    		val[i-1].insert(max(it-1,0));
    	}
    }
    deb2(tot,tot-mn)
    for(int i = n; i >= 0; i--){
    	val[i].clear();
    	ct[i] = 0;
    	f[i] = 0;
    }
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}