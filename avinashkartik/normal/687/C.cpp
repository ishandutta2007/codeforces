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

const ll   N     =  505;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, k, a[N], dp[N][N], vis[N];
set <int> adj[N];
set <int> s, ans;

void mem(int i, int sum){
	if(i == 0) ans.insert(sum);
	if(dp[i][sum] != -1) return;
	for(auto it : adj[i]){
		if(vis[it] == 1) continue;
		vis[it] = 1;
		mem(i - a[it], sum + a[it]);
		mem(i - a[it], sum);
		vis[it] = 0;
	}
	dp[i][sum] = 1;
}

void solve(){
	mset(dp, -1);
	cin >> n >> k;
	s.insert(0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		vll t;
		for(auto it : s){
			if(it + a[i] > k) continue;
			t.pb(it + a[i]);
			adj[it + a[i]].insert(i);
		}
		for(auto it : t) s.insert(it);
	}
	mem(k, 0);
	deb1(ans.size())
	debv(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}