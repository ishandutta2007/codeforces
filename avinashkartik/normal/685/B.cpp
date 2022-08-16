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

ll n, q, p[N], sz[N], mx[N], c[N];
vector <int> adj[N];

void dfs(int x){
	sz[x] = 1;
	for(auto it : adj[x]){
		dfs(it);
		sz[x] += sz[it];
		if(sz[it] >= sz[mx[x]]) mx[x] = it;
	}
	if(2*sz[mx[x]] <= sz[x]) c[x] = x;
	else {
		int v = c[mx[x]];
		while(2*(max(sz[mx[v]], sz[x] - sz[v])) > sz[x]) v = p[v];
		c[x] = v;
	}
}

void solve(){
	cin >> n >> q;
	for(int i = 2; i <= n; i++){
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	dfs(1);
	for(int i = 1; i <= q; i++){
		int x; cin >> x;
		cout << c[x] << "\n";
	}
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}