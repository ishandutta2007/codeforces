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
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ull>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  3e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, a[N];
vll adj[N];

ll base = 1e9+7;
const ll hMOD = 1e9+123; 
ll pow1[N]; 
ull pow2[N];
 
void init_base(){
    pow1[0] = pow2[0] = 1;
    for(int i = 1; i < N; i++) {
        pow1[i] = pow1[i-1] * base % hMOD;
        pow2[i] = pow2[i-1] * base;
    }
}

void solve(){
	map <unsigned long long, ll> ct;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		adj[v].pb(u);
	}
	vll comp;
	for(int i = 1; i <= n; i++){
		if(adj[i].size() == 0) continue;
		else {
			unsigned long long hsh = 0;
			for(auto it : adj[i]){
				hsh += it * pow2[it];
			}
			ct[hsh] += a[i];
		}
	}
	for(auto it : ct) comp.pb(it.s);
	ll g = 0;
	for(auto it : comp) g = __gcd(g, it);
	deb1(g)
	for(int i = 1; i <= n; i++) adj[i].clear();
}

int main(){
	init_base();
	GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}