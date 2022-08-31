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

const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, a[2005][2005], vis[N];
vector <int> adj[2005], rev[2005];
stack <int> s;

void dfs(int x, int f){
	vis[x] = 1;
	if(!f){
		for(auto it : adj[x]){
			if(!vis[it]) dfs(it, f);
		}
		s.push(x);
	} else {
		for(auto it : rev[x]){
			if(!vis[it]) dfs(it, f);
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j]) {
				adj[i].pb(j);
				rev[j].pb(i);
			}
		}
	}
	for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i, 0);
	int ct = 0;
	mset(vis, 0);
	while(s.size()) {
		int i = s.top(); s.pop();
		if(!vis[i]){
			ct++;
			dfs(i, 1);
		}
	}
	if(ct == 1) deb1("YES")
	else deb1("NO")
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}