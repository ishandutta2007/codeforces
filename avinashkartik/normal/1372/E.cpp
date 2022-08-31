#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
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
 
const ll   N     =  105;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, a[N][N], ct[N], cnt = 1, dp[N][N];
set <pll> adj[N];

ll del(int x, int c){
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		auto it = adj[i].upper_bound({c,INF}); it--;
		int f = 0;
		if(a[i][(*it).f] == 0) a[i][(*it).f] = x, f = 1;
		cnt += f;
	}
	return cnt*cnt;
}

void add(int x, int c){
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		auto it = adj[i].upper_bound({c,INF}); it--;
		int f = 0;
		if(a[i][(*it).f] == x) a[i][(*it).f] = 0, f = 1;
		cnt += f;
	}
}

ll mem(int l, int r){
	if(l > r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	ll ans = 0;
	for(int i = l; i <= r; i++){
		ll tmp = cnt++;
		ll x = del(tmp,i);
		ans = max(ans,mem(l,i-1)+mem(i+1,r)+x);
		add(tmp,i);
	}
	return dp[l][r] = ans;
}

void solve(){
	mset(dp,-1);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		int x,l,r;
		cin>>x;
		for(int j = 1; j <= x; j++){
			cin>>l>>r;
			adj[i].insert({l,r});
		}
	}
	deb1(mem(1,m))
}

int main(){
	fastio;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}