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

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll test = 1, n, S, sz[N], sum[2], ct;
multiset <pair<ll,pll>,greater<>> s[2];

struct edge{
	ll to, w, c;
};

vector <edge> adj[N];

void dfs(int x, int p){
	sz[x] = (adj[x].size() == 1);
	for(auto it : adj[x]){
		if(it.to == p) continue;
		dfs(it.to,x);
		sz[x] += sz[it.to];
		ll y = it.w;
		while(y*sz[it.to] > S){
			y /= 2;
			ct += it.c;
		}
		s[it.c%2].insert({(y-y/2)*sz[it.to],{y,sz[it.to]}});
		sum[it.c%2] += y*sz[it.to];
	}
}

int bs(vll v, ll x){
	int l = 0, r = v.size()-1, ans;
	while(l <= r){
		int mid = (l+r)/2;
		if(v[mid] <= x){
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return ans;
}

void solve(){
	ct = 0;
	sum[0] = sum[1] = 0;
	s[0].clear(); s[1].clear();
	cin >> n >> S;
	for(int i = 1; i < n; i++){
		int u, v, w, c; cin >> u >> v >> w >> c;
		adj[u].pb({v,w,c});
		adj[v].pb({u,w,c});
	}
	dfs(1,0);
	vll v;
	v.pb(0);
	while(true){
		if(s[0].size() == 0) break;
		auto it = s[0].begin();
		v.pb(v.back()+(*it).f);
		ll wt = (*it).s.f;
		if(wt == 0) break;
		wt /= 2;
		s[0].erase(s[0].begin());
		s[0].insert({(wt-wt/2)*(*it).s.s,{wt,(*it).s.s}});
	}
	v.pb(INF);
	ll ans = INF;
	sum[1] += sum[0];
	while(true){
		if(s[1].size() == 0) break;
		ll res = (lower_bound(all(v),sum[1]-S)-v.begin());
		if(v[res] != INF) ans = min(ans,ct+res*2);
		auto it = s[1].begin();
		ll wt = (*it).s.f;
		if(wt == 0) break;
		sum[1] -= (*it).f;
		wt /= 2;
		s[1].erase(s[1].begin());
		s[1].insert({(wt-wt/2)*(*it).s.s,{wt,(*it).s.s}});
		ct++;
	}
	ll res = (lower_bound(all(v),sum[1]-S)-v.begin());
	if(v[res] != INF) ans = min(ans,ct+res*2);
	deb1(ans)
	for(int i = 1; i <= n; i++) adj[i].clear();
}

int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}