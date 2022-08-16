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

ll test=1,n,a[N],b[N],c[N], ans = 0;
vll adj[N];

pll dfs(int x, int par, ll m){
	m = min(m,a[x]);
	int m0 = 0, m1 = 0;
	for(auto it : adj[x]){
		if(it != par){
			pll p = dfs(it,x,m);
			m0 += p.f;
			m1 += p.s;
		}
	}
	if(b[x] != c[x]){
		if(b[x] == 1) m1++;
		else m0++;
	}
	ll match = min(m0,m1);
	ans += 2*m*match;
	return {m0-match,m1-match};
}

void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i = 0; i < n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pll p = dfs(1,0,INF);
    if(p.f or p.s) deb1(-1)
    else deb1(ans)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}