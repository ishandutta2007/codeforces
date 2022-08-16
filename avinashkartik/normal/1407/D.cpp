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

const int  N     =  4e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, a[N], mx[N], mn[N], dp[N];
stack <ll> smx, smn;
vll adj[N];

ll mem(int ind){
	if(ind == n) return 0;
	if(dp[ind] != -1) return dp[ind];
	ll ans = INF;
	for(auto it : adj[ind]){
		ans = min(ans, mem(it) + 1);
	}
	return dp[ind] = ans;
}

void solve(){
	mset(mx, -1);
	mset(mn, -1);
	mset(dp, -1);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	smx.push(n);
	smn.push(n);
	for(int i = n - 1; i >= 1; i--){
		adj[i].pb(i+1);
		if(a[i] > a[i+1]){
			int ind = mx[i+1];
			while(ind != -1 and a[ind] < a[i]){
				adj[i].pb(ind);
				ind = mx[ind];
			}
			if(ind != -1) adj[i].pb(ind);
		} else if(a[i] < a[i+1]){
			int ind = mn[i+1];
			while(ind != -1 and a[ind] > a[i]){
				adj[i].pb(ind);
				ind = mn[ind];
			}
			if(ind != -1) adj[i].pb(ind);
		}
		while(smx.size() and a[smx.top()] <= a[i]) smx.pop();
		if(smx.size() != 0) mx[i] = smx.top();
		smx.push(i);
		while(smn.size() and a[smn.top()] >= a[i]) smn.pop();
		if(smn.size() != 0) mn[i] = smn.top();
		smn.push(i);
	}
	deb1(mem(1));
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