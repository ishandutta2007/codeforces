#include<bits/stdc++.h>

using namespace std;

#define  f              first                 
#define  s              second
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
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test = 1, n, vis[N];
set <ll> adj[N];

pll find(){
	int p = -1, q = -1;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			if(adj[i].size() == 1){
				if(p == -1) p = i;
				else q = i;
				vis[i] = 1;
			}
		}
		if(q != -1) break;
	}
	return {p,q};
}

void solve(){
	cin>>n;
	for(int i = 0; i < n-1; i++){
		int u,v;
		cin>>u>>v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for(int i = 0; i < n/2; i++){
		int x;
		pll p = find();
		cout<<"? "<<p.f<<" "<<p.s<<endl;
		cin>>x;
		if(x == p.f){
			cout<<"! "<<p.f<<endl;
			return;
		}
		if(x == p.s){
			cout<<"! "<<p.s<<endl;
			return;
		}
		adj[*adj[p.f].begin()].erase(p.f);
		adj[*adj[p.s].begin()].erase(p.s);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cout<<"! "<<i<<endl;
			break;
		}
	}
}

int main(){
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}