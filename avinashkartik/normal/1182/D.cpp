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
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+3;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, ans = -1, okk[N];
vector <int> adj[N];
map <ull, int> hm[N], okm[N];
ull hsh[N];

void dfs(int x, int p){
	hsh[x] = 1;
	for(auto it : adj[x]){
		if(it == p) continue;
		dfs(it, x);
		hsh[x] += hsh[it] * 39;
		okm[x][okk[it]]++;
		hm[x][hsh[it]]++;
	}
	okk[x] = (hm[x].size() <= 1) & (okm[x][0] == 0);
}

void reroot(int x, int p){
	if(p){
		hsh[p] -= hsh[x] * 39;
		hm[p][hsh[x]]--;
		if(hm[p][hsh[x]] == 0) hm[p].erase(hsh[x]);
		okm[p][okk[x]]--;
		if(okm[p][okk[x]] == 0) okm[p].erase(okk[x]);
		okk[p] = (hm[p].size() <= 1) & (okm[p][0] == 0);
		hsh[x] += hsh[p] * 39; 
		hm[x][hsh[p]]++;
		okm[x][okk[p]]++;
		okk[x] = (hm[x].size() <= 1) & (okm[x][0] == 0);
	}
	if(okk[x]) ans = x;
	for(auto it : adj[x]){
		if(it == p) continue;
		reroot(it, x);
	}
	if(p){
		hsh[x] -= hsh[p] * 39; 
		hm[x][hsh[p]]--;
		if(hm[x][hsh[p]] == 0) hm[x].erase(hsh[p]);
		okm[x][okk[p]]--;
		if(okm[x][okk[p]] == 0) okm[x].erase(okk[p]);
		okk[x] = (hm[x].size() <= 1) & (okm[x][0] == 0);
		hsh[p] += hsh[x] * 39;
		hm[p][hsh[x]]++;
		okm[p][okk[x]]++;
		okk[p] = (hm[p].size() <= 1) & (okm[p][0] == 0);
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	reroot(1, 0);
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}