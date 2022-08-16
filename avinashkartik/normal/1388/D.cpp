#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
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

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], b[N], sz[N], ans = 0, vis[N], no = 1, ind[N];
vll adj[N], rev[N], g[N];
stack <ll> Stack;

void TSUtil(int v){ 
    vis[v] = 1;
    for(auto it : g[v]) 
        if (!vis[it]) 
            TSUtil(it); 
    Stack.push(v); 
} 

void TS(){ 
    for(int i = 1; i <= n; i++) vis[i] = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            TSUtil(i);
    while(Stack.empty() == 0){ 
        ind[no++] = Stack.top(); 
        Stack.pop(); 
    }
} 

void solve(){
	cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        if(b[i] != -1) adj[i].pb(b[i]), rev[b[i]].pb(i);
    }
    set <pll> s;
    for(int i = 1; i <= n; i++){
    	sz[i] = rev[i].size();
    	s.insert({sz[i],i});
    }
    for(int i = 1; i <= n; i++){
    	auto it = s.begin();
    	ans += a[(*it).s];
    	for(auto to : adj[(*it).s]){
    		s.erase({sz[to],to});
    		sz[to]--;
    		s.insert({sz[to],to});
    		if(a[(*it).s] > 0){
    			a[to] += a[(*it).s];
    			g[(*it).s].pb(to);
    		} else g[to].pb((*it).s);
    	}
    	s.erase(it);
    }
    TS();
    deb1(ans)
    for(int i = 1; i <= n; i++) cout << ind[i] << " ";
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