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
 
const ll   N     =  2e6+5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, adj[45][45], cnt = 0, dp1[N], dp2[N];
vector <pair<int, string>> q[N];
map <string, int> ind;

int ffs(int x){
	for(int i = 0; i < 20; i++){
		if((1<<i)&x) return i+1;
	}
	return 0;
}

void solve(){
	cin>>n>>m;
	for(int i = 0; i < m; i++) for(int j = 0; j < m; j++) adj[i][j] = 0;
	for(int i = 0,j = 0; i < n; i++){
		int x; string s = "";
		cin>>x;
		if(x == 2){
			cin>>s;
			if(ind.find(s) == ind.end()) ind[s] = cnt++;
			q[j].pb({x,s});
		}
		else j++;
	}
	for(int i = 0; i < n; i++){
		set <ll> s;
		for(auto it : q[i]) s.insert(ind[it.s]);
		vll v; for(auto it : s) v.pb(it);
		int sz = v.size();
		for(int i = 0; i < sz; i++) for(int j = 0; j < sz; j++) adj[v[i]][v[j]] = 1;
	}
	ll mid = m/2;
	for(int i = 1; i < (1<<mid); i++){
		int f = 0, ind = ffs(i)-1;
		int x = i-(1<<ind);
		if(dp1[x] == __builtin_popcount(x)){
			for(int k = 0; k < mid; k++){
				if((1<<k)&x)
					if(adj[ind][k] == 1) f = 1;
			}
			if(f == 0){
				dp1[i] = dp1[x]+1;
				continue;
			}
		}
		for(int j = 0; j < mid; j++){
			if((1<<j)&i) dp1[i] = max(dp1[i],dp1[i-(1<<j)]);
		}
	}
	mid = m-mid;
	for(int i = 1; i < (1<<mid); i++){
		int f = 0, ind = ffs(i)-1;
		int x = i-(1<<ind);
		if(dp2[x] == __builtin_popcount(x)){
			for(int k = 0; k < mid; k++){
				if((1<<k)&x)
					if(adj[ind+m/2][k+m/2] == 1) f = 1;
			}
			if(f == 0){
				dp2[i] = dp2[x]+1;
				continue;
			}
		}
		for(int j = 0; j < mid; j++){
			if((1<<j)&i) dp2[i] = max(dp2[i],dp2[i-(1<<j)]);
		}
	}
	ll ans = 1;
	for(int i = 0; i < (1<<mid); i++){
		ll pop = __builtin_popcount(i);
		if(dp2[i] != pop) continue;
		ll msk = 0;
		for(int k = 0; k < m/2; k++){
			ll x = (1<<k), f = 1;
			for(int j = 0; j < mid; j++){
				if((1<<j)&i) 
					if(adj[j+m/2][k] == 1) f = 0;
			}
			msk += x*f;
		}
		ans = max(ans,dp1[msk]+pop);
	}
	deb1(ans);
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