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

const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, a[N], mx[N], no[N], lft[N];
vector <int> adj[N];

void dfs(int x){
	for(auto it : adj[x]){
		dfs(it);
		no[x] += no[it];
		lft[x] += lft[it];
		mx[x] = max(mx[x], mx[it]);
	}
	for(auto it : adj[x]){
		lft[x] += no[it] * (mx[x] - mx[it]);
	}
	if(adj[x].size() == 0) no[x] = 1;
	ll mn = min(a[x], lft[x]);
	a[x] -= mn;
	lft[x] -= mn;
	mx[x] += ceil((ld)a[x] / no[x]);
	lft[x] += (no[x] - a[x] % no[x]) % no[x];
}

void solve(){
	cin >> n;
	for(int i = 2; i <= n; i++){
		int x; cin >> x;
		adj[x].pb(i);
	}
	for(int i = 1; i <= n; i++) cin >> a[i];
	dfs(1);
	deb1(mx[1])
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}