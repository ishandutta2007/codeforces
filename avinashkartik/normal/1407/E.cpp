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

ll n, m, dist[N][2], dp[N];
vll adj[N][2];

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v, w; cin >> u >> v >> w;
		adj[v][w].pb(u);
	}
	for(int i = 1; i < n; i++) dist[i][0] = dist[i][1] = dp[i] = INF;
	dist[n][0] = dist[n][1] = dp[n] = 0;
	queue <int> q;
	q.push(n);
	while(q.size()){
		int x = q.front(); q.pop();
		for(auto it : adj[x][0]){
			if(dist[it][0] != INF) continue;
			dist[it][0] = dp[x] + 1;
			if(dist[it][1] != INF){
				q.push(it);
				dp[it] = dist[it][0];
			}
		}
		for(auto it : adj[x][1]){
			if(dist[it][1] != INF) continue;
			dist[it][1] = dp[x] + 1;
			if(dist[it][0] != INF){
				q.push(it);
				dp[it] = dist[it][1];
			}
		}
	}
	deb1((dp[1] == INF ? -1 : dp[1]));
	for(int i = 1; i <= n ; i++){
		cout << (dist[i][0] > dist[i][1] ? 0 : 1);
	}
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