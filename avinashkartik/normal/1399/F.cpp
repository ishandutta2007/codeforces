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

const int   N     =  3e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

int test = 1, n, l[N], r[N], dp[2*N][2*N];
vector <int> adj[2*N];

int mem(int l, int r){
	if(dp[l][r] != -1) return dp[l][r];
	dp[l][r] = 0;
	int f = 0;
	if(l != r) dp[l][r] = mem(l+1,r);
	for(auto it : adj[l]){
		if(it == r) f = 1;
		if(it >= r) continue;
		int val = mem(l,it) + mem(it+1,r);
		dp[l][r] = max(dp[l][r],val);
	}
	dp[l][r] += f;
	return dp[l][r];
}

void solve(){
	vector <int> points;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		points.pb(l[i]);
		points.pb(r[i]);
	}
	sort(all(points)); uniq(points);
	for(int i = 1; i <= n; i++){
		l[i] = lower_bound(all(points), l[i]) - points.begin();
		r[i] = lower_bound(all(points), r[i]) - points.begin();
		adj[l[i]].pb(r[i]);
	}
	for(int i = 0; i <= points.size(); i++)
		for(int j = 0; j <= points.size(); j++)
			dp[i][j] = -1;
	deb1(mem(0,points.size()))
	for(int i = 0; i <= points.size(); i++) adj[i].clear();
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