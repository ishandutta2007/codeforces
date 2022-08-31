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
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());          
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  3e6+8;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, a[N], ans = 0, add[N], rem[N];
vll adj[N];

void solve(){
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
		cin>>a[i];
		if(i != 1){
			ans += abs(a[i]-a[i-1]);
			adj[a[i]].pb(a[i-1]);
			adj[a[i-1]].pb(a[i]);
			int x = min(a[i],a[i-1]), y = max(a[i],a[i-1]);
			if(x != y){
				add[x+1]++;
				rem[y]++;
			}
		}
	}
	cout<<ans<<" ";
	for(int i = 2; i <= n; i++){
		ans += rem[i]-add[i];
		ll res = 0;
		for(auto it : adj[i]){
			if(it == i) continue;
			if(it > i) res += it-1;
			else res += it;
			res -= abs(it-i);
		}
		cout<<ans+res<<" ";
	}
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