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
 
const ll   N     =  1e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test = 1, n, vis[N], d[N], dis[N];
vll adj[N], v;

void CLEAR(){
	mset(vis,0);
	mset(d,0);
	v.clear();
}

pll query(){
	if(v.size() == 0){
		CLEAR();
		return {0,0};
	}
	int dist,node;
	cout<<"? "<<v.size()<<" ";
	debv(v);
	CLEAR();
	cin>>node>>dist;
	return {node,dist};
}

void dfs(int x, int dist){
	vis[x] = 1;
	for(auto it : adj[x]){
		if(!vis[it]){
			d[it] = d[x]+1;
			dfs(it,dist);
		}
	}
	if(d[x] == dist) v.pb(x);
}

void solve(){
	mset(dis,0);
	cin>>n;
	for(int i = 0; i < n-1; i++){
		int ui,vi;
		cin>>ui>>vi;
		adj[ui].pb(vi);
		adj[vi].pb(ui);
		v.pb(i+1);
	}
	v.pb(n);
	pll q = query();
	int mn = q.s, st = q.f;
	int l = 1, r = mn, ans = mn;
	while(l <= r){
		int mid = (l+r)/2;
		dfs(st,mid);
		q = query();
		dis[mid] = q.f;
		if(q.s == mn){
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	dfs(dis[ans],mn);
	q = query();
	cout<<"! "<<dis[ans]<<" "<<q.f<<endl;
	CLEAR();
	for(int i = 1; i <= n; i++) adj[i].clear();
}

int main(){
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
        string x;
        cin>>x;
        if(x[0] == 'I') break;
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}