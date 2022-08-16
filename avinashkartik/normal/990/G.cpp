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

const int  N     =  2e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

int test = 1, n, a[N], ct[N][161], ind[N][161], sz[N];
ll ans[N];
vector <int> adj[N];

int bs(int x, int v){
	int l = 0, r = sz[x]-1;
	while(l <= r){
		int mid = (l+r)/2;
		if(ind[x][mid] == v) return mid;
		if(ind[x][mid] > v) r = mid - 1;
		else l = mid + 1;
	}
}

void dfs(int x, int p){
	ct[x][sz[x]-1]++;
	for(auto it : adj[x]){
		if(it == p) continue;
		dfs(it,x);
		for(int i = 0; i < sz[it]; i++){
			int g = __gcd(a[x],ind[it][i]);
			int idx = bs(x,g);
			ct[x][idx] += ct[it][i];
		}
	}
}

void reroot(int x, int p){
	if(p){
		for(int i = 0; i < sz[x]; i++){
			int g = __gcd(a[p],ind[x][i]);
			int idx = bs(p,g);
			ct[p][idx] -= ct[x][i];
		}
		for(int i = 0; i < sz[p]; i++){
			int g = __gcd(a[x],ind[p][i]);
			int idx = bs(x,g);
			ct[x][idx] += ct[p][i];
		}
	}
	for(int i = 0; i < sz[x]; i++) ans[ind[x][i]] += ct[x][i];
	ans[a[x]]++;
	for(auto it : adj[x]){
		if(it == p) continue;
		reroot(it,x);
	}
	if(p){
		for(int i = 0; i < sz[p]; i++){
			int g = __gcd(a[x],ind[p][i]);
			int idx = bs(x,g);
			ct[x][idx] -= ct[p][i];
		}
		for(int i = 0; i < sz[x]; i++){
			int g = __gcd(a[p],ind[x][i]);
			int idx = bs(p,g);
			ct[p][idx] += ct[x][i];
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1; i <= n; i++){
		int no = 0;
		for(int j = 1; j*j <= a[i]; j++){
			if(a[i]%j == 0){
				ind[i][no++] = j;
				if(j*j != a[i]) ind[i][no++] = a[i]/j;
			}
		}
		sz[i] = no;
		sort(ind[i],ind[i]+no);
	}
	dfs(1,0);
	reroot(1,0);
	for(int i = 1; i <= 2e5; i++) if(ans[i]) deb2(i,ans[i]/2)
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