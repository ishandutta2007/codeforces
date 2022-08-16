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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, p[N], ct, d[N];
vll adj[N], cyc;

void dfs1(int x){
	for(auto it : adj[x]){
		if(it == p[x]) continue;
		if(d[it] != -1 && d[it] < d[x]){
			int st = x;
			while(st != it){
				cyc.pb(st);
				st = p[st];
			}
			cyc.pb(st);
		} else if(d[it] == - 1){
			p[it] = x;
			d[it] = d[x] + 1;
			dfs1(it);
		}
	}
}

void dfs2(int x){
	ct++;
	for(auto it : adj[x]){
		if(p[it] != -1) continue;
		p[it] = x;
		dfs2(it);
	}
}

void solve(){
	cin >> n;
	cyc.clear();
	for(int i = 1; i <= n; i++){
		d[i] = -1;
		adj[i].clear();
	}
	for(int i = 1; i <= n; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	p[1] = d[1] = 0;
	dfs1(1);
	ll ans = n * (n - 1);
	for(int i = 1; i <= n; i++) p[i] = -1;
	for(auto it : cyc) p[it] = 0;
	for(auto it : cyc){
		ct = 0;
		dfs2(it);
		ans += ct * (n - ct);
	}
	deb1(ans / 2)
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}