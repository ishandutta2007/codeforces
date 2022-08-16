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

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n, m, a[N], vis[N], rec[N], p[N];
vll adj[N], g[N], ans, v[N];
stack <ll> Stack;

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		v[i].pb(i);
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(a != b){
		p[b] = a;
		for(auto it : v[b]) v[a].pb(it);
		v[b].clear();
	}
}

void TSUtil(int v){ 
    vis[v] = 1;
    for(auto it : adj[v]) 
        if (!vis[it]) 
            TSUtil(it); 
    Stack.push(v); 
} 

void TS(){ 
    for(int i = 1; i <= n; i++) vis[i] = 0;
    for(int i = 1; i <= n; i++){
    	if(find(i) != i) continue;
        if(!vis[i])
            TSUtil(i);
    }
    while(Stack.empty() == 0){ 
        for(auto it : v[Stack.top()]) ans.pb(it);
        Stack.pop();
    }
} 

bool CycleUtil(int v){ 
    if(vis[v] == 0){
        vis[v] = 1, rec[v] = 1; 
        for(auto it : adj[v]) { 
            if(!vis[it] && CycleUtil(it)) 
                return 1; 
            else if(rec[it]) 
                return 1; 
        } 
    } 
    rec[v] = 0;
    return 0; 
}

bool Cycle(){
    for(int i = 1; i <= n; i++)
        if(CycleUtil(i))
            return 1;
    return 0;
}

void solve(){
	cin >> n >> m;
	make(n);
	set <int> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i]) adj[a[i]].pb(i), g[a[i]].pb(i);
		else s.insert(i);
	}
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		if(find(u) == find(v)){
			deb1(0)
			return;
		}
		merge(u, v);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < adj[i].size(); j++){
			adj[i][j] = find(adj[i][j]);
			if(adj[i][j] == find(i)) adj[i][j] = n + 1;
		}
		if(find(i) != i){
			for(auto it : adj[i]) adj[find(i)].pb(it);
			adj[i].clear();
		}
	}
	for(int i = 1; i <= n; i++){
		sort(all(adj[i]));
		uniq(adj[i]);
		if(adj[i].size() && adj[i][adj[i].size() - 1] == n + 1) adj[i].pop_back();
		// deb1(i)
		// debv(adj[i])
	}
	if(Cycle()) deb1(0)
	else {
		TS();
		for(auto it : ans){
			if(s.find(it) == s.end()){
				deb1(0)
				return;
			}
			s.erase(it);
			for(auto to : g[it]) s.insert(to);
		}
		debv(ans)
	}
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}