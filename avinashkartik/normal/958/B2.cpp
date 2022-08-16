
#pragma optimization_level 3   									//Comment optimisations for an interatcive problem - use endl
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
#define all(x)         	(x).begin(),(x).end()
#define mset(x,val)    	memset(x,val,sizeof(x))
#define newl           	cout<<"\n"
#define pb             	push_back
#define mp             	make_pair
#define f 				first
#define s 				second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';
//#define N 1000000007 // prime modulo value 

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const ll   	N   	=  	2*MAX5;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e9 + 7;


// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, x, k, m, y;
string s, t;
multiset<ll,greater<ll>> ans;
ll start = 0;
//ll A[200000000];
vll adj[N];
ll d1, exu, diam, sz[N], par[N];
set<pll,greater<pll>> p;


void dfs(ll v, ll p, ll d){
   if(d>=d1){
       d1=d;
       exu=v;
   }
   par[v] = p;
   sz[v] = 0;
   for(auto to: adj[v]){
       if(to==p) continue;
       //par[to] = v;
       dfs(to,v,d+1);
       sz[v] = max(sz[v],sz[to]);
   }
   sz[v]++;
}
 
// <------------- Implement Functions Here ----------> //

void dfs2(ll x, ll pp ) {
	p.erase({sz[x],x});
	bool seen = true;
	for(auto it : adj[x]) {
		if(it!=pp && sz[it] == sz[x]-1 && seen) {
			seen = false;
			dfs2(it,x);
		}
	}
}	

// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> n;
	for(ll i=1;i<n;i++) {
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,1,0);
	dfs(exu,-1,0);	


	for(ll i=1;i<=n;i++) {
		p.insert({sz[i],i});
	}  

	cout<<1<<" ";
	for(ll i=2;i<=n;i++) {
		if(p.size() == 0) {
			cout<<n<<" ";
		}
		else {
			pll val = *p.begin();
			//cout<<val.f<<" "<<val.s<<"\n";
			start += val.f;
			cout<<start<<" ";
			p.erase(p.begin());
			dfs2(val.s,par[val.s]);
		}
	}
	newl;

}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}